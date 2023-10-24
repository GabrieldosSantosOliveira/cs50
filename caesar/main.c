//
// Created by gabriel on 24/10/23.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (!isdigit(argv[1][i])) {
            printf("Key need to be a number\n");
            return 1;
        }
    }

    do {
        printf("Plaintext: ");
        fgets(plaintext, LENGTH_ARRAY_PLAINTEXT, stdin);
    } while (strlen(plaintext) <= 0);


    int key = (int) strtol(argv[1], NULL, 10);
    char ciphertext[LENGTH_ARRAY_CIPHERTEXT];
    const int LENGTH_ALPHABET = strlen(alphabet);

    for (int i = 0; i < strlen(plaintext); i++) {
        int isLowerCase = islower(plaintext[i]);
        int positionLetterInAlphabet = findLetter(plaintext[i]);
        if (positionLetterInAlphabet == -1) {
            ciphertext[i] = plaintext[i];
        } else {
            int newPosition = positionLetterInAlphabet + key;
            if (isLowerCase) {
                ciphertext[i] = tolower(alphabet[newPosition % LENGTH_ALPHABET]);
            } else {
                ciphertext[i] = alphabet[newPosition % LENGTH_ALPHABET];
            }
        }
    }
    printf("%s\n", ciphertext);
    return 0;
}