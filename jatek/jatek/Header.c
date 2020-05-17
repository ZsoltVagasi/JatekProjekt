#include "Header.h"

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h> 
#include <conio.h>
#include <time.h>

int hossz, szel;

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
			if (palya[i][j] == 'G')
				printf("G");

		}
		printf("\n");
	}
	//system("pause");
}

void startGame()
{
	printf("Start \nExit \n");
	char task[30];
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
	/*time_t currentTime, startTime;
	startTime = time(NULL);*/
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
	default:
		printf("asd");
		break;
	}
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya[jatekosX][jatekosY] = 'P';
	while (1) {
		//currentTime = time(NULL);
		printf("Pause: P\n");
		printf("\tLevel %i\n",level + 1);
		kirajzolPalya(palya);
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;
		switch (option)
		{
		case 'd':
			jatekosY++;
			if(palya[jatekosX][jatekosY]== '1' || palya[jatekosX][jatekosY] == '3')
				jatekosY--;
			break;
		case 's':
			jatekosX++;
			if (palya[jatekosX][jatekosY] == '1' || palya[jatekosX][jatekosY] == '3')
				jatekosX--;
			break;
		case 'w':
			jatekosX--;
			if (palya[jatekosX][jatekosY] == '1' || palya[jatekosX][jatekosY] == '3')
				jatekosX++;
			break;
		case 'a':
			jatekosY--;
			if (palya[jatekosX][jatekosY] == '1' || palya[jatekosX][jatekosY] == '3')
				jatekosY++;
			break;
		}
		if (palya[jatekosX][jatekosY] == '0') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';
		}
		else if (palya[jatekosX][jatekosY] == 'R')
		{
			goto endgame;
		}
		//Sleep(300);
		system("CLS");
		//	if (currentTime - startTime > 10) 
		//		{
		//		printf("Time limit exceeded!\n Game over\n");
		//		break;
		//		}
	}
endgame: 
	level++;
	char* text = (char*)calloc(50, sizeof(char));
	char* aux = (char*)calloc(50, sizeof(char));
	system("CLS");
	if (level <= 3)
	{
		printf("	Next level\n");
	}
	else
	{
		printf("	Teljesitett jatek\n");
	}
	printf("	New Game\n");
	printf("	Return home\n");
	scanf("%s", text);
	for (int i = 0; i < strlen(text); i++)
	{
		aux[i] = toupper(text[i]);
	}
	if (strstr(aux, "NEXT"))
	{
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
