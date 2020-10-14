#include<stdio.h>

void insertion_sort(int arr[], int sz)
{
	int i, j, temp;
	for (i = 1; i < sz; i++) 
	{
		temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 23, 42, 5, 1, 43, 5, 76, 53, 23, 34 };
	int sz = 0;
	sz = sizeof(arr) / sizeof(arr[0]);
	insertion_sort(arr, sz);
	print(arr, sz);
	return 0;
}