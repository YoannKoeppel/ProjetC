#include <stdio.h>
#include <stdlib.h>

#include "image.h"


int main(int argc, char **argv)
{

    // create an image
    Image image;

    // load a ppm file
    if(loadImagePPM(&image,"images/image.ppm") != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // modify the image (red pixel in the center)
    unsigned int pixel = (image.width*(image.height/2) + (image.width/2))*3;
    printf("%d\n",pixel);
    image.data[pixel + 0] = 255;
    image.data[pixel + 1] = 0;
    image.data[pixel + 2] = 0;

    // création d'un tableau histogramme
    unsigned char *H= malloc((image.width*image.height)*sizeof(unsigned char)); 

    for (int j=0; j < 256; j=j+3)
    {
        int m = ((image.data[j])+(image.data[j+1])+(image.data[j+2]))/3;
        H[m]+=1;
        printf("%d\n", m);
    }


    // save the image (if the directory "pics" already exists)
    saveImagePPM(&image, "images/output.ppm");

    // free the image memory
    freeImage(&image);

    return 0;
}
   

