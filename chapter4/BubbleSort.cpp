#include <iostream>
using namespace std;

/// <summary>
/// ð������ ��С����
/// </summary>
/// <param name="arr"></param>
/// <param name="len"></param>
void BubbleSort(int* arr, int len)
{
    int tmp = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

/// <summary>
/// ð������ ��С����
/// </summary>
/// <param name="arr"></param>
/// <param name="len"></param>
void BubbleSortAdv1(int* arr, int len)
{    
    for (int i = 0; i < len - 1; i++)
    {
        // �����ǣ�ÿһ�ֵĳ�ʼֵ����true
        bool isSorted = true;
        for (int j = 0; j < len - i - 1; j++)
        {
            int tmp = 0;
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                // ��Ϊ��Ԫ�ؽ��н��������в�������ģ����Ϊfalse
                isSorted = false;
            }
        }
        if (isSorted)
        {
            break;
        }
    }
}

/// <summary>
/// ð������ ��С����
/// </summary>
/// <param name="arr"></param>
/// <param name="len"></param>
void BubbleSortAdv2(int* arr, int len)
{
    // ��¼���һ�ν�����λ��
    int lastExchangeIndex = 0;
    // �������еı߽磬ÿ�αȽ�ֻ��Ҫ�ȵ�����Ϊֹ
    int sortBorder = len - 1;
    for (int i = 0; i < len - 1; i++)
    {
        // �����ǣ�ÿһ�ֵĳ�ʼֵ����true
        bool isSorted = true;
        for (int j = 0; j < sortBorder; j++)
        {
            int tmp = 0;
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                // ��Ϊ��Ԫ�ؽ��н��������в�������ģ����Ϊfalse
                isSorted = false;
                // ����Ϊ���һ�ν���Ԫ�ص�λ��
                lastExchangeIndex = j;
            }
        }
        sortBorder = lastExchangeIndex;
        if (isSorted)
        {
            break;
        }
    }
}


int main()
{
    int arr[]{ 3, 4, 2 };//, 1, 5, 6, 8, 7};
    cout << "/**********����ǰ********/" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    int len = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, len);
    cout << "/**********�����********/" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}