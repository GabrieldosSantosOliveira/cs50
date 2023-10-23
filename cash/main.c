//
// Created by gabriel on 22/10/23.
//
#include <stdio.h>

int getCash() {
    float cash;
    do {
        printf("How much change is owned: ");
        scanf("%f", &cash);
    } while (cash < 0);
    return (int) (cash * 100);
}

int main() {
    int cash = getCash();
    int coins = 0;
    int totalOfTwentyFiveCoins = 0;
    int totalOfTenCoins = 0;
    int totalOfFiveCoins = 0;
    int totalOfOneCoins = 0;
    while (cash >= 25) {
        cash -= 25;
        totalOfTwentyFiveCoins++;
        coins++;
    }
    while (cash >= 10) {
        cash -= 10;
        totalOfTenCoins++;
        coins++;
    }
    while (cash >= 5) {
        cash -= 5;
        totalOfFiveCoins++;
        coins++;
    }
    while (cash >= 1) {
        cash -= 1;
        totalOfOneCoins++;
        coins++;
    }

    printf("Total change coins: %d\n", coins);
    printf("Total 25 cent coins: %d\n", totalOfTwentyFiveCoins);
    printf("Total 10 cent coins: %d\n", totalOfTenCoins);
    printf("Total 5 cent coins: %d\n", totalOfFiveCoins);
    printf("Total 1 cent coins: %d\n", totalOfOneCoins);

    return 0;
}