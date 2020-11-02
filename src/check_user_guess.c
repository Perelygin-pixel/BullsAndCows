#include "check_user_guess.h"
#include "constant.h"

#include <stdio.h>
#include <stdlib.h>

void Print_Bulls_And_Cows(int* bulls_and_cows, int* user_number, int attempt)
{
    printf("Attempt: %d\n", attempt);
    printf("Your number:");
    for (short int i = 0; i < QUANTITY_DIGIT_IN_NUMBER; i++) {
        printf("%d", user_number[i]);
    }
    printf("\nbulls: %d\ncows: %d\n",
           bulls_and_cows[INDEX_BULLS],
           bulls_and_cows[INDEX_COWS]);
}

int Check_Win(int bulls)
{
    if (bulls == QUANTITY_DIGIT_IN_NUMBER) {
        return 0;
    }
    return -1;
}

void Message_For_Exit(
        int* hidden_number, int number_of_attempt, int result_game)
{
    system("clear");
    if (result_game == WIN) {
        printf("You Win!\n");
    } else {
        printf("You Loose :(\n");
    }
    printf("Hidden number: ");
    for (short int i = 0; i < QUANTITY_DIGIT_IN_NUMBER; i++) {
        printf("%d", hidden_number[i]);
    }
    printf("\nIt took you %d attempts\n", number_of_attempt);
}

int* Check_User_Guess(int* bulls_and_cows, int* hidden_number, int* user_number)
{
    bulls_and_cows[INDEX_BULLS] = 0;
    bulls_and_cows[INDEX_COWS] = 0;
    for (short int i = 0; i < QUANTITY_DIGIT_IN_NUMBER; i++) {
        for (short int j = 0; j < QUANTITY_DIGIT_IN_NUMBER; j++) {
            if (hidden_number[i] == user_number[j]) {
                if (i == j) {
                    bulls_and_cows[INDEX_BULLS]++;
                } else {
                    bulls_and_cows[INDEX_COWS]++;
                }
            }
        }
    }
    return bulls_and_cows;
}