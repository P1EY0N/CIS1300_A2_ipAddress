/************************quachGiaBaoA2.c**************
Student Name: Gia Bao Quach               Email Id: gquach
Due Date: November 8th, 2024              Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/
/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall quachGiaBaoA2.c quachGiaBaoA2Main.c -lm
Running: ./a.out
OR
gcc -std=c99 -Wall quachGiaBaoA2.c quachGiaBaoA2Main.c -o secondAssn -lm
Running the Program: ./secondAssn
*********************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 16

// Task 1
void readIPAddress(char ipAddress[MAX])
{
    int octet[4];
    // octet#1 input
    do
    {
        printf("Octet#1 - Enter a number - must be between 0 and 127: ");
        scanf("%d", &octet[0]);
    } while ((octet[0] < 0) || (octet[0] > 127));
    // octet#2, octet#3 and octet#4 inputs
    for (int i = 1; i < 4; i++)
    {
        do
        {
            printf("Octet#%d - Enter a number - must be between 0 and 255: ", i + 1);
            scanf("%d", &octet[i]);
        } while ((octet[i] < 0) || (octet[i] > 255));
    }
    // separate digit and assign each digit to array ipAddress
    int j = 0;

    for (int i = 0; i < 4; i++)
    {
        int tempStorage[3]; // tempStorage can store maximum 3 digits
        int tempIndex = 0;
        int number = octet[i];

        do
        {
            tempStorage[tempIndex++] = (number % 10) + '0'; // assign the last digit of number to tempStorage and increase tempIndex
            number /= 10;                                   // quotient (condition for loop)
        } while (number > 0);
        // reverse & assign tempStorage to ipAddress
        for (int k = tempIndex - 1; k >= 0; k--)
        {
            ipAddress[j++] = tempStorage[k];
        }
        // assign dot "." to ipAddress[j] after each octet
        if (i < 3)
        {
            ipAddress[j++] = '.';
        }

        ipAddress[j] = '\0'; // null-terminate for ipAddress string
    }
    /*
    Convert all the inputs (Octets#1,#2,#3,#4) into a string call ipAddress
    sprintf(ipAddress, "%d.%d.%d.%d", octet[0], octet[1], octet[2], octet[3]);
    */
}

// Task 2
long int convertIPToLongNumber(char ipAddress[MAX], int lengthIPAddr, int *numDigits)
{
    // convert ipAddress string to digit (each single digit store in array number), exclude '.'
    int octet[4];
    int octetIndex = 0;
    int tempStorage = 0;
    // convert back to int octet[0], octet[1], octet[2] and octet[3]
    for (int j = 0; j <= lengthIPAddr; j++)
    {
        if ((ipAddress[j] == '.') || (ipAddress[j] == '\0'))
        {
            octet[octetIndex++] = tempStorage; // assign tempStorage to octet[octetIndex] with the increase of octetIndex
            tempStorage = 0;                   // reset the tempStorage for the next octet build
        }
        else
        {
            tempStorage = tempStorage * 10 + (ipAddress[j] - '0'); // combine all digits BEFORE ('.' or the null) to one single digit int tempStorage
        }
    }
    // Line 80 to 92: Functions implementation (convert ipAddr to 32-bit)
    void convertToBinary(int octet, int octetBinary[8]);                         // function prototype
    void combineAllOctets(int octetBinary[8], int pos, int binaryAllOctets[32]); // function prototype

    int octetBinary[8];
    int binaryAllOctets[32];
    int pos = 0;

    for (int i = 0; i < 4; i++)
    {
        convertToBinary(octet[i], octetBinary);              // convert each octet to binary
        combineAllOctets(octetBinary, pos, binaryAllOctets); // combine binary into the 32-bit array "binaryAllOctets"
        pos += 8;                                            // update position after prior octet has already assigned to binaryAllOctets (line210->213)
    }
    // finding the first '1'
    int firstOne = 0;

    do
    {
        firstOne++;
    } while ((firstOne < 32) && (binaryAllOctets[firstOne] == 0));

    // Display 32-bits of ipAddress (exclude all leading zeros)
    printf("It is stored using 32 bits as\n");
    for (int i = firstOne; i < 32; i++)
    {
        printf("%d", binaryAllOctets[i]);
    }
    printf("\n");
    // convertBinaryToDecimal
    long int convertBinaryToDecimal(int binaryAllOctets[32]); // function prototype

    long int decimal = convertBinaryToDecimal(binaryAllOctets); // function call

    //  Count #Digits of Decimal
    int countDig(int decimal); // function prototype

    int count = countDig(decimal); // function call

    *numDigits = count;

    return decimal;
}

// Task 3
char classifyIPAddress(char ipAddress[MAX])
{
    // convert ipAddress string to digit (each single digit store in array number), exclude '.'
    int octet[4];
    int octetIndex = 0;
    int tempStorage = 0;
    // convert back to int octet[0], octet[1], octet[2] and octet[3]
    for (int j = 0; (j <= strlen(ipAddress)); j++)
    {
        if ((ipAddress[j] == '.') || (ipAddress[j] == '\0'))
        {
            octet[octetIndex++] = tempStorage; // assign tempStorage to octet[octetIndex] with the increase of octetIndex
            tempStorage = 0;                   // reset the tempStorage for the next octet build
        }
        else
        {
            tempStorage = tempStorage * 10 + (ipAddress[j] - '0'); // combine all digits BEFORE ('.' or the null) to one single digit int tempStorage
        }
    }
    // classify IP Address
    char class;
    if ((octet[1] >= 0) && (octet[1] <= 126))
    {
        class = 'A';
    }
    else if ((octet[1] >= 128) && (octet[1] <= 191))
    {
        class = 'B';
    }
    else if ((octet[1] >= 192) && (octet[1] <= 223))
    {
        class = 'C';
    }
    else if ((octet[1] >= 224) && (octet[1] <= 239))
    {
        class = 'D';
    }
    else if ((octet[1] >= 240) && (octet[1] <= 255))
    {
        class = 'E';
    }
    else
    {
        class = '\0';
    }

    return class;
}

// helper functions
void convertToBinary(int octet, int octetBinary[8])
{
    int i = 0; // MAX size of i is 8 (octetBinary)

    while (i < 8)
    {
        octetBinary[7 - i] = octet % 2; // store the remainder in reverse order
        octet = octet / 2;              // update quotient for next division until q = 0 -> loop stops
        i++;
    }
}
void combineAllOctets(int octetBinary[8], int pos, int binaryAllOctets[32])
{
    for (int i = 0; i < 8; i++)
    {
        binaryAllOctets[pos + i] = octetBinary[i];
    }
}
long int convertBinaryToDecimal(int binaryAllOctets[32])
{
    long int decimal = 0;

    for (int i = 0; i <= 32; i++)
    {
        decimal = decimal + (binaryAllOctets[i] * pow(2, (31 - i)));
    }
    return decimal;
}
int countDig(int decimal)
{
    int count = 0;
    while (decimal != 0)
    {
        decimal /= 10;
        count++;
    }
    return count;
}
