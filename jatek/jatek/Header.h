#pragma once
#ifndef HEADER_H
#define HHEADER_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h> 
#include <conio.h>

char** beolvasPalya(const char* fajlNev);
void kirajzolPalya(char** palya);
char** generalPalya(char** palya);
void jatekMenet();
void jatekVege();


#endif // !1
