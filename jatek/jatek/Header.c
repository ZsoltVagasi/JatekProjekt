#include "Header.h"

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h> 
#include <conio.h>

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
				printf("_");
			}
			else if (palya[i][j] == '3') {
				printf("|");
			}
			if (palya[i][j] == '0') {
				printf(" ");
			}
			if (palya[i][j] == '1') {
				printf("*");
			}
			if (palya[i][j] == 'R') {
				printf("X");
			}
			if (palya[i][j] == 'P') {
				printf("O");
			}
		}
		printf("\n");
	}
	system("pause");
}

char** generalPalya(char** palya)
{
	return NULL;
}

void jatekMenet()
{
	time_t currentTime, startTime;
	startTime = time(NULL);
	int index = 1;
	char** palya;
	palya = beolvasPalya("be.txt");
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya[jatekosX][jatekosY] = 'P';
	while (1) {
		currentTime = time(NULL);
		printf("jobb: d\nle: s\nbal: a\nfel: w\n");
		kirajzolPalya(palya);
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;
		switch (option)
		{
		case 'd':
			jatekosY++;
			break;
		case 's':
			jatekosX++;
			break;
		case 'w':
			jatekosX--;
			break;
		case 'a':
			jatekosY--;
			break;
		}
		if (palya[jatekosX][jatekosY] == '0') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';
		}
		else if (palya[jatekosX][jatekosY] == 'R')
		{
			printf("Grat");
			break;
		}
		//Sleep(300);
		system("CLS");
		//	if (currentTime - startTime > 10) {
		//		printf("Time limit exceeded!\n Game over\n");
		//		break;
		//}
	}
}
