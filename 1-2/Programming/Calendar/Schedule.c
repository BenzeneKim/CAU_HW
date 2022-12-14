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
void GetSchedule(Schedule scheduleArr[]) {
	FILE* fpR;
	int scheduleNum = 0;
	char txtBuffer[500];
	fpR = fopen("./Database.txt", "r");
	//get the number of schedules
	system("cls");
	if (fpR != NULL) {
		//get the number of schedules
		fpR = fopen("./Database.txt", "r");
		int	scheduleInd=0;
		while(!feof(fpR)){
			fgets(txtBuffer,500,fpR);
			if(txtBuffer[0] == '#'){
				char year[5];
				char month[3];
				char date[3];
				char hour[3];
				char minute[3];
				fgets(txtBuffer, 500, fpR);
				strncpy(year, txtBuffer, 4);
				eraseStrFL(txtBuffer, 4);
				strncpy(month, txtBuffer, 2);
				eraseStrFL(txtBuffer,2);
				strncpy(date,txtBuffer,2);
				eraseStrFL(txtBuffer,2);
				strncpy(hour,txtBuffer,2);
				eraseStrFL(txtBuffer,2);
				strncpy(minute,txtBuffer,2);
				scheduleArr[scheduleInd].year = atoi(year);
				scheduleArr[scheduleInd].month = atoi(month);
				scheduleArr[scheduleInd].date = atoi(date);
				scheduleArr[scheduleInd].hour = atoi(hour);
				scheduleArr[scheduleInd].minute = atoi(minute);
				fgets(txtBuffer, 500, fpR);
				strcpy(scheduleArr[scheduleInd].contents, txtBuffer);
			}
			printf("getingTxt\n");
			Sleep(100);
		}
	}

}

			   
void eraseStrFL(char *targetS,int times){
	for(int i=0;i<times;i++){
		int	length = strlen(targetS);
		for(int j=0;j<length-1;j++){
			targetS[j] = targetS[j + 1];
		}
		targetS[length-1]=NULL;
	}
}