/**
* Program: Crypto - Checksum 
* Author: Xinthral 
* Date: 3/7/2019
*/
#include <stdio.h>
#include <stdlib.h>

// add all the bits in hex, take the 8 least significant bits and subtract that hex from 0xFF to get checksum
int calculateChecksum(char *message, int length) {
	unsigned char sum1 = 0;
	unsigned char sum2 = 0;

	for (int i = 0; i < length; i++) {
		sum1 = ((unsigned char) sum1 + (unsigned char) message[i]) % 255;
		sum2 = (sum1 + sum2) % 255;

	}
	return (sum2 << 8) | sum1;
}
