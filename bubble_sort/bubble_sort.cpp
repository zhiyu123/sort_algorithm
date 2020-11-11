#include<iostream>
using namespace std;

void bubble_sort(int *arr, int sz)						//������ð������
{
	for (int i = 1; i < sz; i++)		//���ѭ������������ΪԪ��������1
	{
		for (int j = 0; j < sz - i; j++)		//�ڲ�ѭ��Ϊһ���н����Ĵ�����ΪԪ������������
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

void bubble_sort_plus(int* arr, int sz)					//ð�������Ż��汾
{
	for (int i = 1; i < sz; i++)		//���ѭ������������ΪԪ��������1
	{
		bool flag = true;		//�����ǣ�ÿһ�ֵĳ�ʼΪtrue
		for (int j = 0; j < sz - i; j++)		//�ڲ�ѭ��Ϊһ���н����Ĵ�����ΪԪ������������
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = false;					//�����Ԫ�ؽ���˵����������ģ���Ǳ�Ϊfalse
			}
		}
		if (flag)
		{
			break;		//���û�н�����˵�������Ѿ���������ˣ���ֱ���˳�������ѭ��
		}
	}
}

void bubble_sort_plus_plus(int* arr, int sz)							//ð�������Ż��汾���Ż��汾
{			
	int last_exchange_index = 0;		//��¼���һ�ν�����λ��
	int sort_border = sz - 1;			//�������еı߽磬ÿ�αȽ�ֻ��Ҫ�Ƚϵ�����Ϳ����ˣ�����϶��������,��ʼΪ���һ��Ԫ��

	for (int i = 1; i < sz; i++)		//���ѭ������������ΪԪ��������1
	{
		bool flag = true;		//�����ǣ�ÿһ�ֵĳ�ʼΪtrue
		for (int j = 0; j < sort_border; j++)		//�ڲ�ѭ��Ϊһ���н����Ĵ�����ΪԪ������������
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				flag = false;						//�����Ԫ�ؽ���˵����������ģ���Ǳ�Ϊfalse

				last_exchange_index = j;			//���������еı߽����Ϊ���һ�ν���Ԫ�ص�λ��
			}
		}
		sort_border = last_exchange_index;			//ÿ�ν���ѭ��������������еı߽磬����ѭ������Ϊ�������еı߽�ֵ
		if (flag)
		{
			break;		//���û�н�����˵�������Ѿ���������ˣ���ֱ���˳�������ѭ��
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