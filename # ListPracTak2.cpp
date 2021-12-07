#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct add{
	char name[40];
	struct add *next;
}list;

struct add *start;
struct add *last;
struct add *top;

struct add *store(struct add *info, struct add *top)
{
	start = top;
	
	if(last==NULL)
	{
		info->next=NULL;
		last=info;
		return info;
	}
	return start;
	
}
struct add *search(struct add *top, char *name)
{
	while(top)
	{
		if(!strcmp(name, top->name))
			return top;
		top=top->next;
	}
	return NULL;
}

void display(struct add *top)
{
	while(top)
	{
		printf("Name : %s\n", top->name);
		top=top->next;
	}
}

void display2(void)
{
	struct add *top;
	top=start;
	while(top){
		printf("%s\n", top->name);
	top=top->next;
	}
}

int menu(void)
{
	char select[10];
	int num;
	
	do{
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Search\n");
		printf("5. Sort\n");
		printf("6. Save\n");
		printf("7. Load\n");
		printf("8. Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &num);
	}while(num!=8);
}

int main(void)
{
	struct add *info;
	struct add *info2;
	struct add *top;
	struct add *temp;
	int choice;
	start=NULL;
	last=NULL;	
 
 	for(;;)
 	{
 		choice = menu();
 		switch(choice){
 			case 1:
 				break;
 			case 2:
 				break;
 			case 3:
 				display2();
 				break;
			 case 8:
 				exit(0);
		 }
	 }
 
 
 
 
 
 
	info = (struct add *)malloc(sizeof(list));
	info2 = (struct add *)malloc(sizeof(struct add *));
	strcpy(info->name, "Tom");
	strcpy(info2->name, "Max");
	info->next=info2;
	info2->next=NULL;
	
	display(info);
	
	temp=search(info, "Tom2");
	
	if(temp)
		display(temp);
	else
		printf("Data is not found");

	free(info);
	free(info2);
	return 0;
}

