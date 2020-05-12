#include "Header.h"

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h> 
#include <conio.h>
#include <string.h>

int main()
{
	printf("Start \nExit \n");
	char task[30];
	scanf("%[^\n]", task);
	char aux[30];
	for (int i = 0; i < strlen(task); i++)
	{
		aux[i] = toupper(task[i]);
	}
	if (strstr(aux, "START"))
	{
		//Start game 
		jatekMenet();
	}
	else if (strstr(aux, "EXIT"))
	{
		//Exit Game 
		printf("Exit Game");
		return 0;
	}
}