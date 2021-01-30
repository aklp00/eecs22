/*********************************************************************/
/* PhotoLab.c: Assignment 2 for EECS 22, Winter 2020                 */
/* 								     								 */
/* modifications: 						     						 */
/* 01/13/21     QV  Adjusted for W21                                 */
/* 01/11/20 	WL	adjusted for W20			     				 */
/* 10/1/18  	MC  adjusted for F18			             	 	 */
/* 09/27/17 	RD	adjusted for lecture usage		      			 */
/*********************************************************************/
/* Enter your name, last name and UCInet ID below: 
 * ***************************************************************** *
 * First Name: Akhil 
 * Last Name: Pappu 	
 * UCInetID: apappu
 */

/*** header files ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*** global definitions ***/

#define WIDTH  600		/* image width */
#define HEIGHT 400		/* image height */
#define SLEN    64		/* maximum length of file names */

// added new defines for edge detection filter
// you can use these or not (not necessary, but we used it for convenience)
#define MAX_PIXEL 255	/* max pixel value */
#define MIN_PIXEL 0		/* min pixel value */

/*** function declarations ***/

/* print a menu */
void PrintMenu(void);

/* read image from a file */
/* written for you; should not been modified */
int LoadImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* save a processed image */
/* written for you; should not been modified */
int SaveImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* aging the photo */
/* sample function to get you started */
void Aging(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* detect edges in a picture (black background with white edges) */
void EdgeDetection(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* sharpen the image */
void Sharpen(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

/* test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]);

int main(void)
{
    /* Two dimensional arrays to hold the current image data, */
    /* one array for each color component.                    */
    unsigned char   R[WIDTH][HEIGHT];
    unsigned char   G[WIDTH][HEIGHT];
    unsigned char   B[WIDTH][HEIGHT];
	int choice; 
	char flen[SLEN];
	printf("\nWelcome to PhotoLab 2021 - v1!\n");
	printf("-----------------------------------------\n");
	while(choice != 99) { 
		PrintMenu();
		scanf("%d", &choice);
		switch(choice) { 
			case 1: 
				printf("Please input the file name to load: ");
				scanf("%s", flen);
				LoadImage(flen, R, G, B);
				continue;
			case 2: 
				printf("Please input the file name to save: ");
				scanf("%s", flen);
				SaveImage(flen, R, G, B);
				continue;
			case 3: 
				Aging(R, G, B);
				printf("Aging tested!\n\n");
				continue;
			case 4:
				EdgeDetection(R, G, B); 
				printf("Edge Detection tested!\n\n");
				continue;
			case 5: 
				Sharpen(R, G, B);
				printf("Sharpen tested!\n\n");
				continue;
			case 22: 
			 	AutoTest(R, G, B);
				continue;
			case 99: 
				break; 
		}
	}
	return 0;

    /* Please replace the following code with proper menu  */
    /* with function calls for DIP operations	           */
    
    // this command is here temporarily so you can see it works
    // only does aging function by default with lambo.ppm file
    // remove before writing your program


    /* End of replacing */

}

/* takes in a file name without extension */
/* writes file into R, G, B arrays */
int LoadImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    char Type[SLEN];
    int  Width, Height, MaxValue;
    int  x, y;
    char ftype[] = ".ppm";
    char fname_ext[SLEN + sizeof(ftype)];

    strcpy(fname_ext, fname);
    strcat(fname_ext, ftype);

    File = fopen(fname_ext, "r");
    if (!File) {
        printf("\nCannot open file \"%s\" for reading!\n", fname);
        return 1;
    }
    fscanf(File, "%79s", Type);
    if (Type[0] != 'P' || Type[1] != '6' || Type[2] != 0) {
        printf("\nUnsupported file format!\n");
        return 2;
    }
    fscanf(File, "%d", &Width);
    if (Width != WIDTH) {
        printf("\nUnsupported image width %d!\n", Width);
        return 3;
    }
    fscanf(File, "%d", &Height);
    if (Height != HEIGHT) {
        printf("\nUnsupported image height %d!\n", Height);
        return 4;
    }
    fscanf(File, "%d", &MaxValue);
    if (MaxValue != 255) {
        printf("\nUnsupported image maximum value %d!\n", MaxValue);
        return 5;
    }
    if ('\n' != fgetc(File)) {
        printf("\nCarriage return expected!\n");
        return 6;
    }
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            R[x][y] = fgetc(File);
            G[x][y] = fgetc(File);
            B[x][y] = fgetc(File);
        }
    }
    if (ferror(File)) {
        printf("\nFile error while reading from file!\n");
        return 7;
    }
    printf("%s was read successfully!\n", fname_ext);
    fclose(File);
    return 0;
}

