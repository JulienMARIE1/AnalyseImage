#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;


class Histogram {
	private:
		IplImage m_Image;
		Mat 	 m_MatImage;
		int 	 m_Pixels [256];

	public:
		Histogram (Mat image){
			m_Image    = image;
			m_MatImage = image;
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
				value = cvGetReal1D(hist->bins, i);
				normalized = cvRound(value * 200 / max_value);
				cvLine(imgHistogram, cvPoint(i*2, 200), cvPoint(i*2, 200 - normalized), CV_RGB(0, 0, 0));
				printf("%d\n", normalized);
			}	
	  		cvShowImage("histogram", imgHistogram);
	  		waitKey(0);

		}
	
		void drawHistogram2(){
			Mat newImage(512, 512, CV_8UC1, Scalar(70));
			for (int i = 0; i < 256; ++i){
				m_Pixels[i] = 0;
			}			
			
			for (int i = 0; i < m_MatImage.rows; ++i){
				for (int j = 0; j < m_MatImage.cols; ++j){
					++m_Pixels[m_MatImage.at<uchar>(j,i)];            
        		}
        	}
        	IplImage tmp = newImage;
        	int normalized;
        	int max = *max_element(m_Pixels, m_Pixels+256);
        	for (int i = 0; i < 256; ++i) {
				normalized = cvRound(m_Pixels[i] * 500 / max);

				cvLine(&tmp, cvPoint(i*2, 512), cvPoint(i*2, 512 - normalized), CV_RGB(0, 0, 0));
//				cout << normalized << endl;
			}

			imshow("Mon Histogram", newImage);
	  		//waitKey(0);
		}	
		
		void expensionDynamique (){
			Mat newImage(m_MatImage.rows, m_MatImage.cols, CV_8UC1, Scalar(255));
        	double max = *max_element(m_Pixels, m_Pixels+256);
			double min = *min_element(m_Pixels, m_Pixels+256);
			//cout << "Max : " << max << " Min : " << min << endl;
			minMaxLoc(m_MatImage, &min, &max);
			for (int i = 0; i < m_MatImage.rows; ++i){
				for (int j = 0; j < m_MatImage.cols; ++j){
					newImage.at<uchar>(j,i) = (255.0/(max- min))*(m_MatImage.at<uchar>(j,i) - min);
					cout << (int)newImage.at<uchar>(j,i) << endl ;
        		}
        	}
			imshow("Image en expension dynamique", newImage);
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
//	hist.drawHistogram();	    
	hist.drawHistogram2();
	hist.expensionDynamique();
    return 0;
}

