#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct list {
	int x;
	char test[20];
	char *sen;
};

int main(void)
{
	struct list** at=(struct list**)malloc(sizeof(struct list *));
  	struct list* newat = (struct list *)malloc(sizeof(struct list));	
	*at=newat;
	
	(*at)->x=100;
	strcpy((*at)->test,"justtesting");
	(*at)->sen="anothertesting";
  	
	  printf("%d  %s  %s\n", (*at)->x, (*at)->test, (*at)->sen);
    
	//////////////////////////////////////////////////////////////

	struct list* st;
	st = (struct list*)malloc(sizeof(struct list));
	
	st->x = 100;
	strcpy(st->test, "justtesting");     
	st->sen="anothertesting";
	
	printf("%d  %s  %s\n", st->x, st->test, st->sen);


	free(st);
	return 0;
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list{
	int n;
	char *sen;
};

int main(void) 
{
	struct list **st=(struct list**)malloc(sizeof(struct list *));
  	struct list *newacc = (struct list *)malloc(sizeof(struct list));	
	*st=newacc;
	
	(*st)->sen="just testing";
	(*st)->n=100;
  	printf("%d %s\n", (*st)->n, (*st)->sen);
    
	return 0;
}
*/
