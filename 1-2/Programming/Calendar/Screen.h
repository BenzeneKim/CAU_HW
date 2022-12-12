#pragma once
#include "main.h"


typedef struct terminalSize {
	int x;
	int y;
} termS;

extern termS termSize;

void View(Day ViewDay);
void ViewInit();
void ViewTitle(Day pointingDay);
void ViewDayIndex();
void ViewDate(Day viewDay);
void ViewTemplate();
void ViewSchedule();
void ViewHelp();
void SetConsoleSize();
void GotoXY(int x, int y);
void GetSize();
void PrintOnRight(char* txt, int row);
void PrintOnMiddle(char* txt, int row);
void PrintOnLeft(char* txt, int row);
void PrintOnCor(char* txt, int column, int row);
void HideCursor();