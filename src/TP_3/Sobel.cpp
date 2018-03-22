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
const int alpha_slider_max = 500;
int alpha_sliderS;
int alpha_sliderC;
int alpha_sliderC2;
int alpha_sliderL;

int alphaL;


int contours_detecte (Mat inImg){
    int count = countNonZero(inImg);
    return count;
}

bool is_detected (int x, int y){
    
}

int contours_corrects (Mat img){
    int cpt = 0;
    for (int i = 0; i < img.row; ++i){
        for (int j = 0; j < img.col; ++j){
            
        }
    }
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

    // réduit le bruit de l'image
    cv::GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
    // transforme l'image ne nuance de gris
    cvtColor( src, src_gray, CV_BGR2GRAY );
    
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    // scale
    /// Gradient X
    Sobel( src_gray, grad_x, ddepth, 1, 0, 3, alpha, delta, BORDER_DEFAULT );
    /// Gradient Y
    Sobel( src_gray, grad_y, ddepth, 0, 1, 3, alpha, delta, BORDER_DEFAULT );
    
    // convertie les résultats en CV_8U
    convertScaleAbs( grad_x, abs_grad_x );
    convertScaleAbs( grad_y, abs_grad_y );
    
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
    
    
    binaire = grad > 128;
    cout << "Contour detecte Sobel: " <<contours_detecte (binaire) << endl;
    imshow("Sobel", binaire);
    
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
    char TrackbarName[50];
    char TrackbarName2[50];
    char TrackbarName3[50];
    char TrackbarName4[50];
    
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