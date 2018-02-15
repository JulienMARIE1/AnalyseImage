//#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

vector <uchar> temporaire;
int tmpY;
void niveau_de_gris(vector<uchar> pixels){

	Mat img(256, pixels.size()+1, CV_8UC1, Scalar(70));
	namedWindow("1_channel", CV_WINDOW_AUTOSIZE);
	IplImage tmp=img;
	for (int i = 0; i < pixels.size()-1; ++i){
		cvLine(&tmp,Point(i, pixels[i]), Point(i + 1, pixels[i+1]),(0x80,0x80,0x80),1);
	}
	imshow("1_channel", img);	
}
void my_mouse_callback( int event, int x, int y, int flags, void* param ) {
    if  ( event == EVENT_LBUTTONDOWN )
    {
        Mat* img = (Mat*) param;
        if (!temporaire.empty()){
            for (int i = 0; i < img->rows; ++i){
                img->at<uchar>(tmpY,i) = temporaire[i];
            }
            temporaire.clear();
        }
        
        for (int i = 0; i < img->rows; ++i){
			cout << i << " ";
            temporaire.push_back(img->at<uchar>(y,i));
            img->at<uchar>(y,i)=50;            
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
    
    cv::Mat image = cv::imread(argv[1], 0); /* Read the file */
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

