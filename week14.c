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

float readInt()
{
	float input;

	readf("%f", &input);

	return input;
}

typedef struct
{
	float x, y;
} point;

float distance(const point *x, const point *y)
{
	return sqrt(pow(abs(x->x - y->x), 2) + pow(abs(x->y - y->y), 2));
}

bool isTriangle(const point *a, const point *b, const point *c)
{
	return (distance(a, b) + distance(b, c) > distance(a, c));
}

void readPoint(point *x)
{
	x->x = readInt();
	x->y = readInt();
}

const isReadFile = true;
int main()
{
	open("test");

	point point_1, point_2;

	readPoint(&point_1);
	readPoint(&point_2);

	writef("%.5f", distance(&point_1, &point_2));

	point a, b, c;

	readPoint(&a);
	readPoint(&b);
	readPoint(&c);

	writef("\n%s", isTriangle(&a, &b, &c) ? "TRUE" : "FALSE");

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
