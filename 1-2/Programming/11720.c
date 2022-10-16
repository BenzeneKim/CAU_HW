#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 101

char inputChar[MAX_LEN];
int length;
int result = 0;
void getInput(){
    char temp[MAX_LEN];
    //scanf("%d",&length);    //get length
    //scanf("%s",inputChar);
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] ='\0';
    length=atoi(temp);
    fgets(inputChar, sizeof(inputChar), stdin);
    inputChar[strcspn(inputChar, "\n")] = '\0';
}

void calc(){
    for(int i=0; i<length; i++){
        result+=inputChar[i]-48;
    }
}

void printResult(){
    printf("%d", result);
}
int main(){
    getInput();
    calc();
    printResult();
}
