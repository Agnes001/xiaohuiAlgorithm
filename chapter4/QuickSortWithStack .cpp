#include <stack>


void quickSortWithStack(int *arr,int startIndex,int endIndex)
{
	//手动利用栈来存储每次分块快排的起始点
	//栈非空时循环获取中轴入栈
	std::stack<int> s;
	if (startIndex < endIndex)
	{
		int boundary = partition(arr, startIndex, endIndex);

		if (boundary - 1 > startIndex) //确保左分区存在 
		{
			//将左分区端点入栈 
			s.push(startIndex);
			s.push(boundary - 1);
		}
		if (boundary + 1 < endIndex) //确保右分区存在 
		{
			s.push(boundary + 1);
			s.push(endIndex);
		}

		while (!s.empty())
		{
			//得到某分区的左右边界 
			int r = s.top();
			s.pop();
			int l = s.top();
			s.pop();

			boundary = partition(arr, l, r);
			if (boundary - 1 > l) //确保左分区存在 
			{
				//将左分区端点入栈 
				s.push(l);
				s.push(boundary - 1);
			}
			if (boundary + 1 < r) //确保右分区存在 
			{
				s.push(boundary + 1);
				s.push(r);
			}
		}
	}
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