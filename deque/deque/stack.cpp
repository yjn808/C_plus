#include <iostream>
#include <string>
using namespace std;
#include<stack>

//栈stack容器

void test01()
{
    //先进后出
    stack<int>s;
    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "stack size is" << s.size() << endl;
    //只要栈不为空！查看栈顶并出栈
    while (!s.empty())
    {
        //查看栈顶元素
        cout << "stack pop" << s.top() << endl;
        s.pop();
    }
    cout << "stack size is" << s.size() << endl;
}




int main(){
 
 
    system("pause");
    return 0;
 
}