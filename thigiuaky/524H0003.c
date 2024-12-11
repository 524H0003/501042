#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
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

void open();
void readf(const char *, ...);
void writef(const char *, ...);

float readInt()
{
	float input;

	readf("%f", &input);

	return input;
}

char readChar()
{
	char input;
	readf("%s", &input);
	return input;
}

float makeBC(float dc)
{
	return pow(dc, 2) * sqrt(dc);
}

float makeBG(float dg)
{
	return pow(dg, 2) * 3.1415926535 / 3.0;
}

bool isPerfectSquare(const int x)
{
	int s = round(sqrt(x));
	return (s * s == x);
}

bool isFibonacci(const int n)
{
	return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b, *b = t;
}

float cal(const float n, const float nPerBC, const float nPerBG, const int bc, const int bg)
{
	const float res = n - nPerBC * bc - nPerBG * bg;
	if (res < 0)
		return INT_MAX;
	return res;
}

int divSum(const int n)
{
	int result = 0, i;

	for (i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			if (i == (n / i))
				result += i;
			else
				result += (i + n / i);

	return (result + 1);
}

bool areAmicable(const int x, const int y)
{
	if (divSum(x) != y)
		return false;

	return (divSum(y) == x);
}

void solve(const int n, const int ld, const float dc, const float dg, const int w)
{
	int i, j;
	if (w == 'S')
	{
		i = ((int)(dc) % 6) - (ld % 5);
		if (i == -4 || i == 2)
			j = 10;
		else if (i == -3 || i == 3)
			j = 12;
		else if (i == -2 || i == 4)
			j = 15;
		else if (i == -1 || i == 5)
			j = 20;
		else if (!i)
			j = 5;
		else if (i == 1)
			j = 7;
		return solve(round(n * (100 + j) / 100), ld - j, dc, dg, (int)(dc + dg) % 3 == 0 ? 'R' : ((int)(dc + dg) % 3 == 1 ? 'W' : 'C'));
	}

	// Order: 1 (Banh chung); 2 (Banh giay); 3 (Bang nhau)
	float nPerBC = makeBC(dc), nPerBG = makeBG(dg), arr[601][3];
	int ldPerBC = (dc < 8) + 1, ldPerBG = (dg < 5) + 1, order[] = {1, 2, 3};

	switch ((int)toupper(w))
	{
	case 'W':
		break;

	case 'O':
		if (nPerBG > nPerBC)
			swap(order, order + 1);
		break;

	case 'R':
		swap(order + 2, order);
		break;

	case 'F':
		if (isFibonacci(dc) && isFibonacci(dg))
			return solve(n, ld, dc / 2, dg / 2, 'O');
		else
			return solve(n, ld, dc * 2, dg * 2, 'O');
		break;

	case 'C':
		if (areAmicable(n, ld))
		{
			writef("0 0 %d", n);
			exit(0);
		}
		swap(order, order + 1);
		break;
	}

	arr[0][0] = n, arr[0][1] = arr[0][2] = 0;
	for (i = 1; i < 601; i++) // la dong
	{
		float curN;
		memcpy(arr[i], arr[i - 1], sizeof(int) * 3);

		for (j = 0; j < 3; j++)
			switch (order[j])
			{
			case 1:
				if (i >= ldPerBC && (curN = cal(arr[i - ldPerBC][0], nPerBC, nPerBG, 1, 0)) < arr[i][0])
				{
					arr[i][0] = curN;
					arr[i][1] = arr[i - ldPerBC][1] + 1;
					arr[i][2] = arr[i - ldPerBC][2];
				}
				break;

			case 2:
				if (i >= ldPerBG && (curN = cal(arr[i - ldPerBG][0], nPerBC, nPerBG, 0, 1)) < arr[i][0])
				{
					arr[i][0] = curN;
					arr[i][1] = arr[i - ldPerBG][1];
					arr[i][2] = arr[i - ldPerBG][2] + 1;
				}
				break;

			case 3:
				if (i >= ldPerBC + ldPerBG && (curN = cal(arr[i - ldPerBC - ldPerBG][0], nPerBC, nPerBG, 1, 1)) < arr[i][0])
				{
					arr[i][0] = curN;
					arr[i][1] = arr[i - ldPerBC - ldPerBG][1] + 1;
					arr[i][2] = arr[i - ldPerBC - ldPerBG][2] + 1;
				}

				break;
			}
	}

	writef("%.0f %.0f %.3f", arr[600][1], arr[600][2], arr[600][0]);
}

const isReadFile = false;
int main()
{
	open();

	float n = readInt(), dc = readInt(), dg = readInt(), ld = readInt(), w = readChar();

	solve(n, ld, dc, dg, w);

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
