#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lut.h"



void addLum(int value, LUT *LUT) {
	for (int i = 0; i < 256; i++)
	{
		LUT->R[i]=i+value;
		LUT->V[i]=i+value;
		LUT->B[i]=i+value;
	}
}

void applyLUT(LUT LUT, Image *image){
	for (int i = 0; i < 256; i++)
	{
		if(LUT.R[i] < 255)
		{
			if(LUT.R[i] < 0)
			{
				LUT.R[i] = 0;
			}
		}
		else {
			LUT.V[i] = 255;
		}

		if(LUT.V[i] < 255)
		{
			if(LUT.V[i] < 0)
			{
				LUT.V[i] = 0;
			}
		}
		else {
			LUT.V[i] = 255;
		}

		if(LUT.B[i] < 255)
		{
			if(LUT.B[i] < 0)
			{
				LUT.B[i] = 0;
			}
		}
		else {
			LUT.B[i] = 255;
		}
	}

 	for (int j=0; j < image->taille; j=j+3)
 	{
        image->data[j] = LUT.R[image->data[j]];
		image->data[j+1] = LUT.V[image->data[j+1]];
		image->data[j+2] = LUT.B[image->data[j+2]];        
        
    }



}


void startLUT(int argc,char **argv,LUT *LUT) {

	int i=2;
    while (i!= argc-2){
    	printf("coucou\n");
        if (strcmp(argv[i],"ADDLUM") == 0)
        {
        	printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));

            addLum(atoi(argv[i+1]),LUT);
        }
        i = i+2;
    }


}

