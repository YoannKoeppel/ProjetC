#ifndef LUT_H__
#define LUT_H__

#include "image.h"

typedef struct LUT{
   int R[256];
   int V[256];
   int B[256];
}LUT;

void addLUM(int value, LUT *LUT);
void dimLUM(int value, LUT *LUT);
void addCON(int value, LUT *LUT);
void dimCON(int value, LUT *LUT);
void invert(LUT *LUT);
void sepia(LUT *LUT);

void applyLUT(LUT *LUT, Image *image);
void startLUT(int argc,char **argv,LUT *LUT,Image *image) ;

#endif