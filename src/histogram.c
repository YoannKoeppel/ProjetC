#include <stdio.h>
#include <stdlib.h>

#include "histogram.h"

// création d'un tableau histogramme
unsigned char* initHistogram (Image *image){

     unsigned char *Histo= malloc((image->width*image->height)*sizeof(unsigned char)); 

     return (Histo);
}    

void createHistogram (Image *image, unsigned char *Histo){

    int taille = image->width*image->height*3;
    
    for (int j=0; j < taille; j=j+3)
    {
        int m = ((image->data[j])+(image->data[j+1])+(image->data[j+2]))/3;
        Histo[m]+=1;
    }
}

void printHistogram(unsigned char *Histo){
    for (int i = 0; i <= 255; ++i)
    {
        printf("%d : %hhu\n",i, Histo[i]);
    }
}


























