#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int recursive(int n)
{
	if(n<1) return -1;
	else return (recursive(n-3)+1);
}
int main(void)
{
	printf("%d",recursive(10));
    return 0;
}

