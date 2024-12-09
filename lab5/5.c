#include <stdio.h>
#define ARR_LENGTH 100000

int main()
{
	char in1[ARR_LENGTH], in2[ARR_LENGTH], l[ARR_LENGTH];
	int i, len;

	fgets(in1, ARR_LENGTH, stdin);
	fgets(in2, ARR_LENGTH, stdin);

	for (i = 0; in1[i]; i++)
		l[i] = in1[i];
	len = i - 1;
	for (i = 0; in2[i]; i++)
		l[len + i] = in2[i];
	l[len + i - 1] = 0;

	printf("%s", l);

	return 0;
}