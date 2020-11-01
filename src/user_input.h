#ifndef USER_INPUT_H

#define USER_INPUT_H

char* Get_User_Attempt(char* user_data_input);
int* Convert_User_String_To_Integer(int* user_number, char* user_data_input);
int Check_User_Write_Digit(char symbol);
int Check_Duplicate_Digit(int* user_number);

#endif