#include "main.h"
#include "Screen.h"
#include "CalendarBase.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define CALENDAR_X 20
#define CALENDAR_Y 20
CONSOLE_SCREEN_BUFFER_INFO csbi;

char* dayIndexTxt;

struct terminalSize {
	int x;
	int y;
} termSize;

void View(Day ViewDay) {
	ViewInit();
	ViewTitle(ViewDay.year, ViewDay.month);
	ViewDayIndex();
	ViewDate(ViewDay.month, CalculateMaxDate(ViewDay.year, ViewDay.month), CalculateStartDay(ViewDay.year, ViewDay.month), ViewDay.date);
}

void ViewInit() {
	system("cls");
	GetSize();
	strcpy(dayIndexTxt, "S  M  T  W  T  F  S");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN); //color reset
}

void ViewTitle(int year, int month) {
	char* title;
	strcat(title, MonthTxt[month]);
	strcat(title, " ");
	char* buffer;
	itoa(year, buffer, 4);
	strcat(title, buffer);
	PrintOnLeft(title, 4);
}

void ViewDayIndex() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	PrintOnMiddle(dayIndexTxt, 8);
}

void ViewDate(int month, int maxDate, int startDay, int pointingDay) {
	
}

void ViewCommand() {
	char* cmdTxt;
	strcpy(cmdTxt, "Command");
	PrintOnMiddle(cmdTxt, termSize.y);
}

void ViewSchedule(){

}



//printing scripts;
void GotoXY(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void GetSize() {
	termSize.x = csbi.srWindow.Right - csbi.srWindow.Left + 1; 
	termSize.y = csbi.srWindow.Top - csbi.srWindow.Bottom + 1;
}

void PrintOnRight(char* txt, int row) {
	GotoXY(termSize.x - strlen(txt), row);
	printf(txt);
}
void PrintOnMiddle(char* txt, int row) {
	GotoXY(termSize.x / 2 - strlen(txt) / 2, row);
	printf(txt);
}
void PrintOnLeft(char* txt, int row) {
	GotoXY(1, row);
	printf(txt);
}
