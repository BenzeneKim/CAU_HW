#include <stdio.h>
#include <stdlib.h>

#define NUM 10
#define TIME 100
int a[NUM+1];
float b[NUM+1];
int n=NUM;

float fact(int num){
    if(num!=0){
        float result=1;
        for(int i=1;i<num+1;i++) result*=i;
        return result;        
    }
    else return 1;
}

int main(){
	for(int i=0;i<TIME;i++){
        b[i]=100*fact(n)/fact(i)/fact(n-i)*(powf(0.5,(float)i))*(powf(0.5,(float)n-i));
	}

	//print
	for(int i=0;i<n+1;i++){
		float per=b[i]/100;
		printf("%d [%.3f]:",i,per);
		if((int)b[i]!=0){
			for(int j=0;j<(int)b[i];j++){
				printf("*");
			}
		}
		printf("\n");
	}
}
