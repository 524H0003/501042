#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define fi first
#define se second

char *combineStrings(char *str1, char *str2)
{
	char *combined = (char *)malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));

	strcpy(combined, str1);
	strcat(combined, str2);

	return combined;
}

FILE *inputFile, *outputFile;
void open(char fileName[])
{
	inputFile = fopen(combineStrings(fileName, ".INP"), "r");
	if (inputFile == NULL)
	{
		printf(combineStrings(combineStrings(fileName, ".INP"), " not found"));
		raise(SIGABRT);
	}

	outputFile = fopen(combineStrings(fileName, ".OUT"), "w");
}

int readf(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int rc = vfscanf(inputFile, fmt, args);
	va_end(args);
	return rc;
}

int writef(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int rc = vfprintf(outputFile, fmt, args);
	va_end(args);
	return rc;
}

void swap(int *a, int *b)
{
	if (a < b)
		*a ^= *b, *b ^= *a, *a ^= *b;
}

int main()
{
	int useCase;

	do
	{
		writef("Input use case: ");
		readf("%d", &useCase);
		switch (useCase)
		{
		case 1:
			writef("Input numbers: ");
			int a, b, c;
			readf("%d %d %d", &a, &b, &c);
			swap(a, b);
			swap(a, b);
			writef("Max number is %d", &a);
			break;

		default:
			writef("Invalid input");
			break;
		}

	} while (true);

	return 0;
}