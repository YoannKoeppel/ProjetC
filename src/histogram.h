#ifndef HISTOGRAM_H__
#define HISTOGRAM_H__


#include "image.h"

int initHistogram (Image image);

void createHistogram (Image image, int* Histo[]);

void printHistogram(Image image, int* Histo[]);


#endif