/* takes R, G, B arrays and writes it in a file */
/* filename (fname) has no extension */
int SaveImage(const char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    FILE *File;
    char ftype[] = ".ppm";
    char fname_ext[SLEN + sizeof(ftype)];
    char SysCmd[SLEN * 5];
    int  x, y;

    strcpy(fname_ext, fname);
    strcat(fname_ext, ftype);

    File = fopen(fname_ext, "w");
    if (!File) {
        printf("\nCannot open file \"%s\" for writing!\n", fname);
        return 1;
    }
    fprintf(File, "P6\n");
    fprintf(File, "%d %d\n", WIDTH, HEIGHT);
    fprintf(File, "255\n");

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fputc(R[x][y], File);
            fputc(G[x][y], File);
            fputc(B[x][y], File);
        }
    }

    if (ferror(File)) {
        printf("\nFile error while writing to file!\n");
        return 2;
    }
    fclose(File);
    printf("%s was saved successfully. \n", fname_ext);

    /*
     * rename file to image.ppm, convert it to ~/public_html/<fname>.jpg
     * and make it world readable
     */
    sprintf(SysCmd, "~eecs22/bin/pnmtojpeg_hw2.tcsh %s", fname_ext);
    if (system(SysCmd) != 0) {
        printf("\nError while converting to JPG:\nCommand \"%s\" failed!\n", SysCmd);
        return 3;
    }
    printf("%s.jpg was stored for viewing. \n", fname);

    return 0;
}


/* Test all functions */
void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{

    LoadImage("lambo", R, G, B);
    Aging(R, G, B);
    SaveImage("aging", R, G, B);
    printf("Aging tested!\n\n");

    LoadImage("lambo", R, G, B); 
    EdgeDetection(R, G, B); 
	SaveImage("edge", R, G, B);
	printf("Edge Detection tested!\n\n");

	LoadImage("lambo", R, G, B);
	Sharpen(R, G, B);
	SaveImage("sharpen", R, G, B);
	printf("Sharpen tested!\n\n");
    /* add more tests here ("edge" and "sharpen")*/

}

/**************************************************************/
/* Please complete and add function definitions below...      */
/**************************************************************/

/* age the image to make it look like old picture */
void Aging(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
    int x, y;

    for( y = 0; y < HEIGHT; y++ ) {
        for( x = 0; x < WIDTH; x++ ) {
	    B[x][y] = ( R[x][y]+G[x][y]+B[x][y] )/5;
            R[x][y] = (unsigned char) (B[x][y]*1.6);
            G[x][y] = (unsigned char) (B[x][y]*1.6);
	    }
    }
}

