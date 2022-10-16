#include <stdio.h>
#include <string.h>
#define MAX_WORD 100
#define MAX_STR 100

int types[MAX_WORD];
char words[MAX_WORD][MAX_STR];
char input[10000];
int isDel;


void parse(char inputStr[]){
    isDel=0;
    int j=0;
    int k=0;
    int isDel=0;
    for(int i=0;i<10000;i++){
        if(inputStr[i]==NULL) break;
        else if(inputStr[i]==' ' || inputStr[i]=='\t' || inputStr[i]=='\n'){
            if(isDel!=1) j++;
            isDel=1;
            k=0;
        }
        else {
            isDel=0;
            words[j][k]=input[i];
            k++;
        }
    }
}

void defineStr(int i){
    int firstCharType = 0;
    int charType = 0;
    int postCharType = 0;
    int isDoublePoint = 0;
    int digitIn = 0;
    for(int j=0;j<MAX_STR;j++){
        if(charType<4){
            if(((int)words[i][j]>64&&(int)words[i][j]<91)||((int)words[i][j]>96&&(int)words[i][j]<123)) {   //Alpaha
                if(j==0) {
                    firstCharType=1;
                    charType=firstCharType;
                }
                else{
                    charType=1;
                    if(postCharType!=charType) charType=4;
                } 
            }
            else if(words[i][j]=='+'||words[i][j]=='-'||words[i][j]=='*'||words[i][j]=='/'||words[i][j]=='^'){ //Oper
                if(j==0){
                    firstCharType=2;
                    charType=firstCharType;
                } 
                else {
                    charType=2;
                    if(postCharType!=charType) charType=4;
                }
            }
            else if((int)words[i][j]<58 && (int)words[i][j]>47){   //num
                if(j==0) {
                    firstCharType=3;
                    charType=firstCharType;
                    digitIn = 1;
                }
                else {
                    digitIn = 1;
                    if(postCharType==3) charType=3;
                    else if(postCharType==2&&j==1) charType=3;
                    else charType=4;
                }
            }
            else if(words[i][j]=='.'){
                if(isDoublePoint==0){
                    if(j==0) {
                        firstCharType=3;
                        charType=firstCharType;
                    }
                    else charType=3;
                    isDoublePoint=1;
                }
                else charType=4; //not number
            }
            else if(words[i][j]==NULL) break; 

            postCharType=charType;
        }

    }
    if(digitIn==0&&isDoublePoint==1) charType = 4;
    if(words[i][0]!=NULL){
        printf("[%d] %s ", i+1, words[i]);
        if(charType == 1){
            printf("(Alphabets)\n");
        }
        else if(charType == 2){
            printf("(Operators)\n");
        }
        else if(charType == 3){
            printf("(Numbers)\n");
        }
        else if(charType == 4){
            printf("(Others)\n");
        }
    }
}

int main(){
    int length=0;
    char enter = '\n';
    char str[1000];
    while(gets(str)!=NULL){
        strcat(input, str);
        strcat(input, &enter);
    }
    parse(input);
    for(int i; i<MAX_WORD;i++){
        defineStr(i);
    }
}