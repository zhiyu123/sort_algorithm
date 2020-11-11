#include<iostream>
using namespace std;

void Sink(int heap[], int target, int range)	//在heap堆中，对target处的元素做下沉
{
	while (2 * target <= range)		//不是叶子节点
	{
		//找出当前节点的较大子节点
		int max = 0;
		if (2 * target + 1 <= range)		//有右子节点
		{
			if (heap[2 * target] < heap[2 * target + 1])
			{
				max = 2 * target + 1;
			}
			else
			{
				max = 2 * target;
			}
		}
		else
		{
			max = 2 * target;
		}

		if (heap[target] >= heap[max])
		{
			break;
		}
		else
		{
			int tmp = heap[max];
			heap[max] = heap[target];
			heap[target] = tmp;

			target = max;			//更新索引值
		}
	}
}

void CreateHeap(int source[], int heap[], int sz)	//根据原数组source，构造出堆heap
{
	//把source中的元素拷贝到heap中，heap的元素就形成了一个无序的堆
	for (int i = 0; i < sz; i++)
	{
		heap[i + 1] = source[i]; 
	}

	//对堆中的元素做下沉调整（从堆最大索引的一半处开始，往索引 1 处扫描），因为索引超出最大索引一半的都为叶子节点，就不需要下沉
	for (int i = (sz / 2); i > 0; i--)		//新构建出的堆最大索引就是原来数组的长度sz
	{
		Sink(heap, i, sz);			//对每个元素下沉，sz代表heap中最后一个结点的索引
	}
}

void Sort(int source[], int sz)		//对source数组中的数据从小到大排序
{
	//构建堆
	int* heap = new int[sz + 1];		//为了方便，构建堆时比原数组多一个长度，因为要从索引1处开始放元素
	CreateHeap(source, heap, sz);

	//定义一个变量，记录未排序的元素中的最大的索引
	int N = sz;

	//通过循环，交换1索引处的元素和还未排序的元素中最大的索引处的元素
	while (N != 1)			//N == 1就剩最后一个元素了，则退出循环
	{
		//交换元素
		int tmp = heap[N];
		heap[N] = heap[1];
		heap[1] = tmp;

		//排序交换后最大元素所在的索引，让他不要参与堆得下沉调整
		N--;

		//需要对索引1处的元素进行堆的下沉调整
		Sink(heap, 1, N);
	}
	//把heap中的数据复制到源数组source中
	for (int i = 1; i < sz + 1; i++)
	{
		source[i - 1] = heap[i];
	}
}

int main()
{
	int arr[] = { 10,4,66,7,33,1,22,43,78,12,21 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}