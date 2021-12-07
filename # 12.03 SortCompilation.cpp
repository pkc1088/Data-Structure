#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;
void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 	// �ּҰ� Ž��
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
	}
}


void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i<n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j]>key; j--)
			list[j + 1] = list[j]; /* ���ڵ��� ������ �̵� */
		list[j + 1] = key;
	}
}


void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = n - 1; i>0; i--) {
		for (j = 0; j<i; j++)
			/* �յ��� ���ڵ带 ���� �� ��ü */
			if (list[j]>list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}
}


inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key<list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}
void shell_sort(int list[], int n)   // n = size
{
	int i, gap;
	for (gap = n / 2; gap>0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i<gap; i++)		// �κ� ����Ʈ�� ������ gap
			inc_insertion_sort(list, i, n - 1, gap);
	}
}


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


int compare(const void *arg1, const void *arg2)
{
	if (*(double *)arg1 > *(double *)arg2) return 1;
	else if (*(double *)arg1 == *(double *)arg2) return 0;
	else return -1;
}


int sorted[MAX_SIZE];  
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;

	/* ���� ���ĵ� list�� �պ� */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i>mid)	/* ���� �ִ� ���ڵ��� �ϰ� ���� */
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else	/* ���� �ִ� ���ڵ��� �ϰ� ���� */
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	/* �迭 sorted[]�� ����Ʈ�� �迭 list[]�� �纹�� */
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left<right) {
		mid = (left + right) / 2;     /* ����Ʈ�� �յ� ���� */
		merge_sort(list, left, mid);    /* �κ� ����Ʈ ���� */
		merge_sort(list, mid + 1, right); /* �κ� ����Ʈ ���� */
		merge(list, left, mid, right);    /* �պ� */
	}
}


int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i<n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 100; 

	quick_sort(list, 0, n-1); // ������ ȣ�� 
	for (i = 0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
	
	double list[5] = { 2.1, 0.9, 1.6, 3.8, 1.2 };
	qsort((void *)list, (size_t)5, sizeof(double), compare);
	for (i = 0; i<5; i++)
		printf("%.2f ", list[i]);
	return 0;
}
