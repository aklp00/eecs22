#include "Constants.h" 
#include "Advanced.h" 


/*changes each pixel to a negative version of itself (inverts it)*/
void NegativeFilter(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]) { 
	int x, y;
	int Rn, Gn, Bn;
	for(x=0; x < WIDTH; x++) { 
		for(y=0; y < HEIGHT; y++) { 
			Rn = 255 - R[x][y];	/*subtracting every pixel from 255*/ 
			Gn = 255 - G[x][y];
			Bn = 255 - B[x][y]; 

			R[x][y] = Rn;
			G[x][y] = Gn;
			B[x][y] = Bn; 
		} 
	}
}

/*randomly adds whit pixels across the image to simulate noise*/
void Noise(int n, unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]) { 
	int x, y, px, i;
	srand(time(NULL));
	px = n * WIDTH * HEIGHT / 100; /*finding the number of pixels to change*/
	for(i=0; i<px; i++) {
		x = rand() % WIDTH;       /*randomizing the x coordinate of the pixel to change*/
		y = rand() % HEIGHT;      /*randomizing the y coordinate of the pixel to change*/

		R[x][y] = 255;            /*assigning each coordinate the color white*/
		G[x][y] = 255; 
		B[x][y] = 255; 
	}
}

void Posterize(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], unsigned int rbits, unsigned int gbits, unsigned int bbits) { 
	int x, y, z, r, g, b;
	for(y=0; y < HEIGHT; y++) { 
		for(x=0; x < WIDTH; x++) { 
			r=0, b=0, g=0;
			/*iterating through n-1 bits*/
			for(z=0; z<rbits-1; z++) { 
				r = (r << 1) + 1;	/*calculating the decimal value, for example, 63 = 11111*/
			} 
			R[x][y] = R[x][y] | r;	/*comparing 11111 using OR with the pixel value*/
			R[x][y] = R[x][y] & ~(1 << (rbits-1) ); /*using AND to change the nth bit to 0*/

			for(z=0; z<gbits-1; z++) { 
				g = (g << 1) + 1; 
			} 
			G[x][y] = G[x][y] | g;
			G[x][y] = G[x][y] & ~(1 << (gbits - 1) );

			for(z=0; z<bbits-1; z++){
				b = (b << 1) + 1;
			}
			B[x][y] = B[x][y] | b;
			B[x][y] = B[x][y] & ~(1 << (bbits - 1) );
		}
	}
}



