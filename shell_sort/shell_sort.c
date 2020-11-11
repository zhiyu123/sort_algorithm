#include<stdio.h>

void shell_sort(int arr[], int sz)
{
	int h = sz / 2;			//��ʼ����Ϊ���г���һ��
	while (h >= 1)		//������СֵΪ1
	{
		for (int i = h; i < sz; i++)	//ÿ�ε�һ���Ƚϵ�Ԫ�ض����±�Ϊh��Ԫ��
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
		h = h / 2;		//������ÿ�μ���һ��
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