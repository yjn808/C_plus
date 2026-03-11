#include <iostream>
#include <string>
using namespace std;
#include<list>




//list容器数据存取

void test01()
{
    list<int>L1;

    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);

    //L1[0];不可用
    //L1.at(0) 不可以用at方式访问list容器中的元素

    //原因是list本身是链表，不是用连续线性空间存储数据，迭代器不支持随机访问

    cout << "one list is " << L1.front() << endl;

    cout << "last " << L1.back() << endl;

    //验证迭代器不支持随机访问

    list<int>::iterator it = L1.begin();
    it++;
    it--;
    //it = it + 1;//报错



}






int main(){
 
 
    system("pause");
    return 0;
 
}