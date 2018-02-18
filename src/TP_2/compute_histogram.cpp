#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;


class Histogram {
	IplImage m_Image;
	
	public:
		Histogram (Mat image){
			m_Image = image;
		}
	
	 	void drawHistogram (){
			CvHistogram* hist;	
			IplImage* imgHistogram = 0;		
			//size of the histogram -1D histogram
			int bins = 256;
			int hsize[] = {bins};
			//max and min value of the histogram
			float max_value = 0, min_value = 0;
			//value and normalized value
			float value;
			int normalized;
			//ranges - grayscale 0 to 256
			float xranges[] = {0, 256};
			float* ranges[] = {xranges};

			//planes to obtain the histogram, in this case just one
			IplImage * planes[] = {&m_Image};
			//get the histogram and some info about it
			hist = cvCreateHist(1, hsize, CV_HIST_ARRAY, ranges, 1);
			cvCalcHist(planes, hist, 0, NULL);

			cvGetMinMaxHistValue(hist, &min_value, &max_value);

			printf("min: %f, max: %f\n", min_value, max_value);
			
			
			//create an 8 bits single channel image to hold the histogram
			//paint it white
			imgHistogram = cvCreateImage(cvSize(bins*2, 200), 8, 1);
			cvRectangle(imgHistogram, cvPoint(0, 0), cvPoint(512, 200), CV_RGB(255, 255, 255), -1);
			//draw the histogram
			for (int i = 0; i < bins; ++i) {
				value = cvGetReal1D(hist->bins, i*2);
				normalized = cvRound(value * 200 / max_value);
				cvLine(imgHistogram, cvPoint(i*2, 200), cvPoint(i*2, 200 - normalized), CV_RGB(0, 0, 0));
				printf("%d\n", normalized);
			}	
	  		cvShowImage("histogram", imgHistogram);
	  		waitKey(0);

		}
	
	
};

int main( int argc, char **argv ) {
    if ( argc != 2 ) {
        printf( "Usage: display_image ImageToLoadAndDisplay\n" );
        return -1;
    }
    
    Mat image = imread(argv[1], 0); /* Read the file */
    if ( !image.data ) { /* Check for invalid input */
        printf("Could not open or find the image\n") ;
        return -1;
    }
    
    namedWindow( "Display window"  ); /* Create a window for display */
    imshow("Display window",image);
    

	Histogram hist(image);
	hist.drawHistogram();	    
    return 0;
}

