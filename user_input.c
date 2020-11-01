#include "user_input.h"
#include "constant.h"

#include <stdio.h>
#include <stdlib.h>

char* Get_User_Attempt(char* user_data_input)
{
    user_data_input = (char*)calloc(QUANTITY_DIGIT_IN_NUMBER, sizeof(char));
    if (user_data_input == NULL) {
        return NULL;
    }
    fread(user_data_input, sizeof(char), QUANTITY_DIGIT_IN_NUMBER, stdin);
    for (short int i = 0; i < QUANTITY_DIGIT_IN_NUMBER; i++) {
        if (user_data_input[i] == '\n') {
            return user_data_input;
        }
    }
    while (getchar() != '\n')
        ;
    return user_data_input;
}

int Check_User_Write_Digit(char symbol)
{
    for (short int i = 1; i < INTERVAL_FROM_ONE_TO_NINE + 1; i++) {
        if (symbol == '0' + i) {
            return i;
        }
    }
    return -1;
}

int Check_Duplicate_Digit(int* user_number)
{
    for (short int i = 0; i < QUANTITY_DIGIT_IN_NUMBER; i++) {
        for (short int j = i + 1; j < QUANTITY_DIGIT_IN_NUMBER; j++) {
            if (user_number[i] == user_number[j]) {
                return 0;
            }
        }
    }
    return user_number[0];
}

int* Convert_User_String_To_Integer(int* user_number, char* user_data_input)
{
    user_number = (int*)calloc(QUANTITY_DIGIT_IN_NUMBER, sizeof(int));
    if (user_number == NULL) {
        return NULL;
    }
    for (short int i = 0; i < QUANTITY_DIGIT_IN_NUMBER; i++) {
        user_number[i] = Check_User_Write_Digit(user_data_input[i]);
        if (user_number[i] == -1) {
            user_number[0] = 0;
            return user_number;
        }
    }
    user_number[0] = Check_Duplicate_Digit(user_number);
    return user_number;
}