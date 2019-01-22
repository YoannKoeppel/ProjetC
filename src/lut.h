#ifndef LUT_H__
#define LUT_H__

#include "image.h"

/// \brief structure that contains an image
typedef struct LUT{
   int R[256];
   int V[256];
   int B[256];
}LUT;

/// \brief add luminosity to the image
/// \param value: value given by user (ex ADDLUM 20)
/// \param LUT: array of the rgb image
void addLUM(int value, LUT *LUT);

/// \brief remove luminosity to the image
/// \param value: value given by user (ex ADDLUM 20)
/// \param LUT: array of the rgb image
void dimLUM(int value, LUT *LUT);

/// \brief add contrast to the image
/// \param value: value given by user (ex ADDLUM 20)
/// \param LUT: array of the rgb image
void addCON(int value, LUT *LUT);

/// \brief remove contrast to the image
/// \param value: value given by user (ex ADDLUM 20)
/// \param LUT: array of the rgb image
void dimCON(int value, LUT *LUT);

/// \brief invert the image color
/// \param LUT: array of the rgb image
void invert(LUT *LUT);

/// \brief apply a sepia effect to the image
/// \param LUT: array of the rgb image
void sepia(LUT *LUT);

/// \brief apply all the filters to the image
/// \param LUT: array of the rgb image
/// \param image: the image to modified
/// \param sepiaUsed: global variable to see if sepia is asked
void applyLUT(LUT *LUT, Image *image, int sepiaUsed);


#endif