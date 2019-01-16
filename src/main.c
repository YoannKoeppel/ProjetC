#include <stdio.h>
#include <stdlib.h>

#include "image.h"
#include "histogram.h"
#include "lut.h"


int main(int argc, char **argv)
{
    printf("%s\n",argv[0]);
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);

    // create an image
    Image image;
    unsigned char *pointeurHisto = NULL;

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

    //création de l'histogramme
    //pointeurHisto = initHistogram(&image);
    //createHistogram(&image, pointeurHisto);
    //printHistogram(pointeurHisto);

    //Execution
    startLUT(argc,argv,&LUT,&image);

    // save the image (if the directory "pics" already exists)
    saveImagePPM(&image, argv[argc-1]);

    // free the image memory
    freeImage(&image);

    return 0;
}
   

