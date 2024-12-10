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

void open();
void readf(const char *, ...);
void writef(const char *, ...);

int readInt()
{
	int input;

	readf("%d", &input);

	return input;
}

char readChar()
{
	char input;
	readf("%s", &input);
	return input;
}

float makeBC(int dc)
{
	return pow(dc, 2) * sqrt(dc);
}

float makeBG(int dg)
{
	return pow(dg, 2) * 3.1415926535 / 3.0;
}

void solve(const int n, const int ld, const float *nPerBC, const float *nPerBG, const int *ldPerBC, const int *ldPerBG, const float *dc, const float *dg, const int w)
{
	int i, x;
	if (w == 'S')
	{
		i = ((int)(*dc) % 6) - (ld % 5);
		if (i == -4 || i == 2)
			x = 10;
		else if (i == -3 || i == 3)
			x = 12;
		else if (i == -2 || i == 4)
			x = 15;
		else if (i == -1 || i == 5)
			x = 20;
		else if (!i)
			x = 5;
		else if (i == 1)
			x = 7;
		return solve(round(n * (100 + x) / 100), ld - x, nPerBC, nPerBG, ldPerBC, ldPerBG, dc, dg, (int)(*dc + *dg) % 3 == 0 ? 'R' : ((int)(*dc + *dg) % 3 == 1 ? 'W' : 'C'));
	}

	switch ((int)w)
	{
	case 'W':
		break;

	case 'R':
		break;
	}
}

const isReadFile = false;
int main()
{
	open();

	float n = readInt(), dc = readInt(), dg = readInt(), ld = readInt(), w = readChar();
	float nPerBC = makeBC(dc), nPerBG = makeBG(dg);
	int ldPerBC = (dc < 8) + 1, ldPerBG = (dg < 5) + 1;

	solve(n, ld, &nPerBC, &nPerBG, &ldPerBC, &ldPerBG, &dc, &dg, w);

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
void open()
{
	if (!isReadFile)
		return;

	inputFile = fopen(combineStrings("input", ".INP"), "r");
	if (inputFile == NULL)
	{
		printf(combineStrings(combineStrings("input", ".INP"), " not found"));
		raise(SIGABRT);
	}

	outputFile = fopen(combineStrings("output", ".OUT"), "w");
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
