#include<iostream>
using namespace std;

//ascii���ȡֵ��Χ	

int ASCII_RANGE = 128;

//��ȡ�ַ�����kλ�ַ�����Ӧ��ascii�����	
int GetCharIndex(string str, int k) 
{
    //����ַ�������С��k + 1��ֱ�ӷ���0���൱�ڸ������ڵ�λ�ò�0	
    if (str.length() < k + 1) 
    {
        return 0;
    }
    return str[k];          //�����ַ���ӦASCII������ֵ
}

string* RadixSort(string array[], int maxLength, int sz)
{
    //���������飬���ڴ洢ÿһ�ΰ�λ�������ʱ���	
 
    string* SortedArray = new string[sz];

    //�Ӹ�λ��ʼ�Ƚϣ�һֱ�Ƚϵ����λ	
    for (int k = maxLength - 1; k >= 0; k--)
    { 
        //��������Ĺ��̣��ֳ�������	
        //1.�������������ͳ�����飬���Ѵ�������ַ��Ժ�������	
        //����Ϊ�˴����ֱ࣬��ʹ��ascii�뷶Χ��Ϊ���鳤��	(�����ַ�һ��128�����Ա�ʾ���Ե��ַ���Ӧ���±�)
        int* count = new int[ASCII_RANGE]();                //newͳ�����鲢��ʼ��Ϊ0
        for (int i = 0; i < sz; i++)
        {
            int index = GetCharIndex(array[i], k);
            count[index]++;
        }

        //2.ͳ�����������Σ������Ԫ�ص���ǰ���Ԫ��֮��	
        for (int i = 1; i < ASCII_RANGE; i++)
        {
            count[i] = count[i] + count[i - 1];
        }

        //3.�������ԭʼ���У���ͳ�������ҵ���ȷλ�ã�������������	
        for (int i = sz - 1; i >= 0; i--) 
        {
            int index = GetCharIndex(array[i], k);
            int sorted_index = count[index] - 1;
            SortedArray[sorted_index] = array[i];
            count[index]--;
        } 

        //��һ��������Ҫ����һ�ֵ�������Ϊ��������˰ѽ�����Ƹ�array
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