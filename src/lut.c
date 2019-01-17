#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "lut.h"

//FONCTION ADDLUM
void addLUM(int value, LUT *LUT) {
	for (int i = 0; i < 256; i++)
	{
		LUT->R[i]+=value;
		LUT->V[i]+=value;
		LUT->B[i]+=value;
	}
}

//FONCTION DIMLUM
void dimLUM(int value, LUT *LUT) {
	for (int i = 0; i < 256; i++)
	{
		LUT->R[i]-=value;
		LUT->V[i]-=value;
		LUT->B[i]-=value;
	}
}

//FONCTION ADDCON
void addCON(int value, LUT *LUT) {

	float varFormule = 0;
	float facteur = 0;

	for (int i = 0; i < 256; i++)
	{
		//ROUGES
		varFormule = (LUT->R[i])*0.0039;
		facteur = 0.5*(sin(M_PI*varFormule+3*M_PI/2)+1);
		
		if (facteur>=0.5)
		{
			facteur=facteur*(1+(float)value/100);
		}
		else {
			facteur = facteur*(1-(float)value/100);
		}
		LUT->R[i]=(int)((float)(LUT->R[i])*facteur);

		//VERTS
		varFormule = (LUT->V[i])*0.0039;
		facteur = 0.5*(sin(M_PI*varFormule+3*M_PI/2)+1);
		
		if (facteur>=0.5)
		{
			facteur=facteur*(1+(float)value/100);
		}
		else {
			facteur = facteur*(1-(float)value/100);
		}
		LUT->V[i]=(int)((float)(LUT->V[i])*facteur);

		//BLEUS
		varFormule = (LUT->B[i])*0.0039;
		facteur = 0.5*(sin(M_PI*varFormule+3*M_PI/2)+1);
		
		if (facteur>=0.5)
		{
			facteur=facteur*(1+(float)value/100);
		}
		else {
			facteur = facteur*(1-(float)value/100);
		}
		LUT->B[i]=(int)((float)(LUT->B[i])*facteur);

	}
}

//FONCTION DIMCON
void dimCON(int value, LUT *LUT) {
	float facteur = ((259.0*(255.0-(float)value))/(255.0*(259.0 + (float)value)));
	for (int i = 0; i < 256; i++)
	{
		LUT->R[i]=(int)(facteur*(((float)(LUT->R[i]))-128.0)+128.0);
		LUT->V[i]=(int)(facteur*(((float)(LUT->V[i]))-128.0)+128.0);
		LUT->B[i]=(int)(facteur*(((float)(LUT->B[i]))-128.0)+128.0);		
	}
}

//FONCTION INVERT
void invert(LUT *LUT) {
	for (int i = 0; i < 256; i++)
	{
		LUT->R[i]=255-(LUT->R[i]);
		LUT->V[i]=255-(LUT->V[i]);
		LUT->B[i]=255-(LUT->B[i]);
	}
}

//FONCTION SEPIA
void sepia(LUT *LUT) {
	for (int i = 0; i < 256; i++)
	{
		float sepiaR = ((float)(LUT->R[i])*0.393) + ((float)(LUT->V[i])*0.769) + ((float)(LUT->B[i])*0.189);   
		float sepiaV = ((float)(LUT->R[i])*0.349) + ((float)(LUT->V[i])*0.686) + ((float)(LUT->B[i])*0.168); 
		float sepiaB = ((float)(LUT->R[i])*0.272) + ((float)(LUT->V[i])*0.534) + ((float)(LUT->B[i])*0.131);

		LUT->R[i]=(int)sepiaR;
		LUT->V[i]=(int)sepiaV;
		LUT->B[i]=(int)sepiaB;
	}
}

//FONCTION qui applique les effets aux LUT RVB
void applyLUT(LUT *LUT, Image *image, int sepiaUsed){
	
	//normalisation des saturations
	for (int i = 0; i < 256; i++)
	 {

	 	if (LUT->R[i] > 255)
	 	{
	 		LUT->R[i] = 255;
	 	}
	 	if (LUT->R[i] < 0)
	 	{
	 		LUT->R[i] = 0;
	 	}

	 	if (LUT->V[i] > 255)
	 	{
	 		LUT->V[i] = 255;
	 	}
	 	if (LUT->V[i] < 0)
	 	{
	 		LUT->V[i] = 0;
	 	}

	 	if (LUT->B[i] > 255)
	 	{
	 		LUT->B[i] = 255;
	 	}
	 	if (LUT->B[i] < 0)
	 	{
	 		LUT->B[i] = 0;
	 	}
	 }

	//application des effets aux LUT
 	for (int j=0; j < image->taille; j=j+3)
 	{
 		if(sepiaUsed == 1)
 		{
 			int grayscale = (int)((float)image->data[j] * 0.2125 + (float)image->data[j+1] * 0.7154 + (float)image->data[j+2] * 0.0721);
	        image->data[j] = LUT->R[grayscale];
			image->data[j+1] = LUT->V[grayscale];
			image->data[j+2] = LUT->B[grayscale];
 		}else
 		{
 			image->data[j] = LUT->R[image->data[j]];
			image->data[j+1] = LUT->V[image->data[j+1]];
			image->data[j+2] = LUT->B[image->data[j+2]];
 		}
    }
}


