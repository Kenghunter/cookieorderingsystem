#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

int NumberChecker(char* quantity)
{
	int isChar = 0;
	char num[] = { '0','1','2','3','4','5','6','7','8','9' };

	for (char index = 0;index < (unsigned)strlen(quantity);index++)
	{
		if (quantity[index] == '.')
		{
			continue;
		}

		isChar = 1;
		for (int innercheck = 0;innercheck < 11;innercheck++)
		{
			if (isChar > 0)
			{
				if (quantity[index] == num[innercheck])
				{
					isChar = 0;
					break;
				}
			}
		}
	}

	if (isChar > 0)
	{
		return -1;
	}

	return 1;
}



int askQues(char* question)
{
	int response = 0;
	char reply[900];


	response = 0;
	goto ask;

ask:
	printf(question);
	rewind(stdin);
	scanf("%s", &reply);
	goto checkresponse;

checkresponse:
	while (stricmp(reply, "y") != 0 && stricmp(reply, "n") != 0)
	{
		goto ask;
	};
	goto evaluate;



evaluate:
	if (stricmp(reply, "y") == 0)
	{
		return 1;
	}

	return 0;
}
