#include <stdio.h>
int main () {
	int lim, sum;
	sum = 0;
	scanf("%d", &lim);
	for(int i=1; i<=lim; i++){
		sum += i;
	}
	printf("%d\n", sum);
}
