#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "main.h"
#include "Screen.h"
#include "CalendarBase.h"
#include "Schedule.h"

#define CALENDAR_X 20
#define CALENDAR_Y 20
extern CONSOLE_SCREEN_BUFFER_INFO csbi;


const char MonthTxt[][4] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

extern Schedule ScheduleData[100];
termS termSize;

void View(Day ViewDay) {
	ViewInit();
	ViewTemplate();
	ViewTitle(ViewDay);
	ViewDayIndex();
	ViewDate(ViewDay);
	ViewSchedule(ViewDay);
}

void ViewInit() {
	SetConsoleTextAttribute(consoleHandle, 0x000f); //color reset
	system("cls");
	GetSize();
}

void ViewTitle(Day pointingDay) {
	char* title;
	title = (char*)calloc(12, sizeof(char));
	strcat(title, MonthTxt[pointingDay.month-1]);
	strcat(title, " ");
	char buffer[5];
	itoa(pointingDay.year, buffer, 10);
	strcat(title, buffer);
	PrintOnMiddle(title, 4);
}

void ViewDayIndex() {
	char* dayIndexTxt;
	dayIndexTxt = (char*)calloc(strlen("Sun      Mon      Tue      Wen      Thu      Fri      Sat")+2, sizeof(char));
	strcpy(dayIndexTxt, "Sun      Mon      Tue      Wen      Thu      Fri      Sat");
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	PrintOnMiddle(dayIndexTxt, 8);
	free(dayIndexTxt);
}

void ViewDate(Day viewDay) {
	int viewingDate = 1;
	int wDayIndex = viewDay.startWDay;
	int corX, corY;
	char* dateText;
	dateText = (char*)calloc(10, sizeof(char));
	corY = 10;
	corX = 45 + 9 * viewDay.startWDay;
	while (viewingDate <= viewDay.maxDate) {
		if (viewingDate == viewDay.date) SetConsoleTextAttribute(consoleHandle, 0x80f0);
		else SetConsoleTextAttribute(consoleHandle, 0x000f);
		itoa(viewingDate, dateText, 10);
		PrintOnCor(dateText, corX - strlen(dateText), corY);
		if (wDayIndex == 6) {
			wDayIndex = 0;
			corY += 2;
		}
		else wDayIndex += 1;
		corX = 45 + 9 * wDayIndex;
		viewingDate++;
	}
	free(dateText);
}

void ViewTemplate() {
	char* buffer;
	buffer = (char*)calloc(200, sizeof(char*));
	strcpy(buffer, "= COMMAND ===================================================================================================================================");
	PrintOnMiddle(buffer, termSize.y - 4);
	free(buffer);
	buffer = (char*)calloc(2, sizeof(char*));
	strcpy(buffer, "|");
	for (int i = 1; i < termSize.y - 1; i++) {
		PrintOnCor(buffer, termSize.x - 59, i);
	}
	free(buffer);
	buffer = (char*)calloc(strlen("Schedule"),sizeof(char*));
	strcpy(buffer, "Schedule");
	PrintOnCor(buffer, termSize.x - 56, 2);
	free(buffer);
	buffer = (char*)calloc(strlen("= Help ============================================"), sizeof(char*));
	strcpy(buffer, "= Help ============================================");
	PrintOnCor(buffer, termSize.x - 57, 30);
	free(buffer);
}

void ViewSchedule(Day pointingDay){
	char* buffer;
	buffer = (char*)calloc(5, sizeof(char*));
	if (ScheduleData != NULL)
		itoa(ScheduleData[0].year, buffer, 10);
	else strcpy(buffer, "NULL");
	PrintOnCor(buffer, termSize.x - 56, 4);
}

void ViewHelp() {
	char* buffer;
	buffer = (char*)calloc(strlen(":q : exit"), sizeof(char*));
	strcpy(buffer, ":q : exit");
	PrintOnCor(buffer, termSize.x - 56, 32);
	free(buffer);
}

void SetConsoleSize() {
	system("mode con:cols=200 lines=50");
	system("cls");
	/*
	SMALL_RECT rect = { 0,0,400,300 };
	COORD csbiSize{ 400,300 };

	SetConsoleScreenBufferSize(consoleHandle, csbiSize);
	SetConsoleWindowInfo(consoleHandle, 0, &rect);*/
}

//printing scripts;
void GotoXY(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(consoleHandle, Pos);
}
void GetSize() {
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);
	termSize.x = csbi.srWindow.Right - csbi.srWindow.Left + 1; 
	termSize.y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	GotoXY(1, 1);
}

void PrintOnRight(char* txt, int row) {
	GotoXY(termSize.x - strlen(txt) - 30, row);
	printf(txt);
	HideCursor();
	
}
void PrintOnMiddle(char* txt, int row) {
	GotoXY(termSize.x / 2 - strlen(txt) / 2 - 30, row);
	printf(txt);
	HideCursor();
}
void PrintOnLeft(char* txt, int row) {
	GotoXY(1, row);
	printf(txt);
	HideCursor();
}

void PrintOnCor(char* txt, int column, int row) {
	GotoXY(column, row);
	printf(txt);
	HideCursor();
}

void HideCursor() {
	CONSOLE_CURSOR_INFO info; info.dwSize = 20;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}