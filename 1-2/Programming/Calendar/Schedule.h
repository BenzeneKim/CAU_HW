#pragma once
#include "main.h"

typedef struct scheduleStruct {
	Day pointingDay;
	struct	tm time;
	char* contents;
} Schedule;

char* GetSchedule(Day pointingDay);
void SaveSchedule(Day pointingDay, char* inputSchedule);
