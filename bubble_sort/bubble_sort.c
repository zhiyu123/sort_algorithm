#include<stdio.h>

void bubble_sort(int *arr, int sz)
{
	int i = 1;
	int j = 0;
	int temp = 0;
	for (i = 1; i < sz; i++)		//外层循环控制趟数，为元素数量减1
	{
		for (j = 0; j < sz - i; j++)		//内层循环为一趟中交换的次数，为元素数量减趟数
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void print(int *arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int sz = 0;
	sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	print(arr, sz);
	return 0;
}