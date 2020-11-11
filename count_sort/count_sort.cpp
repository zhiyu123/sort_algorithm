#include<iostream>
using namespace std;

int* count_sort(int array[], int sz)              //���صļ�������
{
    //1.�õ����е����ֵ
    int max = array[0];
    for (int i = 1; i < sz; i++) 
    {
        if (array[i] > max) 
        {
            max = array[i];
        }
    }
    
    //2.�����������ֵȷ��ͳ������ĳ���
    int* countArray = new int[max + 1]();           //()�ǳ�ʼ��Ϊ0

    //3.�������У����ͳ������
    for (int i = 0; i < sz; i++) 
    {
        countArray[array[i]]++;
    }

    //4.����ͳ�����飬������
    int index = 0;              //�ź������������
    int* sortArray = new int[sz];           //�����ź����Ԫ�ص�����
    for (int i = 0; i < max + 1; i++)//max + 1��countArray����ĳ��ȣ����ѭ���Ǳ�������������±�,Ҳ���Ƕ�Ӧ��Ԫ��ֵ       
    {
        for (int j = 0; j < countArray[i]; j++)     //�ڲ�ѭ����ÿһ�������洢���������������
        {
            sortArray[index++] = i;
        }
    }
    return sortArray;
}

int* count_sort_plus(int array[], int sz)                 //���װ��������
{
    //1.�õ����е����ֵ����Сֵ���������ֵd
    int max = array[0];
    int min = array[0];
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
    int d = max - min;          //�����ֵ����ȷ��ͳ������ĳ���

    //2.����ͳ�����鲢ͳ�ƶ�ӦԪ�ظ���
    int* countArray = new int[d + 1]();                   //ͳ������ĳ���Ϊ ��max-min��+ 1,������ֵΪ0
    for (int i = 0; i < sz; i++) 
    {
        countArray[array[i] - min]++;           //ƫ����Ϊ��Сֵ��������ÿ������ȥƫ�������������Ӧ������
    }

    //3.ͳ�����������Σ������Ԫ�ص���ǰ���Ԫ��֮��
    int sum = 0;
    for (int i = 0; i < d + 1; i++)             //d + 1 ΪcountArraytͳ������ĳ���
    {
        sum += countArray[i];               //����ÿ������ǰ���Ԫ��֮�ͣ������Լ���������
        countArray[i] = sum;                //�������ֵ����ǰ������Ӧ��Ԫ��
    }

    //4.�������ԭʼ���У���ͳ�������ҵ���ȷλ�ã�������������
    int* sortedArray = new int[sz];
    for (int i = sz - 1; i >= 0; i--) 
    {
        sortedArray[countArray[array[i] - min] - 1] = array[i];     //��Ԫ�ز��뵽sortArray������
        countArray[array[i] - min]--;      //��countArray�����ж�Ӧ���±��ֵ-1�������´�������ͬ��Ԫ��ʱ���������ڵ�ǰԪ�ص�ǰ�棬���������ȶ����㷨��
    }
    return sortedArray;
}


int main() 
{
    int array[] = {4, 2, 6, 5, 3, 2, 8, 1, 4, 5, 6, 0, 10};
    int sz = sizeof(array) / sizeof(array[0]);
    int* sortedArray = count_sort(array, sz);
    for (int i = 0; i < sz; i++)
    {
        cout << sortedArray[i] << " ";
    }
    cout << endl;

    sortedArray = count_sort_plus(array, sz);
    for (int i = 0; i < sz; i++)
    {
        cout << sortedArray[i] << " ";
    }
    cout << endl;
    return 0;
}