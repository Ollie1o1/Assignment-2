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

void readIPAddress(char ipAddress[]);
long int convertIPToLongNumber(char ipAddress[], int lengthIPAddr, int *numDigits);
char classifyIPAddress(char ipAddress[]);
void convertToBinary(int octet, int octetBinary[8]);
void combineAllOctets(int octetBinary[8], int pos, int binaryAllOctets[32]);
long int convertBinaryToDecimal(int binaryAllOctets[32]);
int countDig(int num);

// Task 1
void readIPAddress(char ipAddress[]) {
    int octet[4];
    for (int i = 0; i < 4; i++) {
        int min = (i == 0) ? 0 : 0;
        int max = (i == 0) ? 127 : 255;
        
        while (1) {
            // Prompt for the octet input
            printf("Octet#%d - Enter a number - must be between %d and %d: ", i + 1, min, max);
            scanf("%d", &octet[i]);

            // Check if the input is valid
            if (octet[i] >= min && octet[i] <= max) {
                break; // Exit the loop if valid
            }
        }
   
    }
    sprintf(ipAddress, "%d.%d.%d.%d", octet[0], octet[1], octet[2], octet[3]);
    printf("IP Addr: %s\n", ipAddress);
}
// Task 2
long int convertIPToLongNumber(char ipAddress[], int lengthIPAddr, int *numDigits) {
    int octet[4];
    int octetBinary[8];
    int binaryAllOctets[32] = {0};

    // Extract each octet from the IP address string
    sscanf(ipAddress, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]);

    for (int i = 0; i < 4; i++) {
        convertToBinary(octet[i], octetBinary);
        combineAllOctets(octetBinary, i * 8, binaryAllOctets);
    }

    
    long int ipLong = convertBinaryToDecimal(binaryAllOctets);
    *numDigits = countDig(ipLong);
    
    return ipLong;
}

// Task 3
char classifyIPAddress(char ipAddress[]) {
    int octet[4];
    sscanf(ipAddress, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]);

    if (octet[1] >= 0 && octet[1] <= 126) {
        return 'A';
    } else if (octet[1] >= 128 && octet[1] <= 191) {
        return 'B';
    } else if (octet[1] >= 192 && octet[1] <= 223) {
        return 'C';
    } else if (octet[1] >= 224 && octet[1] <= 239) {
        return 'D';
    } else if (octet[1] >= 240 && octet[1] <= 255) {
        return 'E';
    } else {
        return 'X';
    }
}

// Helper function to count the number of digits in a number
int countDig(int num) {
    int numDigits = 0;
    
    if (num == 0) {
        return 1;
    }
    while (num > 0) {
        num /= 10;
        numDigits++;
    }
    
    return numDigits;
}

// Helper function to convert an octet to binary
void convertToBinary(int octet, int octetBinary[8]) {
    for (int i = 7; i >= 0; i--) {
        octetBinary[i] = octet % 2;
        octet /= 2;
    }
}

// Helper function to place each 8-bit octet binary into the 32-bit array
void combineAllOctets(int octetBinary[8], int pos, int binaryAllOctets[32]) {
    for (int i = 0; i < 8; i++) {
        binaryAllOctets[pos + i] = octetBinary[i];
    }
}

// Helper function to convert a 32-bit binary array to a decimal integer
long int convertBinaryToDecimal(int binaryAllOctets[32]) {
    long int decimalValue = 0;
    for (int i = 0; i < 32; i++) {
        decimalValue = (decimalValue << 1) | binaryAllOctets[i];
    }
    return decimalValue;
}
