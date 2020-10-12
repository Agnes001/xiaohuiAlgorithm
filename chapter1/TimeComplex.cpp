#include <iostream>
using namespace std;
//n
void eat1(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "等待一分钟";
    }
}
//logn
void eat2(int n)
{
    for (int i = n; i > 1; i /= 2)
    {
        cout << "等待一分钟";
    }
}
//n^2
void eat4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "等待一分钟";
        }
    }
}