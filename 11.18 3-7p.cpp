#include <stdio.h>

struct complex{
	int real;
	int imagine;
};

struct complex complex_add(complex c1, complex c2)
{
	struct complex c3;
	c3.real=c1.real+c2.real;
	c3.imagine=c1.imagine+c2.imagine;
	
	return c3;
}

int main(void) 
{
  	struct complex c1={1,2},c2={3,4};
  	struct complex ans=complex_add(c1,c2);
  	
	printf("%d+%di\n", ans.real, ans.imagine);
    return 0;
}
