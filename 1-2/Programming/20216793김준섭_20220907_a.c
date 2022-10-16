#include <stdio.h>
#include <stdlib.h>

#define NUM 10
#define TIME 100
int a[NUM+1];
int n=NUM;

int main(){
	for(int i=0;i<TIME;i++){
		int counter=0;
		for(int j=0;j<n;j++){
			int bin = rand()%2;
			if(bin == 0) counter+=1;
		}
		a[counter]++;
	}

	//print
	for(int i=0;i<n+1;i++){
		float per=100*a[i]/TIME;
		printf("%d [%.3f]:",i,per);
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				printf("*");
			}
		}
		printf("\n");
	}
}
