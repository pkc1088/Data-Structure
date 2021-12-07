#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Ackermann(int m, int n)
{
	if(m==0)
		return n+1;
	else if(n==0)
		return Ackermann(m-1,1);
	else 
		return Ackermann(m-1, Ackermann(m,n-1));
}


int main(void)
{
	printf("%d %d\n", Ackermann(3,2), Ackermann(2,3));

    return 0;
}

