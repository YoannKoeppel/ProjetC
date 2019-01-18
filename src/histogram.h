#ifndef HISTOGRAM_H__
#define HISTOGRAM_H__

#include "image.h"


int* initHistogram (Image *image);
void createHistogram (Image *image, int *Histo, Image *imageHisto);
int maxHisto (int *Histo);

//void printHistogram(unsigned char *Histo);

#endif