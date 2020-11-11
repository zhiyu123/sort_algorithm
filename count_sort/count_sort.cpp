#include<iostream>
using namespace std;

int* count_sort(int array[], int sz)              //朴素的计数排序
{
    //1.得到数列的最大值
    int max = array[0];
    for (int i = 1; i < sz; i++) 
    {
        if (array[i] > max) 
        {
            max = array[i];
        }
    }
    
    //2.根据数列最大值确定统计数组的长度
    int* countArray = new int[max + 1]();           //()是初始化为0

    //3.遍历数列，填充统计数组
    for (int i = 0; i < sz; i++) 
    {
        countArray[array[i]]++;
    }

    //4.遍历统计数组，输出结果
    int index = 0;              //排好序的数组索引
    int* sortArray = new int[sz];           //保存排好序的元素的数组
    for (int i = 0; i < max + 1; i++)//max + 1是countArray数组的长度，外层循环是遍历数组的索引下标,也就是对应的元素值       
    {
        for (int j = 0; j < countArray[i]; j++)     //内层循环是每一个索引存储的输出次数的数量
        {
            sortArray[index++] = i;
        }
    }
    return sortArray;
}

int* count_sort_plus(int array[], int sz)                 //进阶版计数排序
{
    //1.得到数列的最大值和最小值，并算出差值d
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
    int d = max - min;          //计算差值，以确定统计数组的长度

    //2.创建统计数组并统计对应元素个数
    int* countArray = new int[d + 1]();                   //统计数组的长度为 （max-min）+ 1,并赋初值为0
    for (int i = 0; i < sz; i++) 
    {
        countArray[array[i] - min]++;           //偏移量为最小值，所以用每个数减去偏移量，就是其对应的索引
    }

    //3.统计数组做变形，后面的元素等于前面的元素之和
    int sum = 0;
    for (int i = 0; i < d + 1; i++)             //d + 1 为countArrayt统计数组的长度
    {
        sum += countArray[i];               //计算每个索引前面的元素之和（包括自己的索引）
        countArray[i] = sum;                //将结果赋值给当前索引对应的元素
    }

    //4.倒序遍历原始数列，从统计数组找到正确位置，输出到结果数组
    int* sortedArray = new int[sz];
    for (int i = sz - 1; i >= 0; i--) 
    {
        sortedArray[countArray[array[i] - min] - 1] = array[i];     //将元素插入到sortArray数组中
        countArray[array[i] - min]--;      //让countArray数组中对应的下标的值-1，代表下次遇到相同的元素时，依旧排在当前元素的前面，这样就是稳定的算法了
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