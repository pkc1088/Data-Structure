#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num;
	char ch, str[30];

	while(ch!='q')
	{
		printf("ch�� �Է�: "); 
		ch=getchar();
		getchar();
		
		printf("str�� �Է�: "); 
		scanf("%[^\n]s", str);
		
		printf("num�� �Է�: "); 
		scanf("%d", &num);
		getchar();
		printf("��� : %c %s %d\n\n", ch, str, num);
	}
	
	
	
	return 0;
}

