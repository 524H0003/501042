#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>

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
void writef(const char *, ...);
void writefi(const char *, ...);
char *combineStrings(char *, char *);

typedef struct
{
	float n;
	int bc, bg;
} data;

typedef struct
{
	float n;
	int ld;
	bool isBanh[2];
} IBanhProperties;

IBanhProperties banhChung, banhGiay;

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

void swap(IBanhProperties *a, IBanhProperties *b)
{
	IBanhProperties t = *a;
	*a = *b, *b = t;
}

float cal(const float n, const int bc, const int bg)
{
	const float res = n - banhChung.n * bc - banhGiay.n * bg;
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
	short int i, j, z;
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

	banhChung.n = makeBC(dc);
	banhGiay.n = makeBG(dg);
	banhChung.ld = (dc >= 8) + 1;
	banhGiay.ld = (dg >= 5) + 1;
	banhChung.isBanh[0] = banhGiay.isBanh[1] = 1;
	banhChung.isBanh[1] = banhGiay.isBanh[0] = 0;
	bool isEqual = false;

	IBanhProperties order[3];
	order[0].n = n, order[0].ld = 0, order[0].isBanh[0] = order[0].isBanh[1] = 0;
	order[1] = banhChung, order[2] = banhGiay;

	switch ((int)toupper(w))
	{
	case 'W':
		break;

	case 'O':
		if (banhGiay.n > banhChung.n)
			swap(order + 1, order + 2);
		break;

	case 'R':
		isEqual = true;
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
			return;
		}
		swap(order + 1, order + 2);
		break;

	default:
		writef("-1 -1 %d", n);
		return;
		break;
	}

	data arr[3][601]; // [Loai banh][La dong]

	for (i = 0; i < 3; i++)			// Loai banh
		for (j = 0; j <= ld; j++) // La dong
		{
			if (!i || !j)
			{
				arr[i][j].n = n;
				arr[i][j].bc = arr[i][j].bg = 0;
				continue;
			}

			float curN;
			memcpy(arr[i] + j, arr[i] + j - 1, sizeof(data));

			for (z = 0; z < 2; z++)
				switch (abs(z - isEqual))
				{
				case 0:
					if (j >= order[i].ld)
					{
						if ((curN = cal(arr[i][j - order[i].ld].n, order[i].isBanh[0], order[i].isBanh[1])) < arr[i][j].n)
						{
							arr[i][j].n = curN;
							arr[i][j].bc = arr[i][j - order[i].ld].bc + order[i].isBanh[0];
							arr[i][j].bg = arr[i][j - order[i].ld].bg + order[i].isBanh[1];
						}

						if ((curN = cal(arr[i - 1][j - order[i].ld].n, order[i].isBanh[0], order[i].isBanh[1])) < arr[i][j].n)
						{
							arr[i][j].n = curN;
							arr[i][j].bc = arr[i - 1][j - order[i].ld].bc + order[i].isBanh[0];
							arr[i][j].bg = arr[i - 1][j - order[i].ld].bg + order[i].isBanh[1];
						}
					}
					break;
				case 1:
					if ((curN = cal(arr[i - 1][j - order[i].ld - order[i - 1].ld].n, order[i].isBanh[0] + order[i - 1].isBanh[0], order[i].isBanh[1] + order[i - 1].isBanh[1])) < arr[i][j].n)
					{
						arr[i][j].n = curN;
						arr[i][j].bc = arr[i - 1][j - order[i].ld].bc + order[i].isBanh[0] + order[i - 1].isBanh[0];
						arr[i][j].bg = arr[i - 1][j - order[i].ld].bg + order[i].isBanh[1] + order[i - 1].isBanh[1];
					}
					break;
				}
		}

	writef("%.0f %.0f %.3f", (float)arr[2][ld].bc, (float)arr[2][ld].bg, (float)arr[2][ld].n);
}

#define NUM_TEST 100
const isReadFile = true;
int main()
{
	int i;
	char snum[5], w[10];

	srand(time(NULL));
	for (i = 0; i < NUM_TEST; i++)
	{
		sprintf(snum, "%d", i);

		const char *dirName = combineStrings("test", snum);

		mkdir(dirName, 0777);
		open(combineStrings(dirName, "/"));

		const int wi = rand() % 5;
		switch (wi)
		{
		case 0:
			strncpy(w, "Rain", 10);
			break;

		case 1:
			strncpy(w, "Sun", 10);
			break;

		case 2:
			strncpy(w, "Cloud", 10);
			break;

		case 3:
			strncpy(w, "Fog", 10);
			break;

		case 4:
			strncpy(w, "Wind", 10);
			break;

		default:
			break;
		}

		const n = rand() % 2000 + 1, bc = rand() % 16 + 1, bg = rand() % 16 + 1, ld = rand() % 600 + 1;
		writefi("%d %d %d %d %s", n, bc, bg, ld, w);
		solve(n, ld, bc, bg, *w);
	}

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
void open(char *dirName)
{
	inputFile = fopen(combineStrings(dirName, combineStrings("input", ".INP")), "w");

	outputFile = fopen(combineStrings(dirName, combineStrings("output", ".OUT")), "w");
}

void readf(const char *fmt, ...)
{
	static va_list args;
	va_start(args, fmt);
	vfscanf(inputFile, fmt, args);
	va_end(args);
}

void writefi(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	if (isReadFile)
		vfprintf(inputFile, fmt, args);
	else
		vprintf(fmt, args);
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
