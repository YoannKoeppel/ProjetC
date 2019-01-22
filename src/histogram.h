#ifndef HISTOGRAM_H__
#define HISTOGRAM_H__

#include "image.h"

/// \brief initialize the image histogram
/// \param image: the image to modified
int* initHistogram (Image *image);

/// \brief create the histogram based on the image rgb colors
/// \param image: the image to modified
/// \param Histo: the histogram initialized
/// \param Histo: the new histogram generated 
void createHistogram (Image *image, int *Histo, Image *imageHisto);

/// \brief find the max value of the histogram
/// \param Histo: the histogram
int maxHisto (int *Histo);

//void printHistogram(unsigned char *Histo);

#endif