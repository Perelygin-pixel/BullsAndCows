#include "constant.h"
#include "generate_number.h"
#include "user_input.h"
#include "check_user_guess.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int* hidden_number = NULL;
    int* user_number = NULL;
    int* bulls_and_cows = NULL;
    char* user_data_input = NULL;
    int number_attempt = 1;
    srand(time(NULL));
    bulls_and_cows = (int*)calloc(SIZE_ARRAY_BULLS_AND_COWS, sizeof(int));
    if (bulls_and_cows == NULL) {
        printf("Error: fail memory allocation for bulls and cows\n");
        return 4;
    }
    hidden_number = Generation_Hidden_Number(hidden_number);
    if (hidden_number == NULL) {
        printf("Error: couldn't generate a number\n");
        return 1;
    }
    do {
        printf("Attempt: %d\n", number_attempt);
        user_data_input = Get_User_Attempt(user_data_input);
        if (strcmp(user_data_input, "exit\0") == 0) {
            Message_For_Exit(hidden_number, number_attempt, LOOSE);
            return 0;
        }
        user_number
                = Convert_User_String_To_Integer(user_number, user_data_input);
        if (user_number == NULL) {
            printf("Error: invalid number entered\n");
            return 2;
        }
        if (user_number[0] == 0) {
            printf("You input data incorrect\n");
            printf("Example correct input data: 1234\n");
            continue;
        }
        bulls_and_cows
                = Check_User_Guess(bulls_and_cows, hidden_number, user_number);
        if (bulls_and_cows == NULL) {
            printf("Error: couldn't get quantity of bulls and cows\n");
            return 3;
        }
        if (Check_Win(bulls_and_cows[INDEX_BULLS]) == 0) {
            Message_For_Exit(hidden_number, number_attempt, WIN);
            return 0;
        } else {
            Print_Bulls_And_Cows(bulls_and_cows, user_number, number_attempt);
        }
        number_attempt++;
    } while (number_attempt < MAX_QUANTITY_ATTEMPT);
    return 4;
}