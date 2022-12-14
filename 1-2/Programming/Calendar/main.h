#pragma once
#include <Windows.h>
#include "Schedule.h"
typedef struct DayStructure {
	int year;			//year
	int month;			//month
	int date;			//date
	int wDay;			//which day in a week(this day) || sunday:0
	int leapYear;		//0:normal 1:leap
	int maxDate;		//28~31
	int startWDay;		//which day in a week(first of this month) || sunday:
}Day;

extern Day mainDay;
extern HANDLE consoleHandle;
extern CONSOLE_SCREEN_BUFFER_INFO csbi;

void Init();
void GetInput();
void GetDate();
void GetCommand();
void DontRefresh();
