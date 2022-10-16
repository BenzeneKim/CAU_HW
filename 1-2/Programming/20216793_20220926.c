#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


#define UpperA 65
#define LowerA 97

int main(){
    char msg[1000];
    int k=26;

    printf("please insert a string : ");
    fgets(msg, sizeof(msg), stdin);
    while (k>25||k<0)
    {
        printf("please insert a number(0~25) : ");
        scanf("%d", &k);
    }
    
    for(int i=0;i<sizeof(msg);i++){
        encoding(k, &msg[i]);
    }
    printf("Encoded : %s\n",msg);
    
    for(int i=0;i<sizeof(msg);i++){
        decoding(k, &msg[i]);
    }
    printf("Decoded : %s\n",msg);

    for(int i=0;i<sizeof(msg);i++){
        encoding(k, &msg[i]);
    }
    swap_char(msg);
    printf("Swapped : %s\n",msg);


}

void encoding(int n, char* c){
        if(isalpha(*c)==1){
            int digit = (int) *c;
            digit+=n;
            digit=((digit-UpperA)%26)+UpperA;
            *c=digit;
        }
        else if(isalpha(*c)==2){
            int digit = (int) *c;
            digit+=n;
            digit=((digit-LowerA)%26)+LowerA;
            *c=digit;
        }
}


void decoding(int n, char* c){
    if(isalpha(*c)==1){
        int digit = (int) *c;
        digit-=n;
        digit=((digit-UpperA)%26)+UpperA;
        if(digit<UpperA) digit+=26;
        *c=digit;
    }
    else if(isalpha(*c)==2){
        int digit = (int) *c;
        digit-=n;
        digit=((digit-LowerA)%26)+LowerA;
        if(digit<LowerA) digit+=26;
        *c=digit;
    }
}

void swap_char(char s[]){
    srand((unsigned int)time(NULL));
    int firstIndex=rand()%sizeof(s);
    int secondIndex=rand()%sizeof(s);
    while(firstIndex==secondIndex||isalpha(s[firstIndex])==0||isalpha(s[secondIndex])==0){
        srand((unsigned int)time(NULL));
        firstIndex=rand()%sizeof(s);
        secondIndex=rand()%sizeof(s);
    }
    char temp=s[firstIndex];
    s[firstIndex]=s[secondIndex];
    s[secondIndex]=temp;
}