#include <opencv2/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

Mat src;
/// Global Variables
const int alpha_slider_max = 100;
int alpha_slider;


int Sobel(Mat src){
    Mat src_gray;
    if ( !src.data ) { /* Check for invalid input */
        printf("Could not open or find the image\n") ;
        return -1;
    }
    Mat grad;
    char* window_name = "Sobel Demo - Simple Edge Detector";
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    
    // réduit le bruit de l'image
    cv::GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
    // transforme l'image ne nuance de gris
    cvtColor( src, src_gray, CV_BGR2GRAY );
    
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    // scale
    /// Gradient X
    Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
    /// Gradient Y
    Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
    
    // convertie les résultats en CV_8U
    convertScaleAbs( grad_x, abs_grad_x );
    convertScaleAbs( grad_y, abs_grad_y );
    
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
    
    cv::namedWindow( "Display window"  ); /* Create a window for display */
    
    imshow("Display window", grad);
    
    cv::waitKey(0);  /* Wait for a keystroke in the window */

}
int Laplace (Mat src){
    Mat src_gray, dst;
    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    char* window_name = "Laplace Demo";
    
    int c;
    if( !src.data )
    { return -1; }
    
    /// Remove noise by blurring with a Gaussian filter
    GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
    
    /// Convert the image to grayscale
    cvtColor( src, src_gray, CV_BGR2GRAY );
    
    /// Create window
    namedWindow( window_name, CV_WINDOW_AUTOSIZE );
    
    /// Apply Laplace function
    Mat abs_dst;
    //scale
    Laplacian( src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( dst, abs_dst );
    
    /// Show what you got
    imshow( window_name, abs_dst );
    
    waitKey(0);
}

void CannyS(int, void*) {
    alpha = alpha_slider ;
    cout << alpha;
    Mat gray, edge, draw;
    cvtColor(src, gray, CV_BGR2GRAY);
    
    Canny( gray, edge, alpha, 150, 3);
    
    edge.convertTo(draw, CV_8U);
   
    imshow("image", draw);
}



int main( int argc, char **argv ) {
    
    alpha_slider = 0;
    if ( argc != 2 ) {
       printf( "Usage: display_image ImageToLoadAndDisplay\n" );
       return -1;
    }
    // Create Trackbars
    char TrackbarName[50];
    // sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );

    src = imread(argv[1]);
   // Sobel(src);
    //Laplace(src);
    namedWindow("image", CV_WINDOW_AUTOSIZE);

    createTrackbar( TrackbarName, "image", &alpha_slider, alpha_slider_max, CannyS);
    CannyS(alpha_slider, 0);
    waitKey(0);
    return 0;
}
