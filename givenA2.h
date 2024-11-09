#include <stdio.h>
#include <string.h>

#define MAX 16

// Task 1
void readIPAddress(char ipAddress[]);

// Task 2
long int convertIPToLongNumber(char ipAddress[], int lengthIPAddr, int *numDigits);

// Task 3
char classifyIPAddress(char ipAddress[]);

// helper functions

int countDig(int);
void convertToBinary(int octet, int octetBinary[8]);
void combineAllOctets(int octetBinary[8], int pos, int binaryAllOctets[32]);
long int convertBinaryToDecimal(int binaryAllOctets[32]);
