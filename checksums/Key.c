/**
* Program: Crypto - KeyHandler
* Author: Xinthral
* Date: 3/7/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Definitions */
int getMessageLength(char *inputFile) {
	int size = 0;
	FILE* fin = fopen(inputFile, "r");
	if (fin != NULL) {
		int ch = '\0';
		while ((ch = fgetc(fin)) != EOF) {
			size++;
		}
		fclose(fin);
		fin = NULL;
	}
	return size;
}

void readInFile(char *inputFile, char *outputArray) {
	FILE* fin = fopen(inputFile, "r");
	if (fin != NULL) {
		int ch = '\0';
		int i = 0;
		while ((ch = fgetc(fin)) != EOF) {
			outputArray[i] = ch;
			i++;
		}
		fclose(fin);
		fin = NULL;
		outputArray[i] = '\0';
	}
}

// Write to output message to output file
void writeToFile(char *outFile, char *string, int length) {
	FILE *fout = fopen(outFile, "wb");
	if (fout != NULL) {
		fwrite(string, sizeof(char), length, fout);
		fclose(fout);
		fout = NULL;
	} else {
		printf("File does not exists!");
	}
}

void translateMessage(char *message, char *secret, char *output, int messageSize, int secretSize, int debug) {
	int count = 0;

	for (int i = 0; i < messageSize; i++) {
		if (count >= secretSize) {
			count = 0;
		}
		output[i] = message[i] ^ secret[count];
		if (debug == 1) {
			printf("%3d ^ %3d -> %3d\n", (unsigned char) message[i], (unsigned char) secret[count], (unsigned char) output[i]);
		}
		count++;
	}
	//for (int j = 0; j < messageSize; j++) {
	//	printf("%c", output[j]);
	//}
}
