#include <string.h>
#include <stdio.h>
#define ARR_LENGTH 100000

int main()
{
	char in[ARR_LENGTH], f[ARR_LENGTH], l[ARR_LENGTH];
	int i, len;

	fgets(in, ARR_LENGTH, stdin);

	len = strlen(in);

	for (i = 0; in[i] != ' '; i++)
		;
	strncpy(f, in, i);
	f[i] = 0;
	printf("%s ", f);

	for (i = len - 2; in[i] != ' '; i--)
		l[len - 2 - i] = in[i];
	for (i = len - 2 - i; i > -1; i--)
		printf("%c", l[i]);

	return 0;
}