#include <stdlib.h>
#include <string.h>
#include "Schedule.h"
#include "main.h"

char* GetSchedule(Day pointingDay) {
	char* pointingSchedule = (char*)calloc(12, sizeof(char));
	strcpy(pointingSchedule, "schedule");
	free(pointingSchedule);
	return pointingSchedule;
}

void SaveSchedule(Day pointingDay, char* inputSchedule) {

}