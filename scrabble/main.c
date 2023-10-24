//
// Created by gabriel on 24/10/23.
//
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

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

int compute_score(char word[]);

int main(void) {
    const int LENGTH_WORD = 700;
    // Get input words from both players
    char word1[LENGTH_WORD];
    printf("Player 1: ");
    setbuf(stdin, NULL);
    fgets(word1, 700, stdin);

    char word2[LENGTH_WORD];
    printf("Player 2: ");
    setbuf(stdin, NULL);
    fgets(word2, 700, stdin);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    if (score1 > score2) {
        printf("Player 1 wins!");
    } else if (score2 > score1) {
        printf("Player 2 wins!");

    } else {
        printf("Tie!");
    }

    // TODO: Print the winner
}

int compute_score(char word[]) {
    // TODO: Compute and return score for string
    int score = 0;
    for (int i = 0; i < strlen(word); i++) {
        int position = findLetter(word[i]);
        if (position != -1) {
            score += POINTS[position];
        }
    }
    return score;
}