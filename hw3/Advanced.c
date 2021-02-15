#include "Constants.h" 
#include "Advanced.h" 

void NegativeFilter(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]) { 
	int x, y;
	int Rn, Gn, Bn;
	for(x=0; x < WIDTH; x++) { 
		for(y=0; y < HEIGHT; y++) { 
			Rn = 255 - R[x][y];
			Gn = 255 - G[x][y];
			Bn = 255 - B[x][y]; 

			R[x][y] = Rn;
			G[x][y] = Gn;
			B[x][y] = Bn; 
		} 
	}
}

void Noise(int n, unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]) { 
	int x, y, px, i;
	srand(time(NULL));
	px = n * WIDTH * HEIGHT / 100;
	for(i=0; i<px; i++) {
		x = rand() % WIDTH;
		y = rand() % HEIGHT;

		R[x][y] = 255;
		G[x][y] = 255; 
		B[x][y] = 255; 
	}
}

void Posterize(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], unsigned int rbits, unsigned int gbits, unsigned int bbits) { 
	int x, y, z, r, g, b;
	for(y=0; y < HEIGHT; y++) { 
		for(x=0; x < WIDTH; x++) { 
			r=0, b=0, g=0;

			for(z=0; z<rbits-1; z++) { 
				r = (r << 1) + 1;
			} 
			R[x][y] = R[x][y] | r;
			R[x][y] = R[x][y] & ~(1 << (rbits-1) );

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



