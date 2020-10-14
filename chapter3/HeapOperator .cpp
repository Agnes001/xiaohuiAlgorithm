class HeapOperator {
    /// <summary>
    /// �ϸ�����
    /// </summary>
    /// <param name="arr"></param>
    /// <param name="n"></param>
    void upAjust(int* arr, size_t n)
    {
        int childIndex = n - 1;
        int parentIndex = (childIndex - 1) / 2;
        // temp��������Ҷ�ӽڵ�ֵ���������ĸ�ֵ
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
    /// �³�����
    /// </summary>
    /// <param name="arr">�������Ķ�</param>
    /// <param name="parentIndex">Ҫ�³��ĸ��ڵ�</param>
    /// <param name="length">�ѵ���Ч��С</param>
    void downAjust(int* arr, int parentIndex, int length)
    {
        // temp���游�ڵ��ֵ���������ĸ�ֵ
        int temp = arr[parentIndex];
        int childIndex = 2 * parentIndex + 1;
        while (childIndex < length)
        {
            // ������Һ��ӣ����Һ���С�����ӵ�ֵ����λ���Һ���
            if (childIndex + 1 < length && arr[childIndex + 1] < arr[childIndex])
            {
                childIndex++;
            }
            // ������ڵ�С���κ�һ�����ӵ�ֵ��ֱ������
            if (temp < arr[childIndex])
                break;
            arr[parentIndex] = arr[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * parentIndex + 1;
        }
        arr[childIndex] = temp;
    }
    /// <summary>
    /// ������
    /// </summary>
    /// <param name="arr"></param>
    /// <param name="n"></param>
    void buildHeap(int* arr, int len)
    {
        // �����һ����Ҷ�ӽڵ㿪ʼ�������³�����
        for (int i = (len - 2) / 2; i >= 0; i--)
        {
            downAjust(arr, i, len);
        }
    }
    // ���һ����Ҷ�ӽڵ��������(len-1),���ĸ��ڵ���((len-1)-1)/2
};