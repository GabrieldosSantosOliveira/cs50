
//
// Created by gabriel on 22/10/23.
//
#include <stdio.h>

int getSize() {
    int size;
    do {
        printf("Tamanho: ");
        scanf("%d", &size);
    } while (size < 1 || size > 8);
    return size;
}

int main() {
    int size = getSize();
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            int emptySpace = ((i + 1) - size) * -1;
            if (k < emptySpace) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf(" ");
        for (int k = 0; k < i + 1; k++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;

}