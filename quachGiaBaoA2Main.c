/************************quachGiaBaoA2Main.c**************
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
#include "givenA2.h"

int main()
{
    // todo Task 1: Display IP Address
    char ipAddress[MAX];

    readIPAddress(ipAddress); // call for task 1

    printf("IP Address: %s\n", ipAddress); // display the output ipAddress
    printf("\n");

    // todo Task 2: Convert ipAddress into 32-bits
    int lengthIPAddr = strlen(ipAddress);
    int numDigits;

    long int decimal = convertIPToLongNumber(ipAddress, lengthIPAddr, &numDigits); // function call

    printf("The above 32-bit binary representation is then converted to its decimal equivalent and stored as a long int is\n");
    printf("%ld\n", decimal);

    printf("The number of digits in this long int is %d\n", numDigits);
    printf("\n");

    // todo Task 3: Classify IP Address
    char class = classifyIPAddress(ipAddress);

    printf("Class for %s = %c\n", ipAddress, class);

    return 0;
}
