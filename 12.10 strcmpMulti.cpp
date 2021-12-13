#include <stdio.h>
#include <string.h>

int main(void){
	char a[4][10]={"hello wh", "hey", "what", "why"};
	char find[10]="hello wh";
	char replace[10]="zzz ZZ";

	printf("a : %s\n", a[0]);
	for(char *p=a[0]; *p!=NULL; p++)
	{
		if(strcmp(p, find)==0)
		{
			strcpy(p, replace);
		}
	}
	
	printf("a : %s\n", a[0]);
	
	return 0;
}
