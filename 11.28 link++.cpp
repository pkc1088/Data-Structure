#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct linked{
	char *str;
	int info;
	struct linked *ptr;
};
int main(void)
{
	static struct linked link[]={{"car",4,link+3}, {"License",4,link+4}, {"Computer",2,link+1},
								 {"Bank",1,link+2}, {"Data",3,link}};			
	struct linked *ptr = link+1;
	
	printf("(1) %s \n", (++ptr)->ptr->str);
	printf("(2) %s \n", link->str);
	printf("(3) %s \n", link[2].ptr->str);
	printf("(4) %s \n", link[1].str++);
	printf("(5) %s \n", ++link[ptr->ptr->info].str);
	printf("(6) %s \n", link[--(ptr->info)].str);
	printf("%s %s %s %s\n", ptr->str, link[1].str, link[2].str, link[4].str);
    return 0;
}

