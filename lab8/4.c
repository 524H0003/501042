#include <stdio.h>
#include <stdbool.h>

#define ID_LENGTH 30

typedef struct
{
    char id[ID_LENGTH], name[256], phonenumber[10];
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

int findEmployeeById(const char id[ID_LENGTH])
{
    int i;

    for (i = 0; i < NUM_EMPLOYEES && employees[i].name; i++)
        if (employees[i].id == id)
            return i;
    return -1;
}

int main()
{
    return 0;
}