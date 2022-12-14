#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "Schedule.h"
#include "main.h"


/*====database format
#n
yyyymmddhhmm   (date)(time)
schedule txt

#n+1
.
.
.
*/
void GetSchedule(Schedule* scheduleArr) {
	FILE* fpR;
	int	scheduleNum;
	char txtBuffer[10000];
	fopen_s(&fpR, "./Database.txt", "r");
	//get the number of schedules
	if (fpR != NULL) {
		//get the number of schedules
		while(!feof(rpR)){
			fgets(txtBuffer, 10000,fpR);
			scheduleNum++;
		}
		scheduleNum/=4;
		fclose(fpR);
		scheduleArr=(*Schedule)calloc(scheduleNum, sizeof(*Schedule));
		fopen(&fpR, "/Database.txt", "r");
		int	scheduleInd=0;
		while(!feof(rpR)){
			fgets(txtBuffer,10000,fpR);
			if(txtBuffer[0]=='#'){
				char year[5];
				char month[3];
				char date[3];
				char hour[3];
				char minute[3];
				fgets(txtBuffer,10000,fpR);
				strncpy(year,txtBuffer,4);
				eraseStrFL(txtBuffer,4);
				strncpy(month,txtBuffer,2);
				eraseStrFL(txtBuffer,2);
				strncpy(day,txtBuffer,2);
				eraseStrFL(txtBuffer,2);
				strncpy(hour,txtBuffer,2);
				eraseStrFL(txtBuffer,2);
				strncpy(minute,txtBuffer,2);
				scheduleArr[scheduleInd].pointingDay.year=itoa(year);
				scheduleArr[scheduleInd].pointingDay.month=itoa(month);
				scheduleArr[scheduleInd].pointingDay.date=itoa(date);
				scheduleArr[scheduleInd].time.tm_hour=itoa(hour);
				scheduleArr[scheduleInd].time.tm_minute=itoa(minute);
				fgets(txtBuffer,10000,fpR);
				scheduleArr[scheduleArr].contents=(char*)calloc(strlen(txtBuffer),sizeof(char*));
				strcpy(scheduleArr[scheduleArr].contents,txtBuffer);
			}
		}
	}
	else *scheduleArr=0;
}

			   
void eraseStrFL(char *targetS,int times){
	for(int i=0;i<times;i++){
		int	length=strlen(targetS)
		for(int j=0;j<length-1;j++){
			targetS[j]=target[j+1);
		}
		targetS[length-1]=NULL;
	}
}

void SaveSchedule(Day pointingDay, char* inputSchedule) {

}
