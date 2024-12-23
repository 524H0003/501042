#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    char id[30], name[256], phonenumber[10];
    bool isMale; // sex
    int birthyear, salary;
} IEmployee;

IEmployee employees[10];

int main()
{
    return 0;
}