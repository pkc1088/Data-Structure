#include <stdio.h>

void get_quotes(int num,char **q)
{
	char *quot1 = "what the fuck";
	
   	if (num == 1)
   	{
      *q = quot1;
   	}
   	
	if (num == 2)
   	{
      *q = "Whatever you do, make it pay";
   	}
}
int main(void)
{
   int a;
   char *qu;
   
   scanf("%d", &a);
   get_quotes(a, &qu);
   printf("%s", qu);
   
   return 0;
}

/*
#include <stdio.h>

void print_str(char **pps, int cnt)
{
	int i;
	for(i=0; i<cnt; i++)
		printf("%s\n", pps[i]); 

}

int main(void)
{
	char *pt_ary[] = {"eagle", "tiger", "lion", "squirel"}; 
	int count;

	count = sizeof(pt_ary) / sizeof(pt_ary[0]);
	print_str(pt_ary, count);

	return 0;
}
*/
