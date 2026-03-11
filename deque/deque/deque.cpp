#include <iostream>
#include <string>
using namespace std;
#include<deque>
#include<algorithm>


void printDeque(const deque<int>& d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        //容器中的数据不可修改
        cout << *it << " ";
    }
    cout << endl;
}

//deque构造函数
void test01()
{
    deque<int>d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2(d1.begin(), d1.end());
    printDeque(d2);

    deque<int>d3(10, 100);
    printDeque(d3);

    deque<int>d4(d3);
    printDeque(d4);



}


//deque容器赋值操作
void test03()
{
    deque<int>d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2;
    d2 = d1;
    printDeque(d2);

    //assign
    deque<int>d3;
    d3.assign(d1.begin(), d1.end());

    deque<int>d4;
    d4.assign(10, 100);
    printDeque(d4);

}


void test04()
{
    deque<int>d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }

    printDeque(d1);


    deque<int>d2;
   bool d=d2.empty();
   cout << d << endl;

   cout << "capacity " << d1.size() << endl;


   d1.resize(15);
   printDeque(d1);

   d1.resize(5);
   printDeque(d1);


}

//deque容器的插入和删除
void test05()
{
    deque<int>d1;

    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(5);
    d1.push_front(1);

    printDeque(d1);

    d1.pop_front();
    printDeque(d1);

    d1.pop_back();
    printDeque(d1);


}


void test06()
{
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(100);
    d1.push_back(200);
    printDeque(d1);

    //insert插入
    d1.insert(d1.begin(), 1000);
    printDeque(d1);

    d1.insert(d1.begin(),2, 1000);
    printDeque(d1);

    //按照区间插入
    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d2.push_back(4);


    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);

    //删除
    deque<int>::iterator it = d1.begin();
    it++;
    d1.erase(d1.begin());
    printDeque(d1);


}

//deque容器存取操作
void test07()
{
    deque<int>d1;

    d1.push_back(100);
    d1.push_back(5);
    d1.push_back(6);
    d1.push_back(8);
    d1.push_back(125400);

    //通过[]访问元素
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1[i] << " " ;
    }
    cout << endl;


    //通过at访问
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1.at(i) << " ";

    }
    cout << endl;

    //deque排序

    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);

    d.push_front(100);
    d.push_front(300);
    d.push_front(200);

    printDeque(d);

    //sort默认从小到大排序
    sort(d.begin(), d.end());
    printDeque(d);

}


int main(){

    test04();
    
 
    system("pause");
    return 0;
 
}