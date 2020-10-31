#include "generate_number.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int* hidden_number = NULL;
	srand(time(NULL));
	hidden_number = Generation_Hidden_Number(hidden_number);
	if(hidden_number == NULL)
	{
		printf("Error: couldn't generate a number\n");
		return 1;
	}
    return 0;
}