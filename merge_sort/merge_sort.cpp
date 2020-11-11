#include<iostream>
using namespace std;

int* assist;

void merge(int a[], int lo, int mid, int hi)	//������lo��midΪһ�����飬������mid+1������hiΪ��һ�����飬
{												//������a�е���������������ݺϲ���һ������Ĵ��飨��lo��hi��
	//��������ָ��
	int i = lo;
	int p1 = lo;
	int p2 = mid + 1;

	//�������ƶ�p1ָ���p2ָ�룬�Ƚ϶�Ӧ����������ֵ���ҳ���С���Ǹ����ŵ���������Ķ�Ӧ��������
	while (p1 <= mid && p2 <= hi)
	{
		//�Ƚ϶�Ӧ��������ֵ
		if (a[p1] < a[p2])
		{
			assist[i++] = a[p1++];
		}
		else
		{
			assist[i++] = a[p2++];
		}
	}

	//���������p1��ָ��û�����꣬��ô˳���ƶ�p1ָ�룬�Ѷ�Ӧ��Ԫ�طŵ���������Ķ�Ӧ������
	while (p1 <= mid)		//˵��p2�����꣬�˳�ѭ������p1��û������
	{
		assist[i++] = a[p1++];
	}

	//���������p2��ָ��û�����꣬��ô˳���ƶ�p2ָ�룬�Ѷ�Ӧ��Ԫ�طŵ���������Ķ�Ӧ������
	while (p2 <= hi)		//˵��p1�����꣬������p2���������ѭ��ֻ�����һ��
	{
		assist[i++] = a[p2++];
	}

	//�Ѹ��������е�Ԫ�ؿ�����ԭ���鵱��
	for (int index = lo; index <= hi; index++)
	{
		a[index] = assist[index];
	}
}

void sort(int a[], int lo, int hi)	//������a�д�����lo������hi֮���Ԫ�ؽ�������
{
	//��ȫ�Լ���
	if (hi <= lo)
	{
		return;
	}

	//��lo��hi֮������ݷ�Ϊ������
	int mid = lo + (hi - lo) / 2;

	//�ֱ��ÿһ���������
	sort(a, lo, mid);
	sort(a, mid + 1, hi);

	//�ٰ��������е����ݽ��й鲢
	merge(a, lo, mid, hi);
}

void sort(int a[], int sz)	//�������ڵ�Ԫ�ؽ�������
{
	//��ʼ����������assist
	assist = new int[sz];

	//����һ��lo������hi�������ֱ��¼��������С����������������
	int lo = 0;
	int hi = sz - 1;

	//����sort���صķ����������a�У�������lo������hi��Ԫ�ص�����
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
