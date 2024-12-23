#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    char id[30], name[256], phonenumber[10];
    bool isMale; // sex
    int birthyear, salary;
} IEmployee;

#define NUM_EMPLOYEES 10
IEmployee employees[NUM_EMPLOYEES];

void printAllEmployees()
{
    int i;

    for (i = 0; i < NUM_EMPLOYEES; i++)
    {
        IEmployee iEmp = employees[i];
        printf("\n-------------------------\nId: %s\nName: %s\nSex: %s\nBirth year: %d\nPhone number: %s\nSalary: %d", iEmp.id, iEmp.name, iEmp.isMale ? "Male" : "Female", iEmp.birthyear, iEmp.phonenumber, iEmp.salary);
    }
}

int main()
{
    return 0;
}