class HeapOperator {
    /// <summary>
    /// 上浮调整
    /// </summary>
    /// <param name="arr"></param>
    /// <param name="n"></param>
    void upAjust(int* arr, size_t n)
    {
        int childIndex = n - 1;
        int parentIndex = (childIndex - 1) / 2;
        // temp保存插入的叶子节点值，用于最后的赋值
        int temp = arr[childIndex];

        while (childIndex > 0 && temp < arr[parentIndex])
        {
            arr[childIndex] = arr[parentIndex];
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
        arr[childIndex] = temp;
    }
    /// <summary>
    /// 下沉调整
    /// </summary>
    /// <param name="arr">待调整的堆</param>
    /// <param name="parentIndex">要下沉的父节点</param>
    /// <param name="length">堆的有效大小</param>
    void downAjust(int* arr, int parentIndex, int length)
    {
        // temp保存父节点的值，用于最后的赋值
        int temp = arr[parentIndex];
        int childIndex = 2 * parentIndex + 1;
        while (childIndex < length)
        {
            // 如果有右孩子，且右孩子小于左孩子的值，则定位到右孩子
            if (childIndex + 1 < length && arr[childIndex + 1] < arr[childIndex])
            {
                childIndex++;
            }
            // 如果父节点小于任何一个孩子的值，直接跳出
            if (temp < arr[childIndex])
                break;
            arr[parentIndex] = arr[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * parentIndex + 1;
        }
        arr[childIndex] = temp;
    }
    /// <summary>
    /// 构建堆
    /// </summary>
    /// <param name="arr"></param>
    /// <param name="n"></param>
    void buildHeap(int* arr, int len)
    {
        // 从最后一个非叶子节点开始，依次下沉调整
        for (int i = (len - 2) / 2; i >= 0; i--)
        {
            downAjust(arr, i, len);
        }
    }
    // 最后一个非叶子节点的索引是(len-1),它的父节点是((len-1)-1)/2
};