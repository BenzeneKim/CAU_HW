#include <stdio.h>
int main () {
	int loop;
	scanf("%d", &loop);
	for(int i=1;i<=loop;i++){
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		printf("Operation #%d: %d + %d = %d\n", i, n1, n2, n1+n2);
	}
}
