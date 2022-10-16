#include <stdio.h>
int largenumber(int *, int *);

int main(){
	int fno, sno, largenum;
	printf(" Input the first number : ");
	scanf("%d", &fno);
	printf(" Input the second number : ");
	scanf("%d", &sno);
	largenum = largenumber(&fno, &sno);
	printf(" The large number is %d\n", largenum);
	return 0;
}

int largenumber(int *n1, int *n2){
	if (*n1 > *n2) {
		return *n1;
	}
	else {
		return *n2;
	}
}
