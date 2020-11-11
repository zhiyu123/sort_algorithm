#include<iostream>
using namespace std;

int* assist;

void merge(int a[], int lo, int mid, int hi)	//从索引lo到mid为一个子组，从索引mid+1到索引hi为另一个子组，
{												//把数组a中的这两个子组的数据合并到一个有序的大组（从lo到hi）
	//定义三个指针
	int i = lo;
	int p1 = lo;
	int p2 = mid + 1;

	//遍历，移动p1指针和p2指针，比较对应的索引处的值，找出最小的那个，放到辅助数组的对应的索引处
	while (p1 <= mid && p2 <= hi)
	{
		//比较对应索引处的值
		if (a[p1] < a[p2])
		{
			assist[i++] = a[p1++];
		}
		else
		{
			assist[i++] = a[p2++];
		}
	}

	//遍历，如果p1的指针没有走完，那么顺序移动p1指针，把对应的元素放到辅助数组的对应索引处
	while (p1 <= mid)		//说明p2已走完，退出循环，但p1还没有走完
	{
		assist[i++] = a[p1++];
	}

	//遍历，如果p2的指针没有走完，那么顺序移动p2指针，把对应的元素放到辅助数组的对应索引处
	while (p2 <= hi)		//说明p1已走完，继续走p2，这里，两个循环只会进入一个
	{
		assist[i++] = a[p2++];
	}

	//把辅助数组中的元素拷贝的原数组当中
	for (int index = lo; index <= hi; index++)
	{
		a[index] = assist[index];
	}
}

void sort(int a[], int lo, int hi)	//对数组a中从索引lo到索引hi之间的元素进行排序
{
	//安全性检验
	if (hi <= lo)
	{
		return;
	}

	//对lo到hi之间的数据分为两个组
	int mid = lo + (hi - lo) / 2;

	//分别对每一组进行排序
	sort(a, lo, mid);
	sort(a, mid + 1, hi);

	//再把两个组中的数据进行归并
	merge(a, lo, mid, hi);
}

void sort(int a[], int sz)	//对数组内的元素进行排序
{
	//初始化辅助数组assist
	assist = new int[sz];

	//定义一个lo变量和hi变量，分别记录数组中最小的索引和最大的索引
	int lo = 0;
	int hi = sz - 1;

	//调用sort重载的方法完成数组a中，从索引lo到索引hi的元素的排序
	sort(a, lo, hi);
}


void print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int arr[10] = { 21, 32, 5, 3, 67, 43, 42, 1, 3, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	sort(arr, sz);
	print(arr, sz);
	return 0;
}