void EdgeDetection(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{   
  	int x, y, red, green, blue; 
    /*temp arrays to avoid contamination*/
	int Rc[WIDTH][HEIGHT];
	int Bc[WIDTH][HEIGHT];
	int Gc[WIDTH][HEIGHT];
	for(x = 0; x < WIDTH; x++) { 
		for(y = 0; y < HEIGHT; y++) { 
			Rc[x][y] = R[x][y];
			Bc[x][y] = B[x][y];
			Gc[x][y] = G[x][y];
		}
	}
	
    for(x = 0; x < WIDTH; x++) { 
		for(y = 0; y < HEIGHT; y++) { 
	    	red    = 8*Rc[x][y]-Rc[x-1][y-1]-Rc[x][y-1]-Rc[x+1][y-1]-Rc[x-1][y]-Rc[x+1][y]-Rc[x-1][y+1]-Rc[x][y+1]
					-Rc[x+1][y+1];
	    	green  = 8*Gc[x][y]-Gc[x-1][y-1]-Gc[x][y-1]-Gc[x+1][y-1]-Gc[x-1][y]-Gc[x+1][y]-Gc[x-1][y+1]-Gc[x][y+1]
					-Gc[x+1][y+1];
	    	blue = 8*Bc[x][y]-Bc[x-1][y-1]-Bc[x][y-1]-Bc[x+1][y-1]-Bc[x-1][y]-Bc[x+1][y]-Bc[x-1][y+1]-Bc[x][y+1]
					-Bc[x+1][y+1];
			if((x < 2 || y < 2) || (x > 598 || y > 398))  { 
				red = 0; 
				blue = 0;
				green =0;
			}
			if(red < 0){ 
				red = 0; 
			} if(red > 255){ 
				red = 255;
			} 
			if(blue < 0){ 
				blue = 0; 
			} if(blue > 255){ 
				blue = 255;
			} 
			if(green < 0){ 
				green = 0;
			} if(green > 255){ 
				green = 255;
			}
			R[x][y] = red;
			B[x][y] = blue; 
			G[x][y] = green;
		} 
	}
	 
	
} 

void Sharpen(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
  	int x, y, red, green, blue; 
    /*temp arrays to avoid contamination*/
	int Rc[WIDTH][HEIGHT];
	int Bc[WIDTH][HEIGHT];
	int Gc[WIDTH][HEIGHT];
	for(x = 0; x < WIDTH; x++) { 
		for(y = 0; y < HEIGHT; y++) { 
			Rc[x][y] = R[x][y];
			Bc[x][y] = B[x][y];
			Gc[x][y] = G[x][y];
		}
	}
	
    for(y = 1; y < HEIGHT-1; y++) { 
		for(x = 1; x < WIDTH-1; x++) { 
	    	red    = 9*Rc[x][y]-Rc[x-1][y-1]-Rc[x][y-1]-Rc[x+1][y-1]-Rc[x-1][y]-Rc[x+1][y]-Rc[x-1][y+1]-Rc[x][y+1]
					-Rc[x+1][y+1];
	    	green  = 9*Gc[x][y]-Gc[x-1][y-1]-Gc[x][y-1]-Gc[x+1][y-1]-Gc[x-1][y]-Gc[x+1][y]-Gc[x-1][y+1]-Gc[x][y+1]
					-Gc[x+1][y+1];
	    	blue = 9*Bc[x][y]-Bc[x-1][y-1]-Bc[x][y-1]-Bc[x+1][y-1]-Bc[x-1][y]-Bc[x+1][y]-Bc[x-1][y+1]-Bc[x][y+1]
					-Bc[x+1][y+1];
			if(red < 0){ 
				red = 0; 
			} if(red > 255){ 
				red = 255;
			} 
			if(blue < 0){ 
				blue = 0; 
			} if(blue > 255){ 
				blue = 255;
			} 
			if(green < 0){ 
				green = 0;
			} if(green > 255){ 
				green = 255;
			}
			R[x][y] = red;
  			B[x][y] = blue; 
			G[x][y] = green;
		}
	}
}

void PrintMenu(void)
{
	printf("\n");
	printf(" 1: Load PPM image\n");
	printf(" 2: Save image in PPM and JPEG format\n");
	printf(" 3: Run aging filter\n");
	printf(" 4: Run edge detection filter\n");
	printf(" 5: Run sharpen filter\n");
	printf("22: Test all functions\n");
	printf("99: Exit\n");
	printf("-----------------------------------------\n");
	printf("Please make your choice: ");
}


	


/* MORE COMING SOON */

/* EOF */
