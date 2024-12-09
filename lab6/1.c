#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checkPrime(const int n)
{
	int i;
	for (i = ceil(sqrt(n)); i > 1; i--)
        if (!(n % i) && n != i && checkPrime(i))
            return false;
	return true;
}

int main()
{
	int n;

	scanf("%d", &n);

	bool output = checkPrime(n);
    
    printf("%d is%sprime", n, output ? " " : " not ");

	return 0;
}