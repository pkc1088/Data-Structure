#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CoEffi(int n, int k)
{
	if(k==0 || k==n)
		return 1;
	else
		return CoEffi(n-1, k-1)+CoEffi(n-1, k);
}

int main(void)
{
	printf("%d\n", CoEffi(7, 4));	//35

    return 0;
}

