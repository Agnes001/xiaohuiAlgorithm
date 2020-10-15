
/// <summary>
/// 鸡尾酒排序
/// </summary>
/// <param name="arr"></param>
/// <param name="len"></param>
void CockTailSort(int* arr, int len)
{
    int tmp = 0;
    for (int i = 0; i < len / 2; i++)
    {
        // 有序标记，每一轮的初始值都是true
        bool isSorted = true;
        // 奇数轮，从左往右比较和交换
        for (int j = i; j < len - i - 1; j++)
        {
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
        // 在偶数轮之前，将isSorted重新标记为true
        isSorted = true;
        // 偶数轮，从右向左比较和交换
        for (int j = len - 2 - i; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                tmp = arr[j];
                arr[j] = arr[j - 1];
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