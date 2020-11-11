#include<stdio.h>

void insertion_sort(int arr[], int sz)
{
	int i, j, temp;
	for (i = 1; i < sz; i++)	//����һ��������������ģ�ʣ�µĵ���δ����ģ����Դ��±�Ϊ1��Ҳ���ǵڶ���Ԫ�ؿ�ʼ����		
	{
		temp = arr[i];			//ÿ�ν��Ƚϵ�Ԫ�ر�����������Ϊ�ڱȽϵĹ�����Ҫ������Ԫ�أ��Ὣ�串�ǵ�
		for (j = i; j > 0 && arr[j - 1] > temp; j--) // ����������ź���Ķ��У��ʹ�����Ԫ�رȽ�
		{
			arr[j] = arr[j - 1];	//������ź����Ԫ�رȴ�����Ԫ�ش���������������ƶ�һλ
		}
		arr[j] = temp;	//����ѭ��˵��j == 0�ˣ��Ǿ����±�Ϊ0������������Ԫ�أ�
						//��������������±�Ϊ��j - 1����Ԫ��û�д��ڴ�����Ԫ�أ��Ǿ��������j�����������Ԫ�ؼ���
	}
}

void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 4, 3, 2, 10, 12, 1, 5, 6 };
	int sz = 0;
	sz = sizeof(arr) / sizeof(arr[0]);
	insertion_sort(arr, sz);
	print(arr, sz);
	return 0;
}