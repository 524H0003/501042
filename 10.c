#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second
#define try bool __HadError = false;
#define catch \
	ExitJmp:    \
	if (__HadError)
#define throw          \
	{                    \
		__HadError = true; \
		goto ExitJmp;      \
	}

void open(char[]);
void readf(const char *, ...);
void writef(const char *, ...);
char *combineStrings(char *str1, char *str2);

int readUserInput(const char *type, ...)
{
	va_list args;
	va_start(args, type);
	int input;

	writef(combineStrings("Input ", combineStrings(type, ": ")), *args);
	readf("%d", &input);

	return input;
}

#define ARR_LENGTH 100000
const isReadFile = true;
int main()
{
	open("test");
	int n = readUserInput("array length"), i, j, z = 0, ou[ARR_LENGTH];
	bool arr[2][ARR_LENGTH];

	for (i = 0; i < ARR_LENGTH; i++)
		arr[0][i] = arr[1][i] = 0;

	for (j = 0; j < n; j++)
	{
		i = readUserInput("value at %d", j + 1);
		if (!arr[(i < 0)][abs(i)])
			ou[z++] = i;
		arr[(i < 0)][abs(i)] = true;
	}

	for (i = 0; i < z; i++)
		writef("%d ", ou[i]);

	return 0;
}

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
	if (!isReadFile)
		return;

	inputFile = fopen(combineStrings(fileName, ".INP"), "r");
	if (inputFile == NULL)
	{
		printf(combineStrings(combineStrings(fileName, ".INP"), " not found"));
		raise(SIGABRT);
	}

	outputFile = fopen(combineStrings(fileName, ".OUT"), "w");
}

void readf(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	if (isReadFile)
		vfscanf(inputFile, fmt, args);
	else
		vscanf(fmt, args);
	va_end(args);
}

void writef(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	if (isReadFile)
		vfprintf(outputFile, fmt, args);
	else
		vprintf(fmt, args);
	va_end(args);
}
