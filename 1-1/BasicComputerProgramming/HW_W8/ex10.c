#include <stdio.h>
int get_sum_and_diff(int a, int b, int * sum_ptr, int * diff_ptr);

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	get_sum_and_diff(a, b, &a, &b);
	printf("sum is : %d\n", a);
	printf("diff is : %d\n", b);
	return 0;
}

int get_sum_and_diff(int a, int b, int * sum_ptr, int * diff_ptr){
	int x, y;
	x = a;
	y = b;
	*sum_ptr=x+y;
	if(x-y>0) *diff_ptr=x-y;
	else *diff_ptr=y-x;
	return 0;
}
