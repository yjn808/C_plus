#include <iostream>
#include <string>
using namespace std;
#include<list>

//list 容器构造函数


void printList(const list<int>& l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    //创建list容器
    list<int>l1;

    //添加数据
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    //遍历容器
    
}




int main(){
    test01();

 
    system("pause");
    return 0;
 
}