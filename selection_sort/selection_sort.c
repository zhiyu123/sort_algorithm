#include<stdio.h>

void selection_sort(int* arr, int sz)
{
	int i = 1;
	for (i = 1; i < sz; i++)
	{
		int temp = 0;
		int j = 0;
		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[] = { 130, 49, 28, 72, 61, 56, 54, 33, 2, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	selection_sort(arr, sz);
	print(arr, sz);
	printf("\n");
	return 0;
}