#include "constant.h"
#include "generate_number.h"
#include "user_input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int* hidden_number = NULL;
    int* user_number = NULL;
    char* user_data_input = NULL;
    int number_attempt = 1;
    srand(time(NULL));
    hidden_number = Generation_Hidden_Number(hidden_number);
    if (hidden_number == NULL) {
        printf("Error: couldn't generate a number\n");
        return 1;
    }
    do {
        printf("Attempt: %d\n", number_attempt);
        user_data_input = Get_User_Attempt(user_data_input);
        if (strcmp(user_data_input, "exit\0") == 0) {
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
        number_attempt++;
    } while (number_attempt < MAX_QUANTITY_ATTEMPT);
    return 3;
}