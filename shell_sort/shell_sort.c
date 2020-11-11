#include<stdio.h>

void shell_sort(int arr[], int sz)
{
	int h = sz / 2;			//初始增量为序列长度一半
	while (h >= 1)		//增量最小值为1
	{
		for (int i = h; i < sz; i++)	//每次第一个比较的元素都是下标为h的元素
		{
			for (int j = i; j >= h; j -= h)  
			{
				if (arr[j - h] > arr[j])
				{
					int tmp = arr[j];
					arr[j] = arr[j - h];
					arr[j - h] = tmp;
				}
				else
				{
					break;
				}
			}
		}
		h = h / 2;		//增长量每次减少一半
	}
}

void print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
	int sz = sizeof(arr) / sizeof(arr[0]);
	shell_sort(arr, sz);
	print(arr, sz);
	return 0;
}