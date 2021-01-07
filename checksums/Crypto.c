/**
* Program: Crypto - Main 
* Author: Xinthral 
* Date: 3/7/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Checksum.h"
#include "Key.h"

int main(int argc, char **argv){
	// Condition to see if there are enough parameters to execute on
	if (argc > 3) {
		int debug = 0;
		if (argc == 5 && atoi(argv[4]) == 1) {
			//printf("Debug: %s\nargc: %d\nargv[1]/[2]: %s/%s\n", (debug) ? "True" : "False", argc, argv[1], argv[2]);				// DEBUG: Line to view arguments
			debug = 1;
		}

		// Initialize Variables
		int mesLen = getMessageLength(argv[1]);
		int secLen = getMessageLength(argv[2]);
		int outLen = (secLen > mesLen) ? secLen : mesLen;
		int mesCheckSum = 0;
		int outCheckSum = 0;
		
		// Initialize Arrays
		char *message = malloc(sizeof(char) * mesLen + 1);
		char *secret = malloc(sizeof(char) * secLen + 1);
		char *output = malloc(sizeof(int) * outLen + 1);

		// Read in files to arrays
		readInFile(argv[1], message);
		readInFile(argv[2], secret);
		translateMessage(message, secret, output, mesLen, secLen, debug);	
		writeToFile(argv[3], output, outLen);

		// Calculate Checksum
		mesCheckSum = calculateChecksum(message, mesLen);
		outCheckSum = calculateChecksum(output, outLen);

		// Display Checksum Values
		printf("Input checksum  : %04X\nOutput checksum : %04X\n", mesCheckSum, outCheckSum);

		// Free up memory blocks
		free(message);
		free(secret);
		free(output);
	// Print properly formated command syntax to user
	} else {
		printf("Crypto <input file> <key file> <output file> [debug]\n");
	}
	return 0;
}

