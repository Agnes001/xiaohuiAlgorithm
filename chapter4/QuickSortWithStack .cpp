#include <stack>


void quickSortWithStack(int *arr,int startIndex,int endIndex)
{
	//�ֶ�����ջ���洢ÿ�ηֿ���ŵ���ʼ��
	//ջ�ǿ�ʱѭ����ȡ������ջ
	std::stack<int> s;
	if (startIndex < endIndex)
	{
		int boundary = partition(arr, startIndex, endIndex);

		if (boundary - 1 > startIndex) //ȷ����������� 
		{
			//��������˵���ջ 
			s.push(startIndex);
			s.push(boundary - 1);
		}
		if (boundary + 1 < endIndex) //ȷ���ҷ������� 
		{
			s.push(boundary + 1);
			s.push(endIndex);
		}

		while (!s.empty())
		{
			//�õ�ĳ���������ұ߽� 
			int r = s.top();
			s.pop();
			int l = s.top();
			s.pop();

			boundary = partition(arr, l, r);
			if (boundary - 1 > l) //ȷ����������� 
			{
				//��������˵���ջ 
				s.push(l);
				s.push(boundary - 1);
			}
			if (boundary + 1 < r) //ȷ���ҷ������� 
			{
				s.push(boundary + 1);
				s.push(r);
			}
		}
	}
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