#ifndef __KEY_H_
#define __KEY_H_

int getMessageLength(char *inputFile);
void readInFile(char *inputFile, char *outputArray);
void writeToFile(char *outFile, char *string, int length);
void translateMessage(char *message, char *secret, char *output, int messageSize, int secretSize, int debug);

#endif
