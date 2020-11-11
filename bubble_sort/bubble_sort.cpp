#include<iostream>
using namespace std;

void bubble_sort(int *arr, int sz)						//初级版冒泡排序
{
	for (int i = 1; i < sz; i++)		//外层循环控制趟数，为元素数量减1
	{
		for (int j = 0; j < sz - i; j++)		//内层循环为一趟中交换的次数，为元素数量减趟数
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void bubble_sort_plus(int* arr, int sz)					//冒泡排序优化版本
{
	for (int i = 1; i < sz; i++)		//外层循环控制趟数，为元素数量减1
	{
		bool flag = true;		//有序标记，每一轮的初始为true
		for (int j = 0; j < sz - i; j++)		//内层循环为一趟中交换的次数，为元素数量减趟数
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = false;					//如果有元素交换说明不是有序的，标记变为false
			}
		}
		if (flag)
		{
			break;		//如果没有交换，说明序列已经是有序的了，就直接退出躺数的循环
		}
	}
}

void bubble_sort_plus_plus(int* arr, int sz)							//冒泡排序优化版本的优化版本
{			
	int last_exchange_index = 0;		//记录最后一次交换的位置
	int sort_border = sz - 1;			//无序数列的边界，每次比较只需要比较到这里就可以了，后面肯定是有序的,初始为最后一个元素

	for (int i = 1; i < sz; i++)		//外层循环控制趟数，为元素数量减1
	{
		bool flag = true;		//有序标记，每一轮的初始为true
		for (int j = 0; j < sort_border; j++)		//内层循环为一趟中交换的次数，为元素数量减趟数
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				flag = false;						//如果有元素交换说明不是有序的，标记变为false

				last_exchange_index = j;			//把无序数列的边界更新为最后一次交换元素的位置
			}
		}
		sort_border = last_exchange_index;			//每次结束循环后更新无序数列的边界，下趟循环就作为无序数列的边界值
		if (flag)
		{
			break;		//如果没有交换，说明序列已经是有序的了，就直接退出躺数的循环
		}
	}
}

void print(int *arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 3, 2, 4, 3, 1, 5, 6, 7, 8, 9, 10 };
	int sz = 0;
	sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	print(arr, sz);

	bubble_sort_plus(arr, sz);
	print(arr, sz);

	bubble_sort_plus_plus(arr, sz);
	print(arr, sz);
	return 0;
}