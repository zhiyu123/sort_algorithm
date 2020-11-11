#include<iostream>
using namespace std;

int partition(int a[], int lo, int hi)
{
	//ȷ���ֽ�ֵ
	int key = a[lo];
	int left = lo;			//��ָ��
	int right = hi + 1;		//��ָ��
	
	//�з�
	while (true)
	{
		//�ȴ�������ɨ�裬�ƶ�rightָ�룬�ҵ�һ���ȷֽ�ֵС��Ԫ�أ�ֹͣright
		while (key <  a[--right])		//���ֽ�ֵС��right��ָ���ֵ��ʱ��ѭ��������- -��Ϊ��ָ�����һ��Ԫ��
		{
			if (right == lo)
			{
				break;
			}
		}
		//�ٴ�������ɨ�裬�ƶ�leftָ�룬�ҵ�һ���ȷֽ�ֵ���Ԫ�أ�ֹͣleft
		while (a[++left] < key)
		{
			if (left == hi)
			{
				break;
			}
		}
		//�ж�left >= hight,����ǣ���֤��Ԫ��ɨ����ϣ�����ѭ����������ǣ�����Ԫ�ؼ���
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
	a[lo] = tmp1;				//��󽻻��ֽ�ֵ��right��ֵ�����ｻ���ͷ���һ��Ҫ��right����Ϊleft����++�ģ����ܻ���ڷֽ�ֵ
	return right;			//�����µķֽ�ֵ�±꣬��right��ֵ
}

void sort(int a[], int lo, int hi)
{
	if (hi <= lo)
	{
		return;
	}

	//��Ҫ��lo������hi������Ԫ�ؽ��з��飨������������飩
	int par = partition(a, lo, hi);		//���ص��Ƿ���ķֽ�ֵ���ڵ��������ֽ�ֵλ�ñ任֮�������

	//������������
	sort(a, lo, par - 1);

	//������������
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