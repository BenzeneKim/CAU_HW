#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 101

char inputTxt[MAX_LEN];
int ind[26];
void getInput(){
    fgets(inputTxt, sizeof(inputTxt), stdin);
    inputTxt[strcspn(inputTxt, "\n")]='\0';
}

void processString(){
    for(int i=0;i<26;i++){
        char temp[2];
        temp[0]=(char)(i+97);
        temp[1]='\0';
        ind[i]=0;
        if(strcspn(inputTxt, temp)+1>strlen(inputTxt)) ind[i] = -1; 
        else if(strcspn(inputTxt, temp)<=strlen(inputTxt))ind[i]=strcspn(inputTxt, temp);
    }
}

void printResult(){
    for(int i=0;i<26;i++){
        printf("%d", ind[i]);
        if(i!=25) printf(" ");
    }
}

int main(){
    getInput();
    processString();
    printResult();
}