#include "Header.h"

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h> 
#include <conio.h>
#include <time.h>

int hossz, szel, counter;
int record[3] = {999,999,999};
char** beolvasPalya(const char* fajlNev)
{
	
	FILE* fin = fopen(fajlNev, "rt");
	if (!fin) {
		printf("Sikertelen");
		exit(1);
	}
	fscanf(fin, "%i%i\n", &hossz, &szel);
	char** palya = (char**)(calloc(hossz, sizeof(char*)));
	//ellenorzes
	for (int i = 0; i < hossz; ++i) {
		palya[i] = (char*)(calloc(szel, sizeof(char)));
	}
	for (int i = 0; i < hossz; ++i) {
		for (int j = 0; j < szel; ++j) {
			fscanf(fin, "%c\n", &palya[i][j]);
		}
	}
	return palya;
}

void kirajzolPalya(char** palya)
{
	for (int i = 0; i < hossz; ++i) {
		for (int j = 0; j < szel; ++j) {
			if (palya[i][j] == '3' && (i == 0 || i == hossz - 1)) {
				printf("%c",205);
			}
			else if (palya[i][j] == '3') {
				printf("%c",186);
			}
			if (palya[i][j] == '0') {
				printf(" ");
			}
			if (palya[i][j] == '1') {
				printf("%c",219);
			}
			if (palya[i][j] == 'R') {
				printf("X");
			}
			if (palya[i][j] == 'P') {
				printf("%c", 248);
			}
			if(palya[i][j] == '4')
				printf("%c", 201);
			if (palya[i][j] == '5')
				printf("%c", 187);
			if (palya[i][j] == '6')
				printf("%c", 188);
			if (palya[i][j] == '7')
				printf("%c", 200);
			if (palya[i][j] == '9')
				printf("%c", 178);
		}
		printf("\n");
	}
	//system("pause");
}

void startGame()
{
	printf("Start \nLevels \nExit \n");
	char task[30],lev;
	scanf("%s", task);
	char aux[30];
	for (int i = 0; i < strlen(task); i++)
	{
		aux[i] = toupper(task[i]);
	}
	if (strstr(aux, "START"))
	{
		//Start game 
		jatekMenet(1);
	}
	
	else if (strstr(aux, "LEVELS"))
	{
		//Show the levels
		printf("\t1. \n\t2. \n\t3. \n");
		lev = getch();
		switch (lev)
		{
		case '1':
			jatekMenet(1);
			break;
		case '2':
			jatekMenet(2);
			break;
		case '3':
			jatekMenet(3);
			break;
		}
	}
	else if (strstr(aux, "EXIT"))
	{
		//Exit Game 
		printf("Exit Game");
		exit(1);
	}
}

void jatekMenet(int level)
{
	
	system("cls");
	int index = 1;
	char** palya;
	palya = beolvasPalya("be.txt");
	switch (level)
	{
	case 1:
		palya = beolvasPalya("be.txt");
		break;
	case 2:
		palya = beolvasPalya("be2.txt");
		break;
	case 3:
		palya = beolvasPalya("be3.txt");
		break;
	default:
		printf("asd");
		break;
	}
	int elozoX, elozoY,gX,gY;
	int jatekosX = 1, jatekosY = 1;
	palya[jatekosX][jatekosY] = 'P';
	while (1) {
		printf("Press 'E' to return to homepage \n");
		printf("\tLevel %i\n",level);
		kirajzolPalya(palya);
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;
		switch (option)
		{
		case 'd':
			jatekosY++;
			if(palya[jatekosX][jatekosY]== '1' || palya[jatekosX][jatekosY] == '3' || palya[jatekosX][jatekosY] == '9')
				jatekosY--;
			break;
		case 's':
			jatekosX++;
			if (palya[jatekosX][jatekosY] == '1' || palya[jatekosX][jatekosY] == '3' || palya[jatekosX][jatekosY] == '9')
				jatekosX--;
			break;
		case 'w':
			jatekosX--;
			if (palya[jatekosX][jatekosY] == '1' || palya[jatekosX][jatekosY] == '3' || palya[jatekosX][jatekosY] == '9')
				jatekosX++;
			break;
		case 'a':
			jatekosY--;
			if (palya[jatekosX][jatekosY] == '1' || palya[jatekosX][jatekosY] == '3' || palya[jatekosX][jatekosY] == '9')
				jatekosY++;
			break;
		case '8':
			gX = jatekosX - 1;
			gY = jatekosY;
				if (palya[gX][gY] == '9') {
					palya[gX][gY] = '0';
					counter++;
				}
				system("CLS");
				kirajzolPalya(palya);
			break;
		case '5':
			gX = jatekosX + 1;
			gY = jatekosY;
			if (palya[gX][gY] == '9') {
				palya[gX][gY] = '0';
				counter++;
			}
			system("CLS");
			kirajzolPalya(palya);
			break;
		case '6':
			gX = jatekosX ;
			gY = jatekosY + 1;
			if (palya[gX][gY] == '9') 
			{
				palya[gX][gY] = '0';
				counter++;
			}
			system("CLS");
			kirajzolPalya(palya);
			break;
		case '4':
			gX = jatekosX ;
			gY = jatekosY - 1;
			if (palya[gX][gY] == '9') {
				palya[gX][gY] = '0';
				counter++;
			}
			system("CLS");
			kirajzolPalya(palya);
			break;
		}
		if (option == 'e')
		{
			system("cls");
			printf("Exit pressed\n");
			startGame();
			//break;
		}
		
		if (palya[jatekosX][jatekosY] == '0') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';
		}
		else if (palya[jatekosX][jatekosY] == 'R')
		{
			if (counter < record[level])
				record[level] = counter;
			//printf("%i kiuttessel sikerult a szint, a rekord %i\n", counter, record);
			goto endgame;
		}
		system("CLS");
	}
endgame: 
	{
		char* text = (char*)calloc(50, sizeof(char));
		char* aux = (char*)calloc(50, sizeof(char));
		system("CLS");
		printf("%i kiuttessel sikerult a szint, a rekord %i\n", counter, record[level]);
		level++;
		if (level <= 3)
		{
			printf("Next level\n");
		}
		else
		{
			printf("Teljesitett jatek\n");
		}
		printf("New Game\n");
		printf("Return home\n");
		scanf("%s", text);
		for (int i = 0; i < strlen(text); i++)
		{
			aux[i] = toupper(text[i]);
		}
		if (strstr(aux, "NEXT"))
		{
			counter = 0;
			jatekMenet(level);
		}
		else if (strstr(aux, "NEW"))
		{
			jatekMenet(1);
		}
		else if (strstr(aux, "RETURN"))
		{
			startGame();
		}
	}
}
