#include <stdio.h>

int change_by_ptr(int* a, int b);
int change_by_double_ptr(int **a, int b);


int main(void){
   int a, b, c;
   int * a_ptr;
   int ** double_ptr;
   a_ptr = &a;
   double_ptr = &a_ptr;

   scanf("%d", &a);
   printf("change a to .. ");
   scanf("%d", &b);
   change_by_ptr(a_ptr, b);
   printf("now a is %d\n", a);
   printf("change a to .. ");
   scanf("%d", &c);
   change_by_double_ptr(double_ptr, c);
   printf("now a is %d\n", a);
   return 0;
}

int change_by_ptr(int* a, int b){
   *a = b;
   return 0;
}

int change_by_double_ptr(int** a, int b){
   int* mPtr = *a;
   *mPtr = b;
   return 0;
}
