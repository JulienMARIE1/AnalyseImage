//#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

vector<cv::Vec3b> temporaire;
int tmpY;
void niveau_de_gris(vector<cv::Vec3b> pixels){

	Mat img(256, pixels.size()+1, CV_8UC3, Scalar(255,255,255));
	namedWindow("1_channel", CV_WINDOW_AUTOSIZE);
	IplImage tmp=img;
	for (int i = 0; i < pixels.size()-1; ++i){
		cvLine(&tmp,Point(i, (int)pixels[i][0]), Point(i + 1, (int)pixels[i+1][0]),Scalar(0,0,255),1);
		cvLine(&tmp,Point(i, (int)pixels[i][1]), Point(i + 1, (int)pixels[i+1][1]),Scalar(0,255,0),1);
		cvLine(&tmp,Point(i, (int)pixels[i][2]), Point(i + 1, (int)pixels[i+1][2]),Scalar(255,0,0),1);

	}
	imshow("1_channel", img);	
}
void my_mouse_callback( int event, int x, int y, int flags, void* param ) {
    if  ( event == EVENT_LBUTTONDOWN )
    {
        Mat* img = (Mat*) param;
        if (!temporaire.empty()){
            for (int i = 0; i < img->rows; ++i){
                img->at<cv::Vec3b>(tmpY,i)[0] = (int)temporaire[i][0];
                img->at<cv::Vec3b>(tmpY,i)[1] = (int)temporaire[i][1];
                img->at<cv::Vec3b>(tmpY,i)[2] = (int)temporaire[i][2];
            }
            temporaire.clear();
        }
        
        for (int i = 0; i < img->rows; ++i){
			temporaire.push_back(img->at<cv::Vec3b>(y,i));
            img->at<cv::Vec3b>(y,i)[0]=50;
            img->at<cv::Vec3b>(y,i)[1]=50;
            img->at<cv::Vec3b>(y,i)[2]=200;
        }
        tmpY = y;
			
		niveau_de_gris(temporaire);
        imshow("Display window",*img);
        cv::waitKey(1);
    }
}


int main( int argc, char **argv ) {
    if ( argc != 2 ) {
        printf( "Usage: display_image ImageToLoadAndDisplay\n" );
        return -1;
    }
    
    cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR); /* Read the file */
    if ( !image.data ) { /* Check for invalid input */
        printf("Could not open or find the image\n") ;
        return -1;
    }
    
    cv::namedWindow( "Display window"  ); /* Create a window for display */
    
    setMouseCallback( "Display window", my_mouse_callback, &image );
    
    imshow("Display window",image);
    
    cv::waitKey(0);  /* Wait for a keystroke in the window */
    return 0;
}

