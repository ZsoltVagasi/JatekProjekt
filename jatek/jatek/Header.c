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
				printf("-");
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
				printf("P");
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
	//kirajzolPalya(palya);
	while (1) {
		currentTime = time(NULL);
		kirajzolPalya(palya);
		printf("jobb: j\nle: l\n bal: b\n fel: f\n");
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;
		if (option == 'j') {
			jatekosY++;
		}
		else if (option == 'l') {
			jatekosX++;
		}
		if (palya[jatekosX][jatekosY] == '0') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';
		}
		//Sleep(300);
		system("CLS");
		//	if (currentTime - startTime > 10) {
		//		printf("Time limit exceeded!\n Game over\n");
		//		break;
		//}
	}
}
