#include <stdio.h>
#define MAX_SIZE 8
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE]={67, 90, 57, 25, 84, 32, 73, 54};
int n;
int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low]<pivot);
		
		do
			high--;
		while (high >= left && list[high]>pivot);
		
		for(int i=0; i<n; i++)
			printf("%d ", list[i]);
		printf("\nlow=%d, high=%d\n\n", low, high);

		if (low<high) 
			SWAP(list[low], list[high], temp);
	} while (low<high);

	SWAP(list[left], list[high], temp);

	return high;
}
void quick_sort(int list[], int left, int right)
{
	if (left<right) 
	{
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
	
}


int main(void)
{
	n=MAX_SIZE;
	quick_sort(list, 0, n-1);

	
	return 0;
}
