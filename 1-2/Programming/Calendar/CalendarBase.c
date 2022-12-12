#include "CalendarBase.h"
#include "main.h"
#include "Schedule.h"

Day CalcDay(Day dayToCalculate) {
	dayToCalculate.leapYear = IsLeapYear(dayToCalculate.year);
	dayToCalculate.maxDate = CalculateMaxDate(dayToCalculate);
	dayToCalculate.startWDay = CalculateStartWDay(dayToCalculate);
	dayToCalculate.schedule = GetSchedule(dayToCalculate);
	return dayToCalculate;
}

int IsLeapYear(int year) {
	if (year % 400 == 0) return 1;
	else if (year % 100 == 0) return 0;
	else if (year % 4 == 0) return 1;
	else return 0;
}

int CalculateMaxDate(Day pointingDay) {
	switch (pointingDay.month) {
	case 1:
		return 31;
		break;
	case 2:
		if (pointingDay.leapYear == 0) return 28;
		else return 29;
		break;
	case 3:
		return 31;
		break;
	case 4:
		return 30;
		break;
	case 5:
		return 31;
		break;
	case 6:
		return 30;
		break;
	case 7:
		return 31;
		break;
	case 8:
		return 31;
		break;
	case 9:
		return 30;
		break;
	case 10:
		return 31;
		break;
	case 11:
		return 30;
		break;
	case 12:
		return 31;
		break;
	default:
		return 0;
		break;
	}
}
int CalculateStartWDay(Day pointingDay) {
	int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int index = 0;
	int count = 0;
	int sumDays = 0;

	while (count != pointingDay.year) {
		count++;
		if (IsLeapYear(count - 1) == 1) {
			index++;
			index++;
		}
		else {
			index++;
		}
	}

	for (int i = 0; i < pointingDay.month - 1; i++) {
		sumDays += months[i];
	}
	sumDays--;

	return sumDays % 7;
}