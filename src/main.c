#include <stdio.h>
#include <stdlib.h>

#include "image.h"
#include "histogram.h"


int main(int argc, char **argv)
{

    // create an image
    Image image;
    unsigned char *pointeurHisto = NULL;

    // load a ppm file
    if(loadImagePPM(&image,"images/img.ppm") != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // modify the image (red pixel in the center)
   // unsigned int pixel = (image.width*(image.height/2) + (image.width/2))*3;
  //  printf("%d\n",pixel);
    // image.data[pixel + 0] = 255;
    // image.data[pixel + 1] = 0;
    // image.data[pixel + 2] = 0;

    
    //pointeurHisto = initHistogram(&image);
    pointeurHisto = initHistogram(&image);
    createHistogram(&image, pointeurHisto);
    printHistogram(pointeurHisto);

    // save the image (if the directory "pics" already exists)
    saveImagePPM(&image, "images/img_output.ppm");

    // free the image memory
    freeImage(&image);

    return 0;
}
   

