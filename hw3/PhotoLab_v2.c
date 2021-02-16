/****************************************
 * Name: Akhil Pappu (sole modifier)
 * Professor QV Dang 
 * Date: 16 February 2020
 * Assignment 3: PhotoLab_v2
 *
 * Modifications: 
 *  7 February 2020-Files decomposed
 *  9 February 2020-Completed header files
 * 11 Febraury 2020-Completed advanced image operations 
 * 15 february 2020-Completed makefile and finished the assignment 
******************************************/

#include "FileIO.h" 
#include "DIPs.h" 
#include "Constants.h"
#include "Advanced.h" 


void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT]); 
void PrintMenu(void); 

int main(void)
{
	int rc;
	/* Two dimensional arrays to hold the current image data, */
    /* one array for each color component.                    */
    
	unsigned char   R[WIDTH][HEIGHT];
    unsigned char   G[WIDTH][HEIGHT];
    unsigned char   B[WIDTH][HEIGHT];
	#ifdef DEBUG 
	AutoTest(R, G, B);
	rc = 0;

    /* Please replace the following code with proper menu  */
    /* with function calls for DIP operations	           */
    #else
	int option;              		  // user input option
    char fname[SLEN];        	 	  // input file name
	int n; 				     		  // percentage of noise
    unsigned int rbits, gbits,bbits;  //number of bits to posterize 
	// print welcome message only once
        
    rc = -1;        // return code of LoadImage()
	
	   
	PrintMenu();
    scanf("%d", &option);

    while (option != 99)
    {   
        // menu item 2-4 requires image is loaded first
        if (option == 1)
        {   printf("Please input the file name to load: ");
            scanf("%s", fname);
            rc = LoadImage(fname, R, G, B);
        }
        else if (option >= 2 && option <= 8)
        {   if (rc != 0)
            {   printf("No image was read.\n");
            }
            else
            {   switch(option)
                {   case 2:
                        printf("Please input the file name to save: ");
                        scanf("%s", fname);
                        SaveImage(fname, R, G, B);
                        break;
                    case 3:
                        Aging(R, G, B);
                        printf("\"Aging\" operation is done!\n");
                        break;
                    case 4:
                        EdgeDetection(R, G, B);
                        printf("\"Edge Detection\" operation is done!\n");
                        break;
                    case 5:
                        Sharpen(R, G, B);
						printf("\"Sharpen\" operation is done!\n");
                        break;
					case 6: 
						printf("Please input noise percentage: ");
						scanf("%d", &n);
						Noise(n, R, G, B);
						printf("\"Noise\" operation is done!\n");
						break;
					case 7: 
						printf("Enter the number of posterization buts for R channel (1 to 8): "); 
						scanf("%d", &rbits);
						printf("Enter the number of posterization buts for G channel (1 to 8): "); 
						scanf("%d", &bbits);
						printf("Enter the number of posterization buts for B channel (1 to 8): "); 
						scanf("%d", &gbits);
						Posterize(R, G, B, rbits, gbits, bbits); 
						printf("\"Posterize\" operation is done!\n");
						break;
					case 8: 
						NegativeFilter(R, G, B);
						printf("\"Negative\" operation is done!\n");
						break;
                    default:
                        break;
                }   
            }
        }
        else if (option == 22)
        {   AutoTest(R, G, B);
        }
        else
        {   printf("Invalid selection!\n");
        }
        // Process finished, waiting for anothre input
        PrintMenu();
        
        scanf("%d", &option);   
    }


    printf("Exiting program.\n");
    /* End of replacing */
	#endif
    return 0;
} /*end of main*/


void PrintMenu()
{   printf("\n-------------------------\n");
    printf(" 1: Load a PPM image\n");
    printf(" 2: Save the image in PPM and JPEG format\n");
    printf(" 3: Run aging filter\n");
    printf(" 4: Run edge detection filter\n");
    printf(" 5: Run sharpen filter\n");
	printf(" 6: Run noise filter\n");
	printf(" 7: Run posterize filter\n");
	printf(" 8: Run negative filter\n");
    printf("22: Test all functions\n");
    printf("99: Exit\n");
    printf("--------------------------\n");
    printf("Please make your choice: ");
}

void AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
	char fname[SLEN] = "pigeon";
    LoadImage(fname, R, G, B);
    Aging(R, G, B);
    SaveImage("aging", R, G, B);
	#ifdef DEBUG 
    printf("Aging tested!\n\n");
    #endif 

    /* add more tests here ("edge" and "sharpen")*/
    LoadImage(fname, R, G, B);
    EdgeDetection(R, G, B);
    SaveImage("edge", R, G, B);
	#ifdef DEBUG
    printf("Edge Detection tested!\n\n");
    #endif 

    LoadImage(fname, R, G, B);
    Sharpen(R, G, B);
    SaveImage("sharpen", R, G, B);
	#ifdef DEBUG 
    printf("Sharpen tested!\n\n");
    #endif 

   LoadImage(fname, R, G, B);
   Noise(30, R, G, B);
   SaveImage("noise", R, G, B);
   #ifdef DEBUG 
   printf("Noise tested!\n\n");
   #endif 

   LoadImage(fname, R, G, B);
   NegativeFilter(R, G, B);
   SaveImage("negative", R, G, B);
   #ifdef DEBUG 
   printf("Negative tested!\n\n");
   #endif 

   LoadImage(fname, R, G, B);
   Posterize(R, G, B, 7, 7, 7);
   SaveImage("posterize", R, G, B);
   #ifdef DEBUG 
   printf("Posterize tested!\n\n");
   #endif 
}
    
