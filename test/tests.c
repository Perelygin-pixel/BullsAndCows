#include "ctest.h"
#include "user_input.h"
#include "check_user_guess.h"

CTEST(USER_INPUT, CHECK_USER_WRITE_DIGIT)
{
    ASSERT_EQUAL(-1,Check_User_Write_Digit('g'));
    ASSERT_EQUAL(-1,Check_User_Write_Digit('!'));
    ASSERT_EQUAL(-1,Check_User_Write_Digit('\n'));
    ASSERT_EQUAL(-1,Check_User_Write_Digit('0'));
    ASSERT_EQUAL(1,Check_User_Write_Digit('1'));
    ASSERT_EQUAL(2,Check_User_Write_Digit('2'));
    ASSERT_EQUAL(3,Check_User_Write_Digit('3'));
    ASSERT_EQUAL(4,Check_User_Write_Digit('4'));
    ASSERT_EQUAL(5,Check_User_Write_Digit('5'));
    ASSERT_EQUAL(6,Check_User_Write_Digit('6'));
    ASSERT_EQUAL(7,Check_User_Write_Digit('7'));
    ASSERT_EQUAL(8,Check_User_Write_Digit('8'));
    ASSERT_EQUAL(9,Check_User_Write_Digit('9'));
}

CTEST(USER_INPUT, CHECK_DUPLICATE_DIGIT)
{
    int user_number_1[] = {9,2,5,1};
    int user_number_2[] = {1,3,4,7};
    int user_number_3[] = {1,1,4,7};
    int user_number_4[] = {1,2,2,7};
    int user_number_5[] = {4,1,6,4};
    int user_number_6[] = {1,3,4,3};
    ASSERT_EQUAL(9,Check_Duplicate_Digit(user_number_1));
    ASSERT_EQUAL(1,Check_Duplicate_Digit(user_number_2));
    ASSERT_EQUAL(0,Check_Duplicate_Digit(user_number_3));
    ASSERT_EQUAL(0,Check_Duplicate_Digit(user_number_4));
    ASSERT_EQUAL(0,Check_Duplicate_Digit(user_number_5));
    ASSERT_EQUAL(0,Check_Duplicate_Digit(user_number_6));
}

CTEST(CHECK_USER_GUESS, CHECK_WIN)
{
    ASSERT_EQUAL(-1,Check_Win(1));
    ASSERT_EQUAL(-1,Check_Win(5));
    ASSERT_EQUAL(0,Check_Win(4));
}