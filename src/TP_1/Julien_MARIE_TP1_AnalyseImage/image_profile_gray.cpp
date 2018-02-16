#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;


vector <uchar> temporaire; // permet de sauvegarder les pixels la ligne selectionnée
int tmpY; // coordonnée y de la ligne selectionné


/* Permet de dessiner l'echelle de gris, de la ligne selectionnée*/
void niveau_de_gris(){
    
	Mat img(256, temporaire.size()+1, CV_8UC1, Scalar(70));
	namedWindow("Echelle de gris", CV_WINDOW_AUTOSIZE);
	IplImage tmp = img;
    /* parcourt le tableau de pixel, pour pouvoir relier les points */
	for (int i = 0; i < temporaire.size()-1; ++i){
		
        // trace une ligne, grise, entre le pixel a l'indice i et le pixel a l'indice i+1
        cvLine(&tmp,Point(i, temporaire[i]), Point(i + 1, temporaire[i+1]),(150),1);
        
	}
    flip(img, img, 0); // retourne l'image
	imshow("Echelle de gris", img);
}

/* Fonction qui sera appelé lors d'un clique de souris */
void my_mouse_callback( int event, int x, int y, int flags, void* param ) {
    if  ( event == EVENT_LBUTTONDOWN ) // si on détecte un clique
    {
        Mat* img = (Mat*) param; // recupere l'image
        
        /* si le tableau temporaire de pixel n'est pas vide, donc si on a déjà cliqué une fois,
           on replace les pixels de l'image à leur ancienne place */
        if (!temporaire.empty()){
            for (int i = 0; i < img->rows; ++i){
                img->at<uchar>(tmpY,i) = temporaire[i];
            }
            temporaire.clear(); // vide le tableau
        }
        /* parcour la ligne en ajoutant tout dabord dans le tableau temporaire
           la valeur des pixels, puis on change la couleur de tout les pixels de la ligne*/
        for (int i = 0; i < img->rows; ++i){
			temporaire.push_back(img->at<uchar>(y,i));
            img->at<uchar>(y,i)=50;            
        }
        tmpY = y; // sauvegarde de la coordonnée y de la ligne selectionné
			
		niveau_de_gris();
        imshow("Display window",*img);
        waitKey(1);
    }
}


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
    
    setMouseCallback( "Display window", my_mouse_callback, &image );
    
    imshow("Display window",image);
    
    waitKey(0);  /* Wait for a keystroke in the window */
    return 0;
}

