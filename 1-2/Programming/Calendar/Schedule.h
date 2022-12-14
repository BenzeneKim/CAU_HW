#pragma once
#include "main.h"

typedef struct scheduleStruct {
	int year;
	int month;
	int date;
	int hour;
	int minute;
	char contents[500];
} Schedule;
void GetSchedule(Schedule scheduleArr[]);
void eraseStrFL(char* targetS, int times);