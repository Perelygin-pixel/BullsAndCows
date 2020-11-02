#ifndef CHECK_USER_GUESS_H

#define CHECK_USER_GUESS_H

void Print_Bulls_And_Cows(int* bulls_and_cows, int* user_number, int attempt);
void Message_For_Exit(
        int* hidden_number, int number_of_attempt, int result_game);
int Check_Win(int bulls);
int* Check_User_Guess(int* bulls_and_cows, int* hidden_number, int* user_number);

#endif