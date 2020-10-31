#include "generate_number.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* Generation_Hidden_Number(int* hidden_number)
{
	int* array_digit = NULL;
	array_digit = (int*)calloc(INTERVAL_FROM_ONE_TO_NINE,sizeof(int));
	hidden_number = (int*)calloc(QUANTITY_DIGIT_IN_NUMBER,sizeof(int));
	if(hidden_number == NULL || array_digit == NULL)
	{
		return NULL;
	}
	for(short int i = 0; i < INTERVAL_FROM_ONE_TO_NINE; i++)
	{
		array_digit[i] = i+1;
	}
	for(short int i = 0, j = 0; i < 4; i++)
	{
		j = rand()%10;
		if(array_digit[j] != 0)
		{
			hidden_number[i] = array_digit[j];
			array_digit[j] = 0;
		}
		else
		{
			i--;
		}
	}
	free(array_digit);
	array_digit = NULL;
	return hidden_number;
}