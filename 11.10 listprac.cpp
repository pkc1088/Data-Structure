#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct subject
{
	char name[20];
	char *id;
	int score;
};
int main(void)
{
	struct subject *context=(struct subject*) malloc(sizeof(struct subject*));
	scanf("%s", (context)->name);
	printf("%s\n", context->name);
    
    char s[100];
	context->id=(char *)malloc( sizeof(strlen(s)+1) ); 
	scanf("%s", context->id);
    printf("%s\n", context->id);
	
	
	return 0;
}

