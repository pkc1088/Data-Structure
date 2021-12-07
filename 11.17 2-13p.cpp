#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int circuit(int n)
{
	if(n==0)
		return n;
	else 
		return n+circuit(n-1);
}

int main(void)
{
	printf("%d", circuit(10));

    return 0;
}

