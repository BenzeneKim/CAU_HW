#pragma once
#include "main.h"

typedef struct scheduleStruct {
	Day pointingDay;
	char* contents;
} Schedule;

char* GetSchedule(Day pointingDay);
void SaveSchedule(Day pointingDay, char* inputSchedule);