#include<stdio.h>

void swap(int* a, int* b)			//交换
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int* arr, int sz)
{
	int i, j;
	for (i = 0; i < sz - 1; i++)			//n个元素，只需经过n-1次排序即可
	{
		int min = i;						//设第一个元素为最小值，将其下标赋值给min
		for (j = i + 1; j < sz; j++)	  //遍历未排序的元素
		{
			if (arr[j] < arr[min])		 //找到目前最小值
			{
				min = j;				 //记录最小值的下标
			}
		}
		swap(&arr[min], &arr[i]);		 //做交換
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