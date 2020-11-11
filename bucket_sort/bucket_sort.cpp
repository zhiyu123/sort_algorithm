#include<iostream>
#include<list>
#include<vector>
using namespace std;

double* BucketSort(double array[], int sz) 
{
	//1.得到数列的最大值和最小值，并算出差值d
	double max = array[0];
	double min = array[0];
	for (int i = 1; i < sz; i++) 
	{
		if (array[i] > max) 
		{
			max = array[i];
		}
		if (array[i] < min) 
		{
			min = array[i];
		}
	}
	double d = max - min;			//计算差值

	//2 .初始化桶
	int bucketNum = sz;				//桶数量等于原始数组的数量
	vector<list<double>> bucket_array;			//所有的桶都保存在bucket_array中，每一个桶中定义成一个链表（list<double>）
	bucket_array.resize(bucketNum);				//初始化桶的数量

	//3.遍历原始数组，将每个元素放入桶中
	for (int i = 0; i < sz; i++) 
	{
		int num = (int)((array[i] - min) * (bucketNum - 1) / d); //定位元素属于第几个桶的公式（桶的数量从0开始数）
		bucket_array[num].push_back(array[i]);			//在vector中的list上面push元素
	}

	//4.对每个通内部进行排序
	for (int i = 0; i < bucket_array.size(); i++) 
	{
		bucket_array[i].sort();		
	}

	//5.输出全部元素
	double* SortedArray = new double[sz]; 
	int index = 0;
	for (int i = 0; i < bucket_array.size(); i++) 
	{
		for (list<double>::const_iterator it_ptr = bucket_array[i].begin(); it_ptr != bucket_array[i].end(); it_ptr++)
		{
			SortedArray[index] = *it_ptr; 
			index++;
		}
	}
	return SortedArray;
}

int main()
{
	double array[] = { 4.12, 6.421, 0.0023, 3.0, 2.123, 8.122, 4.12, 10.09 };
	int sz = sizeof(array) / sizeof(array[0]);
	double* SortedArray = BucketSort(array, sz);
	for (int i = 0; i < sz; i++)
	{
		cout << SortedArray[i] << " ";
	}
	cout << endl;
	return 0;
}
