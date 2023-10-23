//
// Created by gabriel on 22/10/23.
//
#include <stdio.h>

int getStartSize() {
    int startSize;
    do {
        printf("Start size: ");
        scanf("%d", &startSize);
    } while (startSize < 9);
    return startSize;
}

int getEndSize(int min) {
    int endSize;
    do {
        printf("End size: ");
        scanf("%d", &endSize);
    } while (endSize < 1 || endSize < min);
    return endSize;
}

int main() {
    int startSize = getStartSize();
    int endSize = getEndSize(startSize);
    int years = 0;
    while (startSize < endSize) {
        years++;
        startSize = startSize + (startSize / 3) - (startSize / 4);
    }
    printf("Years: %d", years);
    return 0;
}
