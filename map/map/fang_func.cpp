#include <iostream>
#include <string>
 
using namespace std;
 
//仿函数

class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;

    }
};




void test01()
{
    MyAdd myadd;
    cout << myadd(10, 20) << endl;
}

class Myprint
{
public:
    Myprint()
    {
        this->count = 0;
    }
    void operator()(string test)
    {
        cout << test << endl;
        this->count++;
    }

    int count;//内部自己状态
};

void test02()
{
    Myprint myprint;
    myprint("hello");


    int sum = myprint.count;
}

void 

int main(){
 
 
    system("pause");
    return 0;
 
}