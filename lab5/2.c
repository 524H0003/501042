#include <stdio.h>
#include <string.h>
#define ARR_LENGTH 100000

int main()
{
	char input[ARR_LENGTH];
	int i;

	fgets(input, ARR_LENGTH, stdin);

	for (i = strlen(input); i >= 0; i--)
		printf("%c", input[i]);

	return 0;
}