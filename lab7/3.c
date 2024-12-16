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

int readInt()
{
	int input;

	readf("%d", &input);

	return input;
}

#define ARR_LENGTH 1000
int arr[ARR_LENGTH];

void swap(int *a, int *b)
{
	int t;
	t = *a, *a = *b, *b = t;
}

void sort(const int size)
{
	int i, start, min_index;

	for (start = 0; start < size - 1; start++)
	{
		min_index = start;
		for (i = start + 1; i < size; i++)
			if (arr[i] > arr[min_index])
				min_index = i;

		swap(arr + start, arr + min_index);
	}
}

const isReadFile = false;
int main()
{
	open("test");

	int arrLength = readInt(), i;

	for (i = 0; i < arrLength; i++)
		arr[i] = readInt();

	sort(arrLength);

	for (i = 0; i < arrLength; i++)
		writef("%d ", arr[i]);

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
