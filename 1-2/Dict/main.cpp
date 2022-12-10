#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#pragma warning(disable : 4996)


#define MAX_WORDS 13000
#define MAX_WORDLEN 1000
#define MAX_MEANING 1000

typedef struct _word {
	char word[MAX_WORDLEN];
	char meaning[MAX_MEANING];
} Sword;

Sword dictionary[MAX_WORDS];
int nwords = 0;

void GetWords();
int SelectFunction();
void Function();
int Search();
void View();


void GetWords() {

    FILE* fpR;
    //fopen_s(&fpR, "./vocal13000.txt", "rt+,ccs=UTF-8");
    fopen_s(&fpR, "./vocal13000.txt", "r");
    if (fpR == NULL) {
        printf("doesn't have file");
    }
    else {
        while (!feof(fpR)) {
            char buffer[1000];
            fgets(buffer, 1000, fpR);
            buffer[strcspn(buffer, "\n")] = '\0';
            int i = 0;
            while(buffer[i] != ' ') {
                dictionary[nwords].word[i] = buffer[i];
                i++;
            }
            dictionary[nwords].word[i] = '\0';
            while (buffer[i] == ' ') i++;
            int meaningFlag = i;
            while (buffer[i] != '\0') {
                dictionary[nwords].meaning[i - meaningFlag] = buffer[meaningFlag];
                i++;
            }
            nwords++;
            //printf("%d  :  %s  :  %s\n", nwords, dictionary[nwords-1].word, dictionary[nwords-1].meaning);
        }
        fclose(fpR);
    }
}

int SelectFunction() {
    char inputS[2];
    int isPressed = 0;
    int getKey;
    system("cls");
    printf("1. Search a Word\n");
    printf("2. List Words\n");
    printf("3. Exit\n");
    while (isPressed == 0) {
        if (kbhit()) {
            char input = getch();
            inputS[0] = input;
            inputS[1] = '\0';
            getKey = atoi(inputS);
            isPressed = 1;
        }
    }
    return getKey;
}

void Function(int ind) {
    switch (ind) {
    case 1:
        Search();
        break;
    case 2:
        View();
        break;
    case 3:
        exit(0);
        break;
    default:
        break;
    }
}

int Search() {
    system("cls");
    printf("type a word to search : ");
    char inputWord[MAX_WORDLEN];
    fgets(inputWord, MAX_WORDLEN, stdin);
    inputWord[strcspn(inputWord, "\n")] = '\0';
    for (int i = 0; i < nwords; i++) {
        if (strcmp(inputWord, dictionary[i].word) == 0) {
            printf("%d  :  %s  :  %s\n", i + 1, dictionary[i].word, dictionary[i].meaning);
            printf("exit to press any key\n");
            while (!kbhit());
            char input = getch();
            return 0;
        }
    }
    printf("there's no word");
    return 0;
}
void View() {
    int i = 0;
    int num = 0;
    system("cls");
    while (1) {
        if (num == nwords) {
            while (!kbhit());
            char input = getch();
            break;
        }
        else if (i == 15) {
            printf("press 0 to exit\n");
            while (!kbhit());
            char input = getch();
            if (input == '0') break;
            i = 0;
            system("cls");
        }
        else {
            printf("%d  :  %s  :  %s\n", num+1, dictionary[num].word, dictionary[num].meaning);
            num++;
            i++;    
        }
    }
}

int main() {
    system("chcp 65001");
    GetWords();
    while (1) {
        Function(SelectFunction());
    }
}