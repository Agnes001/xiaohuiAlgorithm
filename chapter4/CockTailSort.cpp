
/// <summary>
/// ��β������
/// </summary>
/// <param name="arr"></param>
/// <param name="len"></param>
void CockTailSort(int* arr, int len)
{
    int tmp = 0;
    for (int i = 0; i < len / 2; i++)
    {
        // �����ǣ�ÿһ�ֵĳ�ʼֵ����true
        bool isSorted = true;
        // �����֣��������ұȽϺͽ���
        for (int j = i; j < len - i - 1; j++)
        {
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
        // ��ż����֮ǰ����isSorted���±��Ϊtrue
        isSorted = true;
        // ż���֣���������ȽϺͽ���
        for (int j = len - 2 - i; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                tmp = arr[j];
                arr[j] = arr[j - 1];
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