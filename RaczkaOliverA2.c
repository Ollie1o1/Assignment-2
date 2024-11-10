/************************RaczkaOliverA2.c**************
Student Name: Oliver Raczka Email Id: oraczka
Due Date: October 8, 2024 Course Name: CIS 1300
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
#include <stdio.h>
#include <string.h>
#define MAX 16

// Function prototypes
void readIPAddress(char ipAddress[]);
long int convertIPToLongNumber(char ipAddress[], int lengthIPAddr, int *numDigits);
char classifyIPAddress(char ipAddress[]);
void convertToBinary(int octet, int octetBinary[8]);
void combineAllOctets(int octetBinary[8], int pos, int binaryAllOctets[32]);
long int convertBinaryToDecimal(int binaryAllOctets[32]);
int countDig(int num);

int main() {
    // Declare necessary variables
    int numDigits;
    char ipAddress[MAX];
    
    // Read IP address
    readIPAddress(ipAddress);
    printf("\n");
    printf("Task 1 ends\n");
    printf("\n");
    printf("Testing Task 2 in main\n");
    printf("\n");

    // Convert IP address to long integer
    long int ipAsLong = convertIPToLongNumber(ipAddress, strlen(ipAddress), &numDigits);
    printf("ipDecimal = %ld\n", ipAsLong);
    printf("Number of digits = %d\n", numDigits);
    printf("Task 2 ends\n");
    printf("\n");
    printf("Testing Task 3 in main\n");
    printf("\n");

    // Classify IP address
    char ipClass = classifyIPAddress(ipAddress);
    printf("Class for %s = %c\n", ipAddress, ipClass);
    printf("Task 3 ends\n");
    printf("\n");
    return 0;
}
