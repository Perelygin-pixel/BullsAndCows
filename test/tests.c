#include "ctest.h"
#include "user_input.h"

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