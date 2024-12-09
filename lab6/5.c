#include <stdio.h>

long long int factorial(const int n)
{
	if (n < 10) return 1;
	return 1 + factorial(n/10);
}

int main()
{
	int n;

	scanf("%d", &n);

	printf("%lld", factorial(n));

	return 0;
}