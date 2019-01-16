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

//FONCTION qui applique les effets aux LUT RVB
void applyLUT(LUT *LUT, Image *image){
	
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
        image->data[j] = LUT->R[image->data[j]];
		image->data[j+1] = LUT->V[image->data[j+1]];
		image->data[j+2] = LUT->B[image->data[j+2]];        
        
    }
}

//FONCTION qui appelle les filtres en fonction des commandes
void startLUT(int argc,char **argv,LUT *LUT,Image *image) {
	int i=2;
    while (i!= argc-2){
        
        if (strcmp(argv[i],"ADDLUM") == 0)
        {
        	printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));
            addLUM(atoi(argv[i+1]),LUT);
        }

        if (strcmp(argv[i],"DIMLUM") == 0)
        {
        	printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));
            dimLUM(atoi(argv[i+1]),LUT);
        }

        if (strcmp(argv[i],"ADDCON") == 0)
        {
        	printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));
            addCON(atoi(argv[i+1]),LUT);
        }

        if (strcmp(argv[i],"DIMCON") == 0)
        {
        	printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));
            dimCON(atoi(argv[i+1]),LUT);
        }

        if (strcmp(argv[i],"INVERT") == 0)
        {
        	printf("START : %s %s %d\n",argv[i+1] , argv[i],  atoi(argv[i+1]));
            invert(LUT);
        }
        i++;
    }   
    applyLUT(LUT,image);
}

