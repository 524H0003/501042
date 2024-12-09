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

int readUserInput(char *type)
{
	int input;

	writef("Input %s: ", type);
	readf("%d", &input);

	return input;
}

const isReadFile = true;
int main()
{
	open("test");
	ll int n = readUserInput("array length"), ou = 0;

	do
	{
		writef("\t\t--- %lld element left ---\n", n);
		ll int i = readUserInput("element value");
		if (i % 2 == 0)
			ou += i;
	} while (--n);

	writef("Output: %lld", ou);

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
