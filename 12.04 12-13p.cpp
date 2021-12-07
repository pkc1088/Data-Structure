#include <stdio.h>
#include <string.h>
#define NAME_SIZE 10
#define MAX_SIZE 10

struct record{
	int key;
	char name[NAME_SIZE];
};

struct recordType{
	struct record list[MAX_SIZE];
};

void insertion_sort(struct recordType RT[], int n)
{
	int i, j, xkey;	char xname[NAME_SIZE];
	for (i = 1; i<n; i++) 
	{
		xkey = RT->list[i].key;
		strcpy(xname , RT->list[i].name);
		for (j = i - 1; j >= 0 && RT->list[j].key > xkey; j--)
		{
			RT->list[j+1].key = RT->list[j].key; 
			strcpy(RT->list[j+1].name , RT->list[j].name);
		}
		RT->list[j+1].key = xkey;
		strcpy(RT->list[j+1].name , xname);
	}
}

int main(void)
{
	struct record r1={3, "max"}, r2={2, "tom"}, r3={1, "cat"}, r4={5, "dog"}, r5={4, "fish"}, r6={6, "rat"};
	struct recordType RT;
	RT.list[0]=r1, RT.list[1]=r2, RT.list[2]=r3, RT.list[3]=r4, RT.list[4]=r5, RT.list[5]=r6;
	
	insertion_sort(&RT, 6);
	
	for(int i=0; i<6; i++)
		printf("%d %s\n", RT.list[i].key, RT.list[i].name);
	
	
	return 0;
}
