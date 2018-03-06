#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

class Histogram {
	private:
		IplImage m_Image;  // utiliser pour le dessiner l'histogramme avec la méthode opencv
		Mat 	 m_MatImage; // utiliser pour dessiner l'histogramme avec le calcul à la main
		int 	 m_Pixels [256]; // tableau qui compte les occurrences de chaque pixel dans l'image
        float    m_PixelsFrequence [256];// tableau de fréquence d'apparition
	public:
    
        /* @param : image pour laquelle on va calculer l'histogramme */
    
		Histogram (Mat image){
			m_Image    = image;
			m_MatImage = image;
		}
        /* @brief : méthode qui utilise la fonction de open cv
         *          pour calculer l'histogramme
         */
	 	void drawHistogram (){
			CvHistogram* hist;	
			IplImage* imgHistogram = 0;		
			//taille de l'histogramme
			int bins = 256;
			int hsize[] = {bins};
			//valeur max et min de l'histogramme 
			float max_value = 0, min_value = 0;
			
			float value;
			int normalized;
			
			float xranges[] = {0, 256};
			float* ranges[] = {xranges};

			IplImage * planes[] = {&m_Image};
			
			// calcul l'histogramme
			hist = cvCreateHist(1, hsize, CV_HIST_ARRAY, ranges, 1);
			cvCalcHist(planes, hist, 0, NULL);

			cvGetMinMaxHistValue(hist, &min_value, &max_value);
			
			//creer l'image contenant l'histogramme
			imgHistogram = cvCreateImage(cvSize(bins*2, 512), 8, 1);
			cvRectangle(imgHistogram, cvPoint(0, 0), cvPoint(512, 512), CV_RGB(255, 255, 255), -1);
			//dessine l'histogramme
			for (int i = 0; i < bins; ++i) {
				value = cvGetReal1D(hist->bins, i);
				normalized = cvRound(value * 500 / max_value);
				cvLine(imgHistogram, cvPoint(i, 512), cvPoint(i, 512 - normalized), CV_RGB(0, 0, 0));
			}	
	  		cvShowImage("histogram", imgHistogram);
	  		waitKey(0);

		}
        /* @param : nom de la fenetre cree
           @brief : cette méthode permet de recuperer et d'afficher 
									  l'histogramme, de l'image en donné membre. Pour cela
										on va parcourir toute l'image, et compter 
										le nombre d'occurence de chaque valeur de pixels
         */
		void drawHistogram2(string nom){
			Mat newImage(256, 256, CV_8UC1, Scalar(70)); // créer l'image pour l'histogramme
			
			/* initialise le tableau de pixel avec des valeurs à 0*/
			for (int i = 0; i < 256; ++i){
				m_Pixels[i] = 0;
			}			
			
			/* Compte le nombre d'occurrence de chaque valeur de pixels */		
			for (int i = 0; i < m_MatImage.rows; ++i){
				for (int j = 0; j < m_MatImage.cols; ++j){
					++m_Pixels[m_MatImage.at<uchar>(i,j)];
				}
		    }
			/* Calcul la fréquence d'apparition des pixels */
            float nbPixels = 0;
            for (int i = 0; i < 256; ++i)
                nbPixels += m_Pixels[i];
            
            for (int i = 0; i < 256; ++i){
                    m_PixelsFrequence[i] = m_Pixels[i]/nbPixels*100;
                
            }
        	IplImage tmp = newImage;
        	int normalized;
            /* cherche l'élèment maximum */
        	float max = *max_element(m_PixelsFrequence, m_PixelsFrequence+256);
        	/* On normalise et on dessine l'histogramme */
			for (int i = 0; i < 256; ++i) {
                /* calcul des valeurs normalisé pour avoir un
                 bon affiche en fonction de la fréquence,
                 d'apparition du pixel, de la valeur max et de la taille de la fenetre*/
				normalized = m_PixelsFrequence[i] * 250 / max;
				cvLine(&tmp, cvPoint(i, 256), cvPoint(i, 256 - normalized), CV_RGB(0, 0, 0));
				
			}

			imshow(nom, newImage);
	  		//waitKey(0);
		}	
        void setImage(Mat image){
            m_MatImage = image;
        }

		/* @brief : cette méthode va, à partir de l'histogramme calculé
		 *          afficher la nouvelle image en applicant 
		 *          la formule d'expension dynamique 
		 */
		Mat expensionDynamique (){
			/* initialise la nouvelle image */			
			Mat newImage(m_MatImage.rows, m_MatImage.cols, CV_8UC1, Scalar(255));
        	double max ;
			double min ;
            
            // cherche les valeurs min et max de l'image
			minMaxLoc(m_MatImage, &min, &max);
			
			/* On dessine l'image pixel par pixel */
			for (int i = 0; i < m_MatImage.rows; ++i){
				for (int j = 0; j < m_MatImage.cols; ++j){
                    // applique la transformation linéaire
					newImage.at<uchar>(i,j) = (255.0/(max- min))*(m_MatImage.at<uchar>(i, j) - min);
//					cout << (int)newImage.at<uchar>(j,i) << endl ;
        		}
        	}
            return newImage;
		}
};
