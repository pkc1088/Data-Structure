#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void unknown()
{
	int ch;
	if( (ch=getchar()) != '\n')
		unknown();
	putchar(ch);
}

int main(void)
{
	unknown();
    return 0;
}

