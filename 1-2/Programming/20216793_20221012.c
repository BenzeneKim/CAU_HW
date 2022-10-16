#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100
typedef struct struct_date{
    int year, month, day;
} Sdate;

typedef struct struct_person{
    char name[MAX_STR];
    char telephone[MAX_STR];
    Sdate birthday;
} Sperson;

Sperson GetString(){
    Sperson p;
    char inputDate[10];
    char fN[4];
    char sN[5];
    char tN[5];
    char y[5];
    char m[3];
    char d[3];
    int trigger=1;
    printf("Enter the name : ");
    fgets(&p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name,"\n")] ='\0';
    while(trigger==1){
        printf("Enter the phone number : ");
        fgets(&p.telephone, sizeof(p.telephone), stdin); 
        p.telephone[strcspn(p.telephone,"\n")] ='\0';
        if(isNumber(p.telephone)==1) trigger=0;
        else printf("Input is wrong\n");
    }
    trigger=1;
    while (trigger==1)
    {
        printf("Enter the birthday : ");
        fgets(&inputDate, 10, stdin);
        string_split(inputDate,4,6,y,m,d);
        p.birthday.year= atoi(y);
        p.birthday.month=atoi(m);
        p.birthday.day=atoi(d);
        if(p.birthday.year>=0&&p.birthday.month>=1&&p.birthday.month<=12&&p.birthday.day>=1&&p.birthday.day<=31) trigger=0;
        else printf("Input is wrong\n");
    }
    
    return p;
}
int isNumber(char s[])
{
    for (int i = 0; s[i]!= '\0'; i++)
    {
        if (isdigit(s[i]) == 0)
              return 0;
    }
    return 1;
}
void string_split(char *s, int indexF, int indexS,char *fi, char *se, char *th){
    int length = strlen(s);
    if(indexS<length&&indexS>indexF){
        for(int i=0;i<indexF;i++){
            fi[i]=s[i];
        }
        fi[indexF]='\0';
        for(int i=indexF;i<indexS;i++){
            se[i-indexF]=s[i];
        }
        se[indexS-indexF]='\0';
        for(int i=indexS;i<length-1;i++){
            th[i-indexS]=s[i];
        }
    }
}
void printStruct(Sperson p){
    printf("Name: %s\n", p.name);
    printf("Telephone: %s\n", p.telephone);
    printf("Birthday: %d.%d.%d.\n",p.birthday.year,p.birthday.month,p.birthday.day);
}

int main(){
    for(int i=0;i<2;i++){
        Sperson inputPerson = GetString();
        printStruct(inputPerson);
    }
}