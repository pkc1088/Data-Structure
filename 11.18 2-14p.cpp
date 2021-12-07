#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double circuit(int n)
{
	if(n==1)
		return 1/n;
	else 
		return (double)1/n+circuit(n-1);
}

int main(void)
{
	printf("%lf", circuit(5));

    return 0;
}

