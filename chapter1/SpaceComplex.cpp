#include <iostream>
#include <map>
using namespace std;

//查找数组中重复的整数
//数组作为函数参数，退化为指针，
//由于函数内求不出数组的长度，需要在函数外求出数组长度并传入函数内
//sizeof(arr)/sizeof(arr[0])
int findReNum(int* arr, int len)
{
    int ret = 0;
    map<int, int> tmp;
    for (int i = 0; i < len; i++)
    {
        ++tmp[arr[i]];
        if (tmp[arr[i]] == 2)
        {
            return arr[i];
        }
    }
    return 0;
}

void fun1(int n)
{
    int var = 3;
}

void fun2(int n)
{
    //int arr[n]; 
    //出错：C++中一般是不能使用变量作为一个数组的长度的，必须使用常量。
    //这是因为数组作为C++的内置数据类型，其空间分配在栈内存中，这部分空间的大小在编译时就要确定，不能等到运行时再分配。
    //常量的值在编译时就能得到，而变量的值在运行时才能确定。
    //但是仍然有办法使用变量作为数组的长度：绕过栈内存，将数组空间开辟在堆空间内。
    //这样这块内存就是自己开辟的了，可以使用变量初始化数组的长度，内存空间会在运行时动态分配。
    int* arr = new int[n];

    delete[] arr;
    //注意：
    //使用完这个数组后要delete掉，防止内存泄漏。
    //如果可能的话，使用STL容器替代内置的数组类型，能得到更好的性能和撸代码体验。
}

void fun3(int n)
{
    int** arr = new int* [n];//列
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];//行
    }

    //进行销毁
    //先销毁第二维的数组
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    //再销毁第一维的数组
    delete[] arr;
}