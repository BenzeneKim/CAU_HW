#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "Schedule.h"
#include "main.h"

char* GetSchedule(Day pointingDay) {
	FILE* fpR;
    int isPressed;
	fopen_s(&fpR, "./Database.txt", "rt");
	if (fpR != NULL) {

        while (isPressed == 0) {
            if (kbhit()) {

            }
        }
        return getKey;
    }
	}
}

void SaveSchedule(Day pointingDay, char* inputSchedule) {

}