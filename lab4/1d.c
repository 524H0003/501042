#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>
#include <stdbool.h>

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

	do
	{
		writef("Input %s: ", type);
		readf("%d", &input);
	} while (input <= 1);

	return input;
}

#define ARR_LENGTH 1000
ll int foreValue[ARR_LENGTH];

ll int giaiThua(ll int n)
{
	if (foreValue[n])
		return foreValue[n];
	if (n > 1)
		return foreValue[n] = n * giaiThua(n - 1);
	return 1;
}

const isReadFile = true;
int main()
{
	open("test");
	ll int n = readUserInput("n"), ou;

	for (ou = 0; ou < ARR_LENGTH; ou++)
		foreValue[ou] = 0;
	ou = 1;
	do
		ou *= giaiThua(n);
	while (--n);

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
