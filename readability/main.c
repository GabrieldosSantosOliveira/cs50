//
// Created by gabriel on 24/10/23.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

const int LENGTH_TEXT_ARRAY = 700;

int main() {
    char text[LENGTH_TEXT_ARRAY];
    do {
        printf("Text: ");
        fgets(text, LENGTH_TEXT_ARRAY, stdin);
    } while ((strlen(text) - 1) <= 0);

    int letters = 0;
    int spaces = 0;
    int sentences = 0;
    for (int i = 0; i < strlen(text) - 1; i++) {
        char letter = text[i];
        if (isupper(letter) || islower(letter)) {
            letters++;
        }
        if (isspace(letter)) {
            spaces++;
        }
        if (letter == '.' || letter == '!' || letter == '?') {
            sentences++;
        }
    }
    int words = spaces + 1;
    double L = (letters * 100.0) / words;
    double S = (sentences * 100.0) / words;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    if (index >= 16) {
        printf("Grade 16+\n");
    } else if (index < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade: %d \n", (int) round(index));
    }

    return 0;
}