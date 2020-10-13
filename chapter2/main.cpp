#include <iostream>
#include <map>
using namespace std;

struct stu1 {
    int age;
    int id;
    char* child;
};
struct stu2 {
    int age;
    int id;
    char child[];
};


int main()
{

    cout << sizeof(stu1) << endl;

    cout << sizeof(stu2) << endl;









    cin.get();
    return 0;
}