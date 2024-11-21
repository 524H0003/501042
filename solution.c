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
		if (input < 0)
			return -1;
	} while (input < 0);

	return input;
}

#define nums_size 1000
const int isReadFile = false;
int main()
{
	open("test");
	int n, nums[nums_size][2], i;

	for (i = 0; i < nums_size; i++)
		for (n = 0; n < 2; n++)
			nums[i][n] = 0;

	i = 1, n = -1;
	do
	{
		if (n >= 0 && (!nums[n][0] || !nums[n][1]))
			if (!nums[n][0])
				nums[n][0] = i++;
			else
				nums[n][1] = i++;
		n = readUserInput("num");
	} while (n >= 0);
	n = readUserInput("target");

	for (i = 0; i <= n / 2; i++)
		if (i != n - i)
		{
			if (nums[i][0] && nums[n - i][0])
			{
				writef("[%d, %d]", nums[i][0] - 1, nums[n - i][0] - 1);
				return 0;
			}
		}
		else if (nums[i][0] && nums[i][1])
		{
			writef("[%d, %d]", nums[i][0] - 1, nums[i][1] - 1);
			return 0;
		}
	writef("No solution");

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
