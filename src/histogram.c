#include <stdio.h>
#include <stdlib.h>

#include "histogram.h"
#include "image.h"

// création d'un tableau histogramme
int* initHistogram (Image *image){
    int *Histo= malloc((image->width*image->height)*sizeof(int)); 
    for (int i=0; i <= 255; i++)
    {
        Histo[i]=0;
    }
    return (Histo);
}    



void createHistogram (Image *image, int *Histo, Image *imageHisto){
    for (int j=0; j < image->taille; j=j+3)
    {
        int m = ((image->data[j])+(image->data[j+1])+(image->data[j+2]))/3;
        Histo[m]+=1;
    }

    // Affiche les valeurs de l'histogramme
    // for (int i = 0; i <= 255; ++i)
    // {
    //     printf("%d : %d\n",i, Histo[i]);

    // }

    float unitHeight = 255.0 / maxHisto(Histo);

     for (int y = 0; y <= maxHisto(Histo); ++y)
    {
        for (int x = 0; x < 256; ++x)
        {
            if (y>imageHisto->height-Histo[x]*unitHeight)
            {
                imageHisto->data[255*3*y+3*x+0]=255;
                imageHisto->data[255*3*y+3*x+1]=255;
                imageHisto->data[255*3*y+3*x+2]=255;
            }
            else 
            {
                imageHisto->data[255*3*y+3*x+0]=0;
                imageHisto->data[255*3*y+3*x+1]=0;
                imageHisto->data[255*3*y+3*x+2]=0;
            }
        }
   
    }

}

int maxHisto (int *Histo)
{
    int maxHistog = 0;
    for (int i = 0; i < 255; ++i)
    {
        if (maxHistog < Histo[i]) {
            maxHistog = Histo[i];
        }
    }
    return maxHistog;
}













// int* initHistogram (Image *image){

//      int *Histo= malloc((image->width*image->height)*sizeof(int)); 
//      Histo[]=NULL;
//      return (Histo);
// }    



// void createHistogram (Image *image, int *Histo){

//     int taille = (image->width*image->height)*3;
    

//     for (int j=0; j < taille; j=j+3)
//     {
//         int m = ((image->data[j])+(image->data[j+1])+(image->data[j+2]))/3;
//         Histo[m]+=1;
//     }

//     for (int i = 0; i <= 255; ++i)
//     {
//         printf("%d : %d\n",i, Histo[i]);
//     }
// }

// void printHistogram(int *Histo){
//     for (int i = 0; i <= 255; ++i)
//     {
//         printf("%d : %d\n",i, Histo[i]);
//     }
// }


























