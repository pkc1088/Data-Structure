#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int factorial(int n)
{
	if(n<=1) return(1);
	else return (n*factorial(n-1));
}

int main(void)
{
	int sum=factorial(5);
	printf("%d\n", sum);

    return 0;
}

