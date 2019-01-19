#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"
#include "histogram.h"
#include "lut.h"

int sepiaUsed = 0;
int histoAsked = 0;

// prototype fonction LUT
void startLUT(int argc,char **argv,LUT *LUT,Image *image, Image *imageHisto) ;

int main(int argc, char **argv)
{
    printf("%s\n",argv[0]);
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);

    // create an image
    Image image;

    // create an histogram image
    Image imageHisto;

    // load a ppm file
    if(loadImagePPM(&image,argv[1]) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    
    // stocke la taille de l'image
    image.taille = (image.width*image.height)*3;

    // création de LUT
    LUT LUT;

    //initialisation des LUT RVB
    for (int i = 0; i < 256; i++)
    {
        LUT.R[i]=i;
        LUT.V[i]=i;
        LUT.B[i]=i;
    }

    //Execution
    startLUT(argc,argv,&LUT,&image,&imageHisto);

    // save the image (if the directory "pics" already exists)
    saveImagePPM(&image, argv[argc-1]);
     printf("---- NEW IMAGE saved as \"%s\"\n", argv[argc-1]);
    
    // free the image memory
    freeImage(&image);

    return 0;
}


//FONCTION qui appelle les filtres en fonction des commandes
void startLUT(int argc,char **argv,LUT *LUT,Image *image, Image *imageHisto) {
    int i=2;
    while (i!= argc-2){

        if (strcmp(argv[i],"-histo") == 0)
        {
                
            newImage(imageHisto,255,300);
            int *pointeurHisto = NULL;
            pointeurHisto = initHistogram(image);
            createHistogram(image, pointeurHisto, imageHisto);
            saveImagePPM(imageHisto, "images/histoInitial.ppm");
            printf("---- INITIAL HISTOGRAM saved as \"images/histoInitial.ppm\"\n");
            freeImage(imageHisto);
            histoAsked = 1;
        }
        
        if (strcmp(argv[i],"ADDLUM") == 0)
        {
            addLUM(atoi(argv[i+1]),LUT);
            printf("---- ADDLUM filter applicated\n");
        }

        if (strcmp(argv[i],"DIMLUM") == 0)
        {
            dimLUM(atoi(argv[i+1]),LUT);
            printf("---- DIMLUM filter applicated\n");
        }

        if (strcmp(argv[i],"ADDCON") == 0)
        {
            addCON(atoi(argv[i+1]),LUT);
            printf("---- ADDCON filter applicated\n");
        }

        if (strcmp(argv[i],"DIMCON") == 0)
        {
            dimCON(atoi(argv[i+1]),LUT);
            printf("---- DIMCON filter applicated\n");
        }

        if (strcmp(argv[i],"INVERT") == 0)
        {
            invert(LUT);
            printf("---- INVERT filter applicated\n"); 
        }

        if (strcmp(argv[i],"SEPIA") == 0)
        {
        	sepiaUsed = 1;
            sepia(LUT);
            printf("---- SEPIA filter applicated\n");
        }

        i++;
    }   
    applyLUT(LUT,image,sepiaUsed);

    if (histoAsked ==1 )
    {
            Image imageHistoOut;
            newImage(&imageHistoOut,255,300);
            int *pointeurHistoOut = NULL;
            pointeurHistoOut = initHistogram(image);
            createHistogram(image, pointeurHistoOut, &imageHistoOut);
            saveImagePPM(&imageHistoOut, "images/histoNew.ppm");
            printf("---- NEW HISTOGRAM saved as \"images/histoNew.ppm\"\n");
            freeImage(&imageHistoOut);
    }
}
   

