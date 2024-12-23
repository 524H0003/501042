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

void swap(IEmployee *a, IEmployee *b)
{
    IEmployee t = *a;
    *a = *b;
    *b = t;
}

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

int countEmployeesBySex(const bool countMale)
{
    int i, numMale = 0, numFemale = 0;

    for (i = 0; i < NUM_EMPLOYEES && employees[i].name; i++)
        numMale += employees[i].isMale, numFemale += !employees[i].isMale;

    return countMale ? numMale : numFemale;
}

void sortEmployeesByBirthYear(const int l, const int r)
{
    if (l >= r)
        return;

    int pivot = employees[r].birthyear, i = r - 1, j;

    for (j = l; j < r; j++)
        if (employees[j].birthyear < pivot)
            swap(employees + ++i, employees + j);
    swap(employees + ++i, employees + r);

    sortEmployeesByBirthYear(l, i - 1);
    sortEmployeesByBirthYear(i + 1, r);
}

void sortEmployeesBySalary(const int l, const int r)
{
    if (l >= r)
        return;

    int pivot = employees[r].salary, i = r - 1, j;

    for (j = l; j < r; j++)
        if (employees[j].salary < pivot)
            swap(employees + ++i, employees + j);
    swap(employees + ++i, employees + r);

    sortEmployeesBySalary(l, i - 1);
    sortEmployeesBySalary(i + 1, r);
}

int main()
{
    return 0;
}