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
		int 	 m_Pixels [256]; // tableau qui compte les occurrences de chaque pixel dans l'image
        float    m_PixelsFrequence [256];// tableau de fréquence d'apparition
	public:
    
        /* @param : image pour laquelle on va calculer l'histogramme */
    
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
			
			//create an 8 bits single channel image to hold the histogram
			//paint it white
			imgHistogram = cvCreateImage(cvSize(bins*2, 512), 8, 1);
			cvRectangle(imgHistogram, cvPoint(0, 0), cvPoint(512, 512), CV_RGB(255, 255, 255), -1);
			//draw the histogram
			for (int i = 0; i < bins; ++i) {
				value = cvGetReal1D(hist->bins, i);
				normalized = cvRound(value * 500 / max_value);
				cvLine(imgHistogram, cvPoint(i, 512), cvPoint(i, 512 - normalized), CV_RGB(0, 0, 0));
			}	
	  		cvShowImage("histogram", imgHistogram);
	  		waitKey(0);

		}
        /* @param : nom de la fenetre cree
           @brief : cette
         */
		void drawHistogram2(string nom){
			Mat newImage(256, 256, CV_8UC1, Scalar(70));
			for (int i = 0; i < 256; ++i){
				m_Pixels[i] = 0;
			}			
			
			for (int i = 0; i < m_MatImage.rows; ++i){
				for (int j = 0; j < m_MatImage.cols; ++j){
					++m_Pixels[m_MatImage.at<uchar>(i,j)];
        		}
        	}
            float nbPixels = 0;
            for (int i = 0; i < 256; ++i)
                nbPixels += m_Pixels[i];
            
            for (int i = 0; i < 256; ++i){
                    m_PixelsFrequence[i] = m_Pixels[i]/nbPixels*100;
                
            }
        	IplImage tmp = newImage;
        	int normalized;
        	float max = *max_element(m_PixelsFrequence, m_PixelsFrequence+256);
        	for (int i = 0; i < 256; ++i) {
				normalized = m_PixelsFrequence[i] * 250 / max;

				cvLine(&tmp, cvPoint(i, 256), cvPoint(i, 256 - normalized), CV_RGB(0, 0, 0));
				cout << "Norm" << normalized << endl;
			}

			imshow(nom, newImage);
	  		//waitKey(0);
		}	
        void setImage(Mat image){
            m_MatImage = image;
        }
		Mat expensionDynamique (){
			Mat newImage(m_MatImage.rows, m_MatImage.cols, CV_8UC1, Scalar(255));
        	double max ;
			double min ;
			//cout << "Max : " << max << " Min : " << min << endl;
			minMaxLoc(m_MatImage, &min, &max);
			for (int i = 0; i < m_MatImage.rows; ++i){
				for (int j = 0; j < m_MatImage.cols; ++j){
					newImage.at<uchar>(i,j) = (255.0/(max- min))*(m_MatImage.at<uchar>(i, j) - min);
//					cout << (int)newImage.at<uchar>(j,i) << endl ;
        		}
        	}
            return newImage;
		}
};
