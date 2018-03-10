#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include "compute_histogram.cpp"
using namespace cv;
using namespace std;

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
		/* utilise la méthode ou je parcourt les pixels un par un pour
			 calculer le nombre d'occurence de chaque valeur de pixel */
    hist.drawHistogram2("Histogram 1");

		// calcul l'expension dynamique de l'image 
    Mat imageExpansion = hist.expensionDynamique();
		// modifie l'image dans la classe    
		hist.setImage(imageExpansion);
		// calcul l'histogramme de l'image après la transformation linéaire
    hist.drawHistogram2("Histogram 2");
    imshow("Image en expension dynamique", imageExpansion);
    waitKey(0);
    
    return 0;
}
