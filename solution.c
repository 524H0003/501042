#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>
#include <limits.h>
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

#define MAX_CLASSES 10
#define MAX_STUDENTS 30

int readUserInput(char *type, int smallerThan)
{
	int input;

	do
	{
		writef("Input %s: ", type);
		readf("%d", &input);
	} while (input >= smallerThan || input < 0);

	return input;
}

int readDataInput(int isEnrol[][MAX_CLASSES], int numClasses, int numStudents)
{
	int entries = readUserInput("number of data entries", INT_MAX), i;
	writef("Enter %d data entries (student class): \n", entries);
	for (i = 0; i < entries; i++)
		isEnrol[readUserInput("student", numStudents)][readUserInput("class", numClasses)] = 1;
}

int classWithMostStudent(int isEnrol[][MAX_CLASSES], int numClasses, int numStudents)
{
	int class = numClasses, i, j;

	for (i = 0; i < numClasses; i++)
	{
		for (j = 0; j < numStudents; j++)
			isEnrol[numStudents][i] += isEnrol[j][i];
		if (isEnrol[numStudents][i] > isEnrol[numStudents][class])
			class = i;
	}

	return class;
}

void nameStudentsWithClasses(int isEnrol[][MAX_CLASSES], int numClasses, int numStudents)
{
	int i, j;

	for (i = 0; i < numClasses; i++)
	{
		writef("Class number %d\n", i);

		for (j = 0; j < numStudents; j++)
			if (isEnrol[j][i])
				writef("\tStudent %d\n", j);
	}
}

const int isReadFile = false;
int main()
{
	open("test");
	int numClasses, numStudents, isEnrol[MAX_STUDENTS][MAX_CLASSES] = {{0}};

	writef("Number of classes and students\n");
	numClasses = readUserInput("number of clases", MAX_CLASSES);
	numStudents = readUserInput("number of students", MAX_STUDENTS);
	readDataInput(isEnrol, numClasses, numStudents);

	writef("Class with most student: %d", classWithMostStudent(isEnrol, numClasses, numStudents));
	nameStudentsWithClasses(isEnrol, numClasses, numStudents);

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
		printf("%s", combineStrings(combineStrings(fileName, ".INP"), " not found"));
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
