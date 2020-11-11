#include<iostream>
using namespace std;

//ascii码的取值范围	

int ASCII_RANGE = 128;

//获取字符串第k位字符所对应的ascii码序号	
int GetCharIndex(string str, int k) 
{
    //如果字符串长度小于k + 1，直接返回0，相当于给不存在的位置补0	
    if (str.length() < k + 1) 
    {
        return 0;
    }
    return str[k];          //返回字符对应ASCII的整数值
}

string* RadixSort(string array[], int maxLength, int sz)
{
    //排序结果数组，用于存储每一次按位排序的临时结果	
 
    string* SortedArray = new string[sz];

    //从个位开始比较，一直比较到最高位	
    for (int k = maxLength - 1; k >= 0; k--)
    { 
        //计数排序的过程，分成三步：	
        //1.创建辅助排序的统计数组，并把待排序的字符对号入座，	
        //这里为了代码简洁，直接使用ascii码范围作为数组长度	(所有字符一共128，可以表示所以的字符对应的下标)
        int* count = new int[ASCII_RANGE]();                //new统计数组并初始化为0
        for (int i = 0; i < sz; i++)
        {
            int index = GetCharIndex(array[i], k);
            count[index]++;
        }

        //2.统计数组做变形，后面的元素等于前面的元素之和	
        for (int i = 1; i < ASCII_RANGE; i++)
        {
            count[i] = count[i] + count[i - 1];
        }

        //3.倒序遍历原始数列，从统计数组找到正确位置，输出到结果数组	
        for (int i = sz - 1; i >= 0; i--) 
        {
            int index = GetCharIndex(array[i], k);
            int sorted_index = count[index] - 1;
            SortedArray[sorted_index] = array[i];
            count[index]--;
        } 

        //下一轮排序需要以上一轮的排序结果为基础，因此把结果复制给array
        for (int i = 0; i < sz; i++)
        {
            array[i] = SortedArray[i];
        }
    }
    return array;
}

int main()
{

    string array1[] = { "qd", "abc", "qwe", "hhh", "a", "cws", "ope" };   
    int sz = sizeof(array1) / sizeof(array1[0]);
    string* p_sorted = RadixSort(array1, 3, sz);
    for (int i = 0; i < sz; i++)
    {
        cout << p_sorted[i] << " ";
    }
    cout << endl;
    return 0;
}