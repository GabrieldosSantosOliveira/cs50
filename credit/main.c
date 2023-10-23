//
// Created by gabriel on 22/10/23.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long getCreditCardNumber() {
    long creditCardNumber;
    do {
        printf("Number o credit card: ");
        scanf("%ld", &creditCardNumber);
    } while (creditCardNumber < 0);
    return creditCardNumber;
}

int main() {
    long creditCardNumber = getCreditCardNumber();
    char creditCarNumberInString[20];

    sprintf(creditCarNumberInString, "%ld", creditCardNumber);
    long checkSum;
    for (int i = 0; i < strlen(creditCarNumberInString); i++) {
        char string[2];
        string[0] = creditCarNumberInString[i];
        char middle[3];
        if (i == 0) {
            checkSum = strtol(string, NULL, 10) * 2;
        } else if ((i + 1) % 2 == 1) {
            sprintf(middle, "%ld", strtol(string, NULL, 10) * 2);
            for (int k = 0; k < strlen(middle); k++) {
                char transition[2];
                transition[0] = middle[k];
                checkSum += strtol(transition, NULL, 10);
            }
        } else {
            checkSum += strtol(string, NULL, 10);
        }
    }
    if (checkSum % 10 != 0) {
        printf("INVALID");
        return 1;
    }
    char firstTwoDigits[2];
    firstTwoDigits[0] = creditCarNumberInString[0];
    firstTwoDigits[1] = creditCarNumberInString[1];

    long amexOrMastercard = strtol(firstTwoDigits, NULL, 10);

    if ((amexOrMastercard == 34 || amexOrMastercard == 37) && strlen(creditCarNumberInString) == 15) {
        printf("AMEX\n");
    }

    if ((amexOrMastercard == 51 || amexOrMastercard == 52 || amexOrMastercard == 53 || amexOrMastercard == 54 ||
         amexOrMastercard == 55) && strlen(creditCarNumberInString) == 16) {
        printf("MASTERCARD\n");
    }

    if ((strlen(creditCarNumberInString) == 13 || strlen(creditCarNumberInString) == 16) &&
        creditCarNumberInString[0] == '4') {
        printf("VISA\n");
    }

    return 0;
}