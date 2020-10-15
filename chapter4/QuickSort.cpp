

void quickSort(int* arr, int startIndex, int endIndex)
{
    // �ݹ����������startIndex�����endIndex��ʱ��
    if (startIndex >= endIndex) {
        return;
    }
    // �õ���׼Ԫ��λ��
    int pivotIndex = partition(arr, startIndex, endIndex);
    // ���ݻ�׼Ԫ�أ��ֳ������ֵݹ�����
    quickSort(arr, startIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, endIndex);
}
/// <summary>
/// ���Σ�˫��ѭ������
/// </summary>
/// <param name="arr"></param>
/// <param name="startIndex"></param>
/// <param name="endIndex"></param>
/// <returns></returns>
int partition(int* arr, int startIndex, int endIndex)
{
    // ȡ��һ��λ�õ�Ԫ����Ϊ��׼Ԫ��
    int pivot = arr[startIndex];
    int left = startIndex;
    int right = endIndex;

    while (left != right)
    {
        // ����rightָ��Ƚϲ�����
        while (left<right && arr[right] >pivot)
        {
            right--;
        }
        //����leftָ��Ƚϲ�����
        while (left < right && arr[left] < pivot)
        {
            left++;
        }
        //����left��rightָ���Ԫ��
        if (left < right)
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
    //pivot��ָ���غϵ㽻��
    arr[startIndex] = arr[left];
    arr[left] = pivot;

    return left;
}
/// <summary>
/// ���Σ�����ѭ������
/// </summary>
/// <param name="arr"></param>
/// <param name="startIndex"></param>
/// <param name="endIndex"></param>
/// <returns></returns>
int partitionV2(int* arr, int startIndex, int endIndex)
{
    // ȡ��һ��λ�õ�Ԫ����Ϊ��׼Ԫ�أ�Ҳ����ѡ�����λ�ã�
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