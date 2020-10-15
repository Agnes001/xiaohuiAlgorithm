

void quickSort(int* arr, int startIndex, int endIndex)
{
    // 递归结束条件：startIndex大等于endIndex的时候
    if (startIndex >= endIndex) {
        return;
    }
    // 得到基准元素位置
    int pivotIndex = partition(arr, startIndex, endIndex);
    // 根据基准元素，分成两部分递归排序
    quickSort(arr, startIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, endIndex);
}
/// <summary>
/// 分治（双边循环法）
/// </summary>
/// <param name="arr"></param>
/// <param name="startIndex"></param>
/// <param name="endIndex"></param>
/// <returns></returns>
int partition(int* arr, int startIndex, int endIndex)
{
    // 取第一个位置的元素作为基准元素
    int pivot = arr[startIndex];
    int left = startIndex;
    int right = endIndex;

    while (left != right)
    {
        // 控制right指针比较并左移
        while (left<right && arr[right] >pivot)
        {
            right--;
        }
        //控制left指针比较并右移
        while (left < right && arr[left] < pivot)
        {
            left++;
        }
        //交换left和right指向的元素
        if (left < right)
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
    //pivot和指针重合点交换
    arr[startIndex] = arr[left];
    arr[left] = pivot;

    return left;
}
/// <summary>
/// 分治（单边循环法）
/// </summary>
/// <param name="arr"></param>
/// <param name="startIndex"></param>
/// <param name="endIndex"></param>
/// <returns></returns>
int partitionV2(int* arr, int startIndex, int endIndex)
{
    // 取第一个位置的元素作为基准元素（也可以选择随机位置）
    int pivot = arr[startIndex];
    int mark = startIndex;
    for (int i = startIndex + 1; i <= endIndex; i++)
    {
        if (arr[i] < pivot)
        {
            mark++;
            int p = arr[mark];
            arr[mark] = arr[i];
            arr[i] = p;
        }
    }
    arr[startIndex] = arr[mark];
    arr[mark] = pivot;
    return mark;
}