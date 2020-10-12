#include <iostream>
using namespace std;

int main()
{
    int arr[10]{};
    cout << &arr[9] << endl;
    cout << &arr[10] << endl;

    float f = 2.4f;
    ++f;
    cout << f;

    cin.get();
    return 0;
}