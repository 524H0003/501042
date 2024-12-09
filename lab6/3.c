#include <stdio.h>

long long int factorial(const int n)
{
	if (n == 0) return 1;
	return 2 * factorial(n-1);
}

int main()
{
	int n;

	scanf("%d", &n);

	printf("%lld", factorial(n));

	return 0;
}