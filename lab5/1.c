#include <stdio.h>
#include <string.h>
#define ARR_LENGTH 100000

int main()
{
	char input[ARR_LENGTH];
	int i;

	fgets(input, ARR_LENGTH, stdin);
	printf("%d", strlen(input) - 1);

	return 0;
}