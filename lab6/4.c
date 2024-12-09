#include <stdio.h>

int x;
long long int factorial(const int n)
{
	if (n == 0) return 1;
	return x * factorial(n-1);
}

int main()
{
	int n;

    printf("n: ");
	scanf("%d", &n);
	
	printf("x: ");
	scanf("%d", &x);

	printf("%lld", factorial(n));

	return 0;
}