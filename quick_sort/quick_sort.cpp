#include<iostream>
using namespace std;

int partition(int a[], int lo, int hi)
{
	//确定分界值
	int key = a[lo];
	int left = lo;			//左指针
	int right = hi + 1;		//右指针
	
	//切分
	while (true)
	{
		//先从右往左扫描，移动right指针，找到一个比分界值小的元素，停止right
		while (key <  a[--right])		//当分界值小于right所指向的值的时候，循环继续，- -是为了指向最后一个元素
		{
			if (right == lo)
			{
				break;
			}
		}
		//再从左往右扫描，移动left指针，找到一个比分界值大的元素，停止left
		while (a[++left] < key)
		{
			if (left == hi)
			{
				break;
			}
		}
		//判断left >= hight,如果是，则证明元素扫描完毕，结束循环，如果不是，交换元素即可
		if (left >= right)
		{
			break;
		}
		else
		{
			int tmp = a[right];
			a[right] = a[left];
			a[left] = tmp;
		}
	}
	int tmp1 = a[right];
	a[right] = a[lo];
	a[lo] = tmp1;				//最后交换分界值和right的值，这里交换和返回一定要用right，因为left是先++的，可能会大于分界值
	return right;			//返回新的分界值下标，即right的值
}

void sort(int a[], int lo, int hi)
{
	if (hi <= lo)
	{
		return;
	}

	//需要对lo索引到hi索引的元素进行分组（左子组和右子组）
	int par = partition(a, lo, hi);		//返回的是分组的分界值所在的索引，分界值位置变换之后的索引

	//让左子组有序
	sort(a, lo, par - 1);

	//让右子组有序
	sort(a, par + 1, hi);
}

void sort(int a[], int sz)
{
	int lo = 0;
	int hi = sz - 1;
	sort(a, lo, hi);
}

int main()
{
	int arr[10] = { 4, 33, 1, 64, 5, 87, 3, 13, 54, 75 };	
	int sz = sizeof(arr) / sizeof(arr[0]);
	sort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}