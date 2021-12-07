#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subject
{
	char name[20];
	char id[20];	//char *id; 로 하면 복잡해지는듯..id에도 할당해줘야하는듯.. 
	struct subject *next;
};

char * GetName()
{
	char gname[20];
	scanf("%s", gname);
	return gname;
}

char * GetID()
{
	char gid[20];
	scanf("%s", gid);
	return gid;
}

struct subject * AddSubject()
{
	struct subject *newcontext=(struct subject*) malloc(sizeof(struct subject*));
  	char *xname, *xid;
	
	strcpy(xname, GetName());
	strcpy(xid, GetID());
	strcpy(newcontext->name, xname);
	strcpy(newcontext->id, xid);
	
	return newcontext;
}
int main(void)
{
	struct subject *context=(struct subject*) malloc(sizeof(struct subject*));
	strcpy(context->name, "Math");
	strcpy(context->id, "123");
	
	struct subject *context2=(struct subject*) malloc(sizeof(struct subject*));
  	strcpy(context2->name, "Science");
	strcpy(context2->id, "456");

	struct subject *context3=(struct subject*) malloc(sizeof(struct subject*));
  	scanf("%s", &context3->name);
  	scanf("%s", &context3->id);
  	
	context->next=context2;
	context2->next=context3;
	context3->next=NULL;
	
	
	while(context!=NULL)
	{
  		printf( "%s %s\n", context->name, context->id );
		context=context->next;
	}
  	
	return 0;
}

