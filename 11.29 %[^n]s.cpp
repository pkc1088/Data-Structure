#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num;
	char ch, str[30];

	while(ch!='q')
	{
		printf("ch를 입력: "); 
		ch=getchar();
		getchar();
		
		printf("str를 입력: "); 
		scanf("%[^\n]s", str);
		
		printf("num를 입력: "); 
		scanf("%d", &num);
		getchar();
		printf("출력 : %c %s %d\n\n", ch, str, num);
	}
	
	
	
	return 0;
}

