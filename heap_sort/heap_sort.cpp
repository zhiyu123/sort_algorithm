#include<iostream>
using namespace std;

void Sink(int heap[], int target, int range)	//��heap���У���target����Ԫ�����³�
{
	while (2 * target <= range)		//����Ҷ�ӽڵ�
	{
		//�ҳ���ǰ�ڵ�Ľϴ��ӽڵ�
		int max = 0;
		if (2 * target + 1 <= range)		//�����ӽڵ�
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

			target = max;			//��������ֵ
		}
	}
}

void CreateHeap(int source[], int heap[], int sz)	//����ԭ����source���������heap
{
	//��source�е�Ԫ�ؿ�����heap�У�heap��Ԫ�ؾ��γ���һ������Ķ�
	for (int i = 0; i < sz; i++)
	{
		heap[i + 1] = source[i]; 
	}

	//�Զ��е�Ԫ�����³��������Ӷ����������һ�봦��ʼ�������� 1 ��ɨ�裩����Ϊ���������������һ��Ķ�ΪҶ�ӽڵ㣬�Ͳ���Ҫ�³�
	for (int i = (sz / 2); i > 0; i--)		//�¹������Ķ������������ԭ������ĳ���sz
	{
		Sink(heap, i, sz);			//��ÿ��Ԫ���³���sz����heap�����һ����������
	}
}

void Sort(int source[], int sz)		//��source�����е����ݴ�С��������
{
	//������
	int* heap = new int[sz + 1];		//Ϊ�˷��㣬������ʱ��ԭ�����һ�����ȣ���ΪҪ������1����ʼ��Ԫ��
	CreateHeap(source, heap, sz);

	//����һ����������¼δ�����Ԫ���е���������
	int N = sz;

	//ͨ��ѭ��������1��������Ԫ�غͻ�δ�����Ԫ����������������Ԫ��
	while (N != 1)			//N == 1��ʣ���һ��Ԫ���ˣ����˳�ѭ��
	{
		//����Ԫ��
		int tmp = heap[N];
		heap[N] = heap[1];
		heap[1] = tmp;

		//���򽻻������Ԫ�����ڵ�������������Ҫ����ѵ��³�����
		N--;

		//��Ҫ������1����Ԫ�ؽ��жѵ��³�����
		Sink(heap, 1, N);
	}
	//��heap�е����ݸ��Ƶ�Դ����source��
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