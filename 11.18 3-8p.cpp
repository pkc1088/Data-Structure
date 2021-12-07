#include <stdio.h>

void insert(int arr[], int loc, int value)
{
	int brr[10];
	
	for(int i=0; i<10; i++)
		brr[i]=arr[i];
		
	for(int i=loc+1; i<11; i++)
		arr[i]=brr[i-1];
		
	arr[loc]=value;	
}	// 앞에서 부터 

void insert2(int array[], int loc, int value) {
    for(int i = 10 -1; i > loc; i--) {
        array[i] = array[i - 1];
    }
    array[loc] = value;
}	// 뒤에서 부터 

void Delete(int arr[], int loc) 
{
    int temp = arr[loc];
    for (int i = loc; i < 5 - 1; i++)
        arr[i] = arr[i + 1];
    arr[5] = 0;
}	

int main(void) 
{
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	int loc=5, value=100;
  	insert2(arr, loc, value);
  	for(int i=0; i<10; i++)
  		printf("%d ", arr[i]);
  	
  	
    return 0;
}
