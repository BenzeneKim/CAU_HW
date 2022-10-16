#include <stdio.h>
#define date __DATE__
#define time __TIME__
#define file __FILE__
int main () {
	printf("%s\n", date);
	printf("%s\n", time);
	printf("%s\n", file);
}
