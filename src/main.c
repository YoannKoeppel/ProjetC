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
    newImage(&imageHisto,255,300);

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

    printf("histoaskedblabal" );

    //Execution
    startLUT(argc,argv,&LUT,&image,&imageHisto);

    // save the image (if the directory "pics" already exists)
    saveImagePPM(&image, argv[argc-1]);
    



    if (histoAsked == 1) {
        Image imageHistoOut;
        newImage(&imageHistoOut,255,300);

        int *pointeurHistoOut = NULL;
        pointeurHistoOut = initHistogram(&image);
        createHistogram(&image, pointeurHistoOut, &imageHistoOut);
        saveImagePPM(&imageHistoOut, "histomodified.ppm");
        freeImage(&imageHistoOut);
    }



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
            int *pointeurHisto = NULL;
            pointeurHisto = initHistogram(image);
            createHistogram(image, pointeurHisto, imageHisto);
            histoAsked = 1;
            saveImagePPM(imageHisto, "histoinitial.ppm");
            freeImage(imageHisto);
        }
        
        if (strcmp(argv[i],"ADDLUM") == 0)
        {
            printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));
            addLUM(atoi(argv[i+1]),LUT);
        }

        if (strcmp(argv[i],"DIMLUM") == 0)
        {
            printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));
            dimLUM(atoi(argv[i+1]),LUT);
        }

        if (strcmp(argv[i],"ADDCON") == 0)
        {
            printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));
            addCON(atoi(argv[i+1]),LUT);
        }

        if (strcmp(argv[i],"DIMCON") == 0)
        {
            printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));
            dimCON(atoi(argv[i+1]),LUT);
        }

        if (strcmp(argv[i],"INVERT") == 0)
        {
            printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));
            invert(LUT);
        }

        if (strcmp(argv[i],"SEPIA") == 0)
        {
        	sepiaUsed = 1;
            printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));
            sepia(LUT);
        }


        i++;
    }   
    applyLUT(LUT,image,sepiaUsed);
}
   

