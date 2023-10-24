//
// Created by gabriel on 24/10/23.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int LENGTH_ARRAY_PLAINTEXT = 700;
const int LENGTH_ARRAY_CIPHERTEXT = 700;

const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int findLetter(char character) {
    char letter = toupper(character);
    for (int i = 0; i < strlen(alphabet); i++) {
        if (letter == alphabet[i]) {
            return i;
        }
    }
    return -1;
}


int main(int argc, char *argv[]) {
    char plaintext[LENGTH_ARRAY_PLAINTEXT];
    if (argv[1] == NULL) {
        printf("Key is required\n");
        return 1;
    }
    if (strlen(argv[1]) != 26) {
        printf("Key need to be 26 letters\n");
        return 1;
    }

    do {
        printf("Plaintext: ");
        fgets(plaintext, LENGTH_ARRAY_PLAINTEXT, stdin);
    } while (strlen(plaintext) <= 0);


    char ciphertext[LENGTH_ARRAY_CIPHERTEXT];
    for (int i = 0; i < strlen(plaintext); i++) {
        int isLowerCase = islower(plaintext[i]);
        int positionLetterInAlphabet = findLetter(plaintext[i]);
        if (positionLetterInAlphabet == -1) {
            ciphertext[i] = plaintext[i];
        } else {
            if (isLowerCase) {
                ciphertext[i] = tolower(argv[1][positionLetterInAlphabet]);
            } else {
                ciphertext[i] = argv[1][positionLetterInAlphabet];
            }
        }
    }
    printf("%s\n", ciphertext);
    return 0;
}