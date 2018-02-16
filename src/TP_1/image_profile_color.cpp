#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

vector<Vec3b> temporaire; // permet de sauvegarder les pixels rvb la ligne selectionnée
int tmpY; // coordonnée y de la ligne selectionné

/* Permet de dessiner l'echelle de rouge , de la ligne selectionnée*/
void niveau_de_coleur(){

	Mat img(256, temporaire.size()+1, CV_8UC3, Scalar(255,255,255));
	namedWindow("Echelle rvb", CV_WINDOW_AUTOSIZE);
	IplImage tmp=img;
    /* parcourt le tableau de pixel, pour pouvoir relier les points */
	for (int i = 0; i < temporaire.size()-1; ++i){
         // trace une ligne, grise, entre le pixel a l'indice i et le pixel a l'indice i+1, pour le rvb
		cvLine(&tmp,Point(i, (int)temporaire[i][0]), Point(i + 1, (int)temporaire[i+1][0]),Scalar(255,0,0),1);
		cvLine(&tmp,Point(i, (int)temporaire[i][1]), Point(i + 1, (int)temporaire[i+1][1]),Scalar(0,255,0),1);
		cvLine(&tmp,Point(i, (int)temporaire[i][2]), Point(i + 1, (int)temporaire[i+1][2]),Scalar(0,0,255),1);

	}
    flip(img, img, 0); // retourne l'image
	imshow("Echelle rvb", img);
}
/* Fonction qui sera appelé lors d'un clique de souris */
void my_mouse_callback( int event, int x, int y, int flags, void* param ) {
    if  ( event == EVENT_LBUTTONDOWN )// si on détecte un clique
    {
        // recupere l'image
        
        /* si le tableau temporaire de pixel n'est pas vide, donc si on a déjà cliqué une fois,
         on replace les pixels de l'image à leur ancienne place */
        Mat* img = (Mat*) param;
        if (!temporaire.empty()){
            for (int i = 0; i < img->rows; ++i){
                img->at<Vec3b>(tmpY,i)[0] = (int)temporaire[i][0];
                img->at<Vec3b>(tmpY,i)[1] = (int)temporaire[i][1];
                img->at<Vec3b>(tmpY,i)[2] = (int)temporaire[i][2];
            }
            temporaire.clear(); // vide le tableau
        }
        
        /* parcour la ligne en ajoutant tout dabord dans le tableau temporaire
         la valeur des pixels, puis on change la couleur de tout les pixels de la ligne*/
        for (int i = 0; i < img->rows; ++i){
			temporaire.push_back(img->at<Vec3b>(y,i));
            img->at<Vec3b>(y,i)[0]=50;
            img->at<Vec3b>(y,i)[1]=50;
            img->at<Vec3b>(y,i)[2]=200;
        }
        tmpY = y; // sauvegarde de la coordonnée y de la ligne selectionné
			
		niveau_de_coleur();
        imshow("Display window",*img);
        waitKey(1);
    }
}


int main( int argc, char **argv ) {
    if ( argc != 2 ) {
        printf( "Usage: display_image ImageToLoadAndDisplay\n" );
        return -1;
    }
    
    Mat image = imread(argv[1], CV_LOAD_IMAGE_COLOR); /* Read the file */
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

