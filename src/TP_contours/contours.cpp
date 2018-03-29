#include <opencv2/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

Mat src;
string name;
/// Global Variables
const int alpha_slider_max = 100;
int alpha_sliderS;
int alpha_sliderC;
int alpha_sliderC2;
int alpha_sliderL;
Mat img2;
int alphaL;


int contours_detecte (Mat img){
    int count = 0;
    
    for (int i = 0; i < img.rows; ++i){
        for (int j = 0; j < img.cols; ++j){
            if (img.at<uchar>(i,j) == 255){
                ++count;
            }
        }
    }
    return count;
}
int contours_reference (){
    int count = 0;

    for (int i = 0; i < img2.rows; ++i){
        for (int j = 0; j < img2.cols; ++j){
            if (img2.at<uchar>(i,j) < 200){
                ++count;
            }
        }
    }
    cout << " ref " << count;
    return count;
}
bool is_detected (Mat img, int x, int y){
    
    for (int i = x-1; i <= x +1; ++i){
        for (int j = y - 1; j <= y + 1; ++j){
            if (i >= 0 && i < img.rows && j >= 0 && j < img.cols)
                if (img.at<uchar>(i,j) == 0){
                    return true;
                }
        }
    }
    return false;
}

int contours_corrects (Mat img){
    int cpt = 0;
    for (int i = 0; i < img2.rows; ++i){
        for (int j = 0; j < img2.cols; ++j){
            if (img2.at<uchar>(i,j) == 0){
                if (is_detected(img, i, j)){
                    ++cpt;
                }
            }
        }
    }
    return cpt;
}
int faux_positif (Mat img){
    return contours_detecte(img) - contours_corrects(img);
}

int faux_negatif (Mat img){
   
    return contours_reference() - contours_corrects(img);
}

float performance (Mat img){
    return (float)contours_corrects(img) / (float)(contours_corrects(img) + faux_positif(img) + faux_negatif(img));
}

float taux_faux_positif(Mat img){
    return (float)faux_positif(img) / (float)(contours_corrects(img) + faux_positif(img) + faux_negatif(img));
}

float taux_faux_negatif(Mat img){
    return (float)faux_negatif(img) / (float)(contours_corrects(img) + faux_positif(img) + faux_negatif(img));
}



void SobelS(int, void*){
    int alpha = alpha_sliderS ;
    Mat src_gray;

    Mat grad;
    Mat binaire;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    src = imread(name);
    Mat gradXY, result;
    
    // réduit le bruit de l'image
    cv::GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
    // transforme l'image ne nuance de gris
    cvtColor( src, src_gray, CV_BGR2GRAY );
    
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    // scale
    /// Gradient X
    Sobel( src_gray, grad_x, ddepth, 1, 0, 3);
    /// Gradient Y
    Sobel( src_gray, grad_y, ddepth, 0, 1, 3);
    
    double min, max;
    gradXY = grad_x + grad_y;
    minMaxLoc(gradXY, &min, &max);
    min = fabs(min);
    if (min > max) max = min;
    // convertie les résultats en CV_8U
    convertScaleAbs( gradXY, gradXY, 255./max);
    
    result = 0;
    threshold (gradXY, result, alpha, 255, THRESH_BINARY);
    
   // cout << "Contour detecte Sobel: " <<contours_detecte (result) << endl;
   // cout << "Contour correct Sobel: " <<contours_corrects (result) << endl;
    cout << "P : " <<performance (result) << " TFP : " << taux_faux_positif(result) << " TFN : " << taux_faux_negatif(result) << endl;
    imshow("Sobel", result);
    
    cv::waitKey(1);  /* Wait for a keystroke in the window */

}
void LaplaceS (int, void*){
    alphaL = alpha_sliderL;
    Mat src_gray, dst, binaire;
    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    src = imread(name);
    
    int c;

    
    /// Remove noise by blurring with a Gaussian filter
    GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
    
    /// Convert the image to grayscale
    cvtColor( src, src_gray, CV_BGR2GRAY );
    
    
    /// Apply Laplace function
    Mat abs_dst;
    //scale
    Laplacian( src_gray, dst, ddepth, kernel_size, alphaL, delta, BORDER_DEFAULT );
    convertScaleAbs( dst, abs_dst );
    //subtract(Scalar(255,255,255), abs_dst, abs_dst );

    binaire = abs_dst > 128;
    cout << "Contour detecte Laplace: " <<contours_detecte (binaire) << endl;

    /// Show what you got
    imshow("Laplace", binaire);
    
    waitKey(1);
}


void CannyS(int, void*) {
    int alpha = alpha_sliderC ;
    int alpha2 = alpha_sliderC2;
    Mat gray, edge, draw, binaire;
    src = imread(name);

    cvtColor(src, gray, CV_BGR2GRAY);
    
    Canny( gray, edge, alpha, alpha2, 3);
    
    edge.convertTo(draw, CV_8U);
   
    binaire = draw > 128;
    cout << "Contour detecte Canny: " << contours_detecte (binaire) << endl;

    imshow("Canny", binaire);
    
}


int main( int argc, char **argv ) {
    
    alpha_sliderS = 0;
    alpha_sliderC = 0;
    alpha_sliderL = 0;
    
    if ( argc != 2 ) {
       printf( "Usage: display_image ImageToLoadAndDisplay\n" );
       return -1;
    }
    // Create Trackbars
    char TrackbarName[50] = "Sobel";
    char TrackbarName2[50] = "Canny1";
    char TrackbarName3[50] = "Laplace";
    char TrackbarName4[50] = "Canny2";
    img2 = imread("../../img/bearRef.jpg");

  
    name = argv[1];

    namedWindow("Sobel", CV_WINDOW_AUTOSIZE);
    createTrackbar(TrackbarName, "Sobel", &alpha_sliderS, alpha_slider_max, SobelS);
    SobelS(alpha_sliderS, 0);

    namedWindow("Laplace", CV_WINDOW_AUTOSIZE );
    createTrackbar(TrackbarName3, "Laplace", &alpha_sliderL, alpha_slider_max, LaplaceS);
    LaplaceS(alpha_sliderL, 0);
    
    namedWindow("Canny", CV_WINDOW_AUTOSIZE);
    createTrackbar(TrackbarName2, "Canny", &alpha_sliderC, alpha_slider_max, CannyS);
    CannyS(alpha_sliderC, 0);
    createTrackbar(TrackbarName4, "Canny", &alpha_sliderC2, alpha_slider_max, CannyS);
    CannyS(alpha_sliderC2, 0);
    waitKey(0);
    return 0;
}
