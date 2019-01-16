#ifndef HISTOGRAM_H__
#define HISTOGRAM_H__

#include "image.h"


unsigned char* initHistogram (Image *image);
void createHistogram (Image *image, unsigned char *Histo);

//void printHistogram(unsigned char *Histo);

#endif