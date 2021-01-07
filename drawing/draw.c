// Code for ASCII Drawing assignment
/**
 * TODO: Needs comments, and switch statement could be modulated
 * probably do with some ternaries and struct's for long argument list
 */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
void initImage(int width, int height, double image[][width]);
char grayScaleColor(double value);
void printImage(int width, int height, double image[][width]);
void drawPoint(int width, int height, double image[][width], int x, int y, double color);
void drawRectangle(int width, int height, double image[][width], int left, int top, int rectangleWidth, int rectangleHeight, double color);
void getImageStats(int width, int height, double image[][width], double *minColor, double *maxColor, double *avgColor);
void floodFill(int width, int height, double image[][width], int x, int y, double color);

// Read in a set of drawing instructions from standard input.
// Print the resulting greyscale image as ASCII art.
int main(void) {
   // Read in the size of the drawing canvas
   int width = 0;
   int height = 0;
   int result = scanf("%d %d", &width, &height);

   // Program only supports images that are 1x1 or bigger
   if ((width <= 0) || (height <= 0) || (result != 2)) {
      printf("Failed to read a valid width and height from standard input!\n");
      return 0;
   }

   // Create the 2D arary and initialize all the greyscale values to 0.0
   double image[width][height];
   initImage(width, height, image);

   char command = '\0';
   double color = 0.0;

   // Keep reading in drawing commands until we reach the end of the input
   while (scanf(" %c", &command) == 1) {
      switch (command) {
         case 'p': {
            // Draw a point, read in: x, y, color
            int x = 0;
            int y = 0;
            result = scanf("%d %d %lf", &x, &y, &color);
            if (result != 3) {
               printf("Invalid point command!\n");
               return 0;
            }

            drawPoint(width, height, image, x, y, color);
            break;
         }

         case 'r': {
            // Draw a rectangle, read in: x, y, w, h, color
            int left = 0;
            int top = 0;
            int rectangleWidth = 0;
            int rectangleHeight = 0;
            result = scanf("%d %d %d %d %lf", &left, &top, &rectangleWidth, &rectangleHeight, &color);
            if (result != 5) {
               printf("Invalid rectangle command!\n");
               return 0;
            }

            drawRectangle(width, height, image, left, top, rectangleWidth, rectangleHeight, color);
            break;
         }

         case 'f': {
            // Flood fill a color in, read in: x, y, color
            int x = 0;
            int y = 0;
            result = scanf("%d %d %lf", &x, &y, &color);
            if (result != 3) {
               printf("Invalid flood fill command!\n");
               return 0;
            }

            floodFill(width, height, image, x, y, color);
            break;
         }

         default: {
            printf("Unknown command!\n");
            return 0;
         }
      }
   }

   // Print the final image
   printImage(width, height, image);

   // Finally display some statistics about the image
   double minColor = 0.0;
   double maxColor = 0.0;
   double avgColor = 0.0;
   getImageStats(width, height, image, &minColor, &maxColor, &avgColor);
   printf("Color range [%.2f, %.2f], average %.4f\n", minColor, maxColor, avgColor);
}

/* Function Definitions */
void initImage(int width, int height, double image[width][height]) {
	int row;
	int col;
	for (row = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			image[row][col] = 0.0;
		}
	}
}

char grayScaleColor(double value)
{
	char pixel;
	if ( value < 0.2 ) {
		pixel = ' ';
	} else if ( value < 0.4 ) {
		pixel = '.';
	} else if ( value < 0.6 ) {
		pixel = 'o';
	} else if ( value < 0.8 ) {
		pixel = 'O';
	} else if ( value <= 1.0 ) {
		pixel = '@';
	} else {
		pixel = ' ';
	}
	return pixel;
}

void printImage(int width, int height, double image[width][height]) {
	printf("+");
	for (int i = 0; i < width; i++) {
		printf("-");
	}
	printf("+\n");
	for (int row = 0; row < height; row++) {
		printf("|");
		for (int col = 0; col < width; col++) {
			printf("%c", grayScaleColor(image[col][row]));
		}
		printf("|\n");
	}
	printf("+");
	for (int j = 0; j < width; j++) {
		printf("-");
	}
	printf("+\n");
}

void drawPoint(int width, int height, double image[width][height], int x, int y, double color) {
	if (x >= 0 && x < width && y >= 0 && y < height) {
		image[x][y] = color;
	}
}

void drawRectangle(int width, int height, double image[width][height], int left, int top, int rectangleWidth, int rectangleHeight, double color) {
	for (int i = top; i < (top + rectangleHeight); i++) {
		for (int j = left; j < (left + rectangleWidth); j++) {
			drawPoint(width, height, image, j, i, color);
		}
	}
}

void getImageStats(int width, int height, double image[width][height], double *minColor, double *maxColor, double *avgColor) {
	double sum = 0.0;
	double temp = 0.0;
	*minColor = 1.0;
	*maxColor = 0.0;
	*avgColor = 0.0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			temp = image[i][j];
			if (temp < *minColor) {
				*minColor = temp;
			}
			if (temp > *maxColor) {
				*maxColor = temp;
			}
			sum += temp;
		}
	}
	*avgColor = sum / ((height) * (width));
}

void floodFill(int width, int height, double image[width][height], int x, int y, double color) {
	if ( x >= 0 && x < width && y >= 0 && y < height ) {
		image[x][y] = color;
		// Up
		if ( color > image[x][y-1] ) {
			floodFill( width, height, image, x, y-1, color );
		}
		// Down
		if ( color > image[x][y+1] ) {
			floodFill( width, height, image, x, y+1, color );
		}
		// East
		if ( color > image[x+1][y] ) {
			floodFill( width, height, image, x+1, y, color );
		}
		// Weast lol
		if ( color > image[x-1][y] ) {
			floodFill( width, height, image, x-1, y, color );
		}
	}
}
