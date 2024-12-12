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
int arr[ARR_LENGTH][2];

int findBin(const int l, const int r, const int key)
{
	if (l == r)
		return arr[l][1];

	int m = (l + r) / 2;
	if (arr[m][0] < key)
		return findBin(m + 1, r, key);
	else
		return findBin(l, m, key);

	return -2;
}

void swap(int a[2], int b[2])
{
	int t[2];
	memcpy(t, a, sizeof(int) * 2);
	memcpy(a, b, sizeof(int) * 2);
	memcpy(b, t, sizeof(int) * 2);
}

void sort(const int l, const int r)
{
	if (l >= r)
		return;

	int p = arr[r][0], i, j = l;

	for (i = l; i < r; i++)
		if (arr[i][0] < p)
			swap(arr[i], arr[j++]);
	swap(arr[j], arr[r]);

	sort(l, j - 1);
	sort(j + 1, r);
}

const isReadFile = false;
int main()
{
	open("test");

	int arrLength = readInt(), i;

	for (i = 0; i < arrLength; i++)
		arr[i][0] = readInt(), arr[i][1] = i;

	int ele = readInt();

	sort(0, arrLength - 1);

	writef("position of %d: %d", ele, findBin(0, arrLength - 1, ele) + 1);

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
