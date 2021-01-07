/**
 * Program: Dynamic Array Allocation
 * Author: Xinthral
 * Date: 4/19/2019
 */
#include <stdio.h>
#include <stdlib.h>

void initArray(int** inputArray, int size) {
	int* iArray = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		iArray[i] = 0;
	}
	inputArray = &iArray;
}


// int main(int argc, char** argv) {
// 	int* myArray = NULL;
// 	int length = 10;
// 	initArray(&myArray, length);
// 	for(int i = 0; i < length; i++) {
// 		printf("%d: %d\n", i, myArray[i]);
// 	}
// }
