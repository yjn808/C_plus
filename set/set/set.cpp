#include <iostream>
#include <string>
#include<set>
using namespace std;

//set 容器 大小和交换



void printSet(const set<int>& p)
{
    for (set<int>::const_iterator it = p.begin(); it != p.end(); it++)
    {
        cout << *it << " ";

    }
    cout << endl;
}

//大小

void test01()
{
    set<int>s1;
    //插入数据
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    //打印容器
    printSet(s1);



    if (s1.empty())
    {
        cout << "s1 is empty" << endl;
    }
    else
    {
        cout << "s1 not empty" << endl;
    }


    cout<<s1.size();


    set<int>s2;
    s2.insert(100);
    s2.insert(200);
    s2.insert(300);
    s2.insert(400);


    s1.swap(s2);


}





 
int main(){
    test01();
 
    system("pause");
    return 0;
 
}