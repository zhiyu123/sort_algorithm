#include<stdio.h>

void insertion_sort(int arr[], int sz)
{
	int i, j, temp;
	for (i = 1; i < sz; i++)	//将第一个数当成已排序的，剩下的当成未排序的，所以从下标为1，也就是第二个元素开始排序		
	{
		temp = arr[i];			//每次将比较的元素保存下来，因为在比较的过程中要往后移元素，会将其覆盖掉
		for (j = i; j > 0 && arr[j - 1] > temp; j--) // 逆序遍历已排好序的队列，和待插入元素比较
		{
			arr[j] = arr[j - 1];	//如果已排好序的元素比待插入元素大，则将已排序的往后移动一位
		}
		arr[j] = temp;	//结束循环说明j == 0了，那就在下标为0处插入待插入的元素，
						//或者是已排序的下标为（j - 1）的元素没有大于待插入元素，那就在其后面j处插入待插入元素即可
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
	int arr[] = { 4, 3, 2, 10, 12, 1, 5, 6 };
	int sz = 0;
	sz = sizeof(arr) / sizeof(arr[0]);
	insertion_sort(arr, sz);
	print(arr, sz);
	return 0;
}