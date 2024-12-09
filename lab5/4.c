#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define ARR_LENGTH 100000

int main()
{
	char in[ARR_LENGTH], l[ARR_LENGTH];
	int i, j, z, s = 0;

	fgets(in, ARR_LENGTH, stdin);

	for (j = 0; (isspace(in[j])); j++)
		;
	for (i = j; in[i]; i++)
	{
		if (l[i - j - s - 1] == ' ' && isspace(in[i]))
		{
			s++;
			continue;
		}
		l[i - j - s] = (!(i - j) || in[i - 1] == ' ') ? toupper(in[i]) : tolower(in[i]);
		z = (isspace(in[i])) ? z : i - j - s;
	}
	l[z + 1] = 0;

	printf("%s", l);

	return 0;
}