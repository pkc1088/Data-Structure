#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct add{
	char name[40];
	struct add *next;
}list;

int main(void)
{
	struct add *info;
	struct add *info2;
	struct add *top;
	FILE *fp;
	int dataLength;
	info = (struct add *)malloc(sizeof(list));
	info2 = (struct add *)malloc(sizeof(struct add *));
	strcpy(info->name, "Tom");
	strcpy(info2->name, "Max");
	info->next=info2;
	info2->next=NULL;

	top=info;
	while(top)
	{
		printf("Name : %s\n", top->name);
		top=top->next;
	}
	if( ( fp=fopen("mlist.bin", "wb") )==NULL )	//write(save)
	{
			fprintf(stderr, "cannot write file!\n");
			exit(-1);
	}

	top=info;
	while(top)
	{
		printf("Name : %s\n", top->name);
		dataLength=fwrite(top, sizeof(struct add), 1, fp);
		printf("dadta length : %d\n", dataLength);
		top=top->next;
	}
	fclose(fp);

//======================

	if( ( fp=fopen("mlist.bin", "rb") )==NULL ) //read(load)
	{
		fprintf(stderr, "cannot read file!\n");
		exit(-1);
	}
	
	struct add *info3;
	info3=(struct add *)malloc(sizeof(struct add *));
	if(!info3)
	{
		fprintf(stderr, "Out of memory!\n");
		exit(-1);
	}
	top=NULL;
	
	while(!feof(fp))
	{
		if(1 !=fread(info3, sizeof(struct add), 1, fp))
			break;
		else if(!top)
			top=info;		
		printf("Name : %s\n", top->name);
	
		info3->next=(struct add *)malloc(sizeof(struct add *));
		if(!info3)
		{
		fprintf(stderr, "Out of memory!\n");
		exit(-1);
		}
	}


	free(info);
	free(info2);
	return 0;
}
