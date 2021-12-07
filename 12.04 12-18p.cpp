#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE]={5, 4, 3, 2, 1, 9, 7, 8, 6, 3};
int n;

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	int middle = (left + right) / 2;
	
	if (left < right)
	{
		if (right < middle) 
			pivot = list[right];
		else 
		{
			if (left < middle) 
				pivot = list[middle];
			else 
				pivot = list[left];
		}
	}
	else 
	{
		if (left < middle)
			pivot = list[left];
		else 
		{
			if (right < middle) 
				pivot = list[middle];
			else 
			
				pivot = list[right];
		}
	}

	printf("pivot is %d\n", pivot);
	do {
		do
			low++;
		while (list[low]<pivot);
		
		do
			high--;
		while (list[high]>pivot);
		
		if (low<high) 
			SWAP(list[low], list[high], temp);
	} while (low<high);

	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left<right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main(void)
{
    n = MAX_SIZE;
    quick_sort(list, 0, n-1);
    for (int a = 0; a < n; a++)
        printf("%d ", list[a]);
    printf("\n");
	return 0;
}
