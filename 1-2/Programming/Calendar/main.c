#include <time.h>
#include <Windows.h>
#include "main.h"
#include "Screen.h"
#include "Schedule.h"
#include "CalendarBase.h"

Day mainDay;
Schedule ScheduleData[100];
LPCSTR consoleTitle = "Calendar";
CONSOLE_SCREEN_BUFFER_INFO csbi;
HANDLE consoleHandle;

time_t curr_t;
struct tm* curr_time;

int needToRefresh = 1;
void Init() {
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitleA(consoleTitle);
	SetConsoleSize();
	time(&curr_t);
	curr_time = localtime(&curr_t);
	mainDay.year = curr_time->tm_year + 1900;
	mainDay.month = curr_time->tm_mon + 1;
	mainDay.date = curr_time->tm_mday;

	//scheduleArr = (Schedule*)calloc(10, sizeof(Schedule*));
	GetSchedule(ScheduleData);
}

int main() {
	Init();
	while (1) {
		mainDay = CalcDay(mainDay);
		if (needToRefresh == 1)View(mainDay);
		else needToRefresh = 1;
		GetInput();
	}
}

void GetInput() {
	char inputChar;
	int isPressed = 0;
	while (isPressed == 0) {
		if (kbhit()) {
			inputChar = getch();
			isPressed = 1;
		}
	}
	switch (inputChar) {
	case ':':
		GetCommand();
		break;
	case '/':
		GetDate();
		break;
	case 75:
		//left
		if (mainDay.date == 1) {
			if (mainDay.month == 1) {
				mainDay.year--;
				mainDay.month = 12;
				mainDay.date = 31;
				break;
			}
			else {
				mainDay.month--;
				mainDay.date = 1; //init day to calculate max date
				mainDay.date = CalculateMaxDate(mainDay);
				break;
			}
		}
		else mainDay.date--;
		break;
	case 77:
		//right
		if (mainDay.date == mainDay.maxDate) {
			if (mainDay.month == 12) {
				mainDay.year++;
				mainDay.month = 1;
				mainDay.date = 1;
				break;
			}
			else {
				mainDay.month++;
				mainDay.date = 1; //init day to calculate max date
				break;
			}
		}
		else mainDay.date++;
		break;
	case 72:
		//up
		if (mainDay.date < 8) {
			if (mainDay.month == 1) {
				mainDay.year--;
				mainDay.month = 12;
				mainDay.date = 31 - 7 + mainDay.date;
				break;
			}
			else {
				mainDay.month--;
				mainDay.date = CalculateMaxDate(mainDay) - 7 + mainDay.date;
				break;
			}
		}
		else mainDay.date -= 7;
		break;
	case 80:
		//down
		if (mainDay.maxDate - mainDay.date < 7) {
			if (mainDay.month == 12) {
				mainDay.year++;
				mainDay.month = 1;
				mainDay.date = 7 + mainDay.date - mainDay.maxDate;
				break;
			}
			else {
				mainDay.month++;
				mainDay.date = 7 + mainDay.date - mainDay.maxDate;
				break;
			}
		}
		else mainDay.date += 7;
		break;


	}
}

void GetCommand() {
	char* cmdStr = (char*)calloc(12,sizeof(char));
	char inputC = NULL;
	strcpy(cmdStr, ":");
	PrintOnLeft(cmdStr, termSize.y - 2);
	while (inputC!='\r' && strlen(cmdStr) > 0 ){
		int isPressed = 0;
		while (isPressed == 0) {
			if (kbhit()) {
				inputC = getch();
				isPressed = 1;
			}
		}
		if (inputC == '\b') {
			if (strlen(cmdStr) > 1) {
				int len = strlen(cmdStr);
				cmdStr[len - 1] = '\0';
				cmdStr[len] = NULL;
			}
			else strcpy(cmdStr, "");
		}
		else {
			char buffer[2];
			buffer[0] = inputC;
			buffer[1] = '\0';
			strcat(cmdStr, buffer);
		}
		char* temp = (char*)calloc(12, sizeof(char));
		strcpy(temp, cmdStr);
		strcat(temp, " ");
		PrintOnLeft(temp, termSize.y - 2);
		free(temp);
	}
	switch (cmdStr[1]) {
	case NULL:
		break;
	case 'h':
		ViewHelp();
		DontRefresh();
		break;
	case 'q':
		free(ScheduleData);
		free(cmdStr);
		exit(0);
		break;
	default:
		break;
	}
	free(cmdStr);
}
void GetDate() {
	char* cmdStr = (char*)calloc(10, sizeof(char));
	char inputFormat[10] = "/yyyymmdd";
	char emptyStr[10] = "         ";
	char inputC = NULL;
	strcpy(cmdStr, inputFormat);
	PrintOnLeft(cmdStr, termSize.y - 2);
	int indexTxt = 1;
	while (inputC != '\r' && indexTxt > 0) {
		int isPressed = 0;
		while (isPressed == 0) {
			if (kbhit()) {
				inputC = getch();
				isPressed = 1;
			}
		}
		if (inputC == '\b') {
			cmdStr[indexTxt - 1] = inputFormat[indexTxt - 1];
			indexTxt--;
		}
		else {
			if (isdigit(inputC)) {
				cmdStr[indexTxt] = inputC;
				indexTxt++;
			}
		}
		PrintOnLeft(cmdStr, termSize.y - 2);
	}
	if (indexTxt == 9) {
		char yearTxt[5];
		char monthTxt[3];
		char dayTxt[3];
		for (int i = 0; i < 4; i++) {
			yearTxt[i] = cmdStr[i + 1];
		}
		for (int i = 0; i < 2; i++) {
			monthTxt[i] = cmdStr[i + 5];
			dayTxt[i] = cmdStr[i + 7];
		}
		yearTxt[4] = '\0';
		monthTxt[2] = '\0';
		dayTxt[2] = '\0';

		mainDay.year = atoi(yearTxt);
		mainDay.month = atoi(monthTxt);
		mainDay.date = atoi(dayTxt);
	}
	strcpy(cmdStr, emptyStr);
	PrintOnLeft(cmdStr, termSize.y - 2);
	free(cmdStr);
}
void DontRefresh() {
	needToRefresh = 0;
}