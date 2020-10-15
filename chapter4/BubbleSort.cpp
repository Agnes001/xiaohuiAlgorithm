#include <iostream>
using namespace std;

/// <summary>
/// 冒泡排序 从小到大
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
/// 冒泡排序 从小到大
/// </summary>
/// <param name="arr"></param>
/// <param name="len"></param>
void BubbleSortAdv1(int* arr, int len)
{    
    for (int i = 0; i < len - 1; i++)
    {
        // 有序标记，每一轮的初始值都是true
        bool isSorted = true;
        for (int j = 0; j < len - i - 1; j++)
        {
            int tmp = 0;
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                // 因为有元素进行交换，所有不是有序的，标记为false
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
/// 冒泡排序 从小到大
/// </summary>
/// <param name="arr"></param>
/// <param name="len"></param>
void BubbleSortAdv2(int* arr, int len)
{
    // 记录最后一次交换的位置
    int lastExchangeIndex = 0;
    // 无序数列的边界，每次比较只需要比到这里为止
    int sortBorder = len - 1;
    for (int i = 0; i < len - 1; i++)
    {
        // 有序标记，每一轮的初始值都是true
        bool isSorted = true;
        for (int j = 0; j < sortBorder; j++)
        {
            int tmp = 0;
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                // 因为有元素进行交换，所有不是有序的，标记为false
                isSorted = false;
                // 更新为最后一次交换元素的位置
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
    cout << "/**********排序前********/" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    int len = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, len);
    cout << "/**********排序后********/" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}