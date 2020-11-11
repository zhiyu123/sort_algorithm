#include<iostream>
#include<list>
#include<vector>
using namespace std;

double* BucketSort(double array[], int sz) 
{
	//1.�õ����е����ֵ����Сֵ���������ֵd
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
	double d = max - min;			//�����ֵ

	//2 .��ʼ��Ͱ
	int bucketNum = sz;				//Ͱ��������ԭʼ���������
	vector<list<double>> bucket_array;			//���е�Ͱ��������bucket_array�У�ÿһ��Ͱ�ж����һ������list<double>��
	bucket_array.resize(bucketNum);				//��ʼ��Ͱ������

	//3.����ԭʼ���飬��ÿ��Ԫ�ط���Ͱ��
	for (int i = 0; i < sz; i++) 
	{
		int num = (int)((array[i] - min) * (bucketNum - 1) / d); //��λԪ�����ڵڼ���Ͱ�Ĺ�ʽ��Ͱ��������0��ʼ����
		bucket_array[num].push_back(array[i]);			//��vector�е�list����pushԪ��
	}

	//4.��ÿ��ͨ�ڲ���������
	for (int i = 0; i < bucket_array.size(); i++) 
	{
		bucket_array[i].sort();		
	}

	//5.���ȫ��Ԫ��
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
