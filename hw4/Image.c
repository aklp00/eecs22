#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "Constants.h"  
#include "Image.h"

typedef unsigned char us;

us GetPixelR(const IMAGE *image, unsigned int x, unsigned int y) {
	us tempr; 
	tempr = image -> R[x + y *(image -> W)];
	return tempr;
} 

us GetPixelG(const IMAGE *image, unsigned int x, unsigned int y) { 
	us tempg; 
	tempg = image -> G[x + y *(image -> W)];
	return tempg;
} 

us GetPixelB(const IMAGE *image, unsigned int x, unsigned int y) { 
	us tempb;
	tempb = image -> B[x + y *(image -> W)];
	return tempb;
}

