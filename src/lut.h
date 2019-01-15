#ifndef LUT_H__
#define LUT_H__

#include "image.h"

typedef struct LUT{
  unsigned char R[256];
  unsigned char V[256];
  unsigned char B[256];
}LUT;




void addLum(int value, LUT *LUT) ;
void applyLUT(LUT LUT, Image *image);

void startLUT(int argc,char **argv,LUT *LUT) ;






#endif