#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define INDEX_MAX 10

struct itable{
  int key;
  int index;
};
int list[100];
struct itable indexTable[INDEX_MAX];

void MakeIndexTable(int list[], int size)
{
	printf("****index 출력****\n");
	for(int i=0; i*size<100; i++)
	{
		indexTable[i].index = i*size;
		indexTable[i].key = list[i*size];
		printf("%d %d\n", indexTable[i].key, indexTable[i].index);
	}
	printf("\n");
}

int seq_search(int key, int low, int high)
{
  int i;
  list[high+1] = key;
  for(i= low; list[i] != key; i++)
  	;

  if(i == high+1) 
  	return -1; 
  else 
  	return i; 
}

int search_index(int key, int n)
{
  int i,low, high;
  
  if(key < list[0] || key > list[n-1]) 
  	return -1;

  for(i=0; i<INDEX_MAX; i++)
    if(indexTable[i].key <= key && indexTable[i+1].key > key) 
		break;
  
  if(i == INDEX_MAX) 
  {
    low = indexTable[i-1].index;
    high = n;
  }
  else 
  {
    low = indexTable[i].index;
    high = indexTable[i+1].index;
  }
  printf("%d와 %d사이에서 발견\n", low, high); 
  return seq_search(key, low, high);
}

int main(void)
{
	struct itable p;
	for(int i=0; i<100; i++)
	{
		list[i]=i;
	}
	MakeIndexTable(list, 10);
	printf("%d 탐색 완료", search_index(25, 100));
	
	
	return 0;
}
