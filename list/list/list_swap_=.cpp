#include <iostream>
#include <string>
using namespace std;
#include<list>

//list容器的赋值与交换
void printList(const list<int>& l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << endl;
    }
    cout << endl;
}



//list 容器的赋值和交换
//赋值
void test01()
{
    list<int>l1;

    l1.push_back(1);
    l1.push_back(210);
    l1.push_back(30);
    l1.push_back(520);
    l1.push_back(1314);

    printList(l1);

    //赋值
    list<int>l2;
    l2 = l1;
    printList(l2);

    list<int>l3;
    l3.assign(l2.begin(), l2.end());
    printList(l3);

    list<int>l4;
    l4.assign(10, 100);

    printList(l4);



}

//交换
void test02()
{
    list<int>l1;
    l1.push_back(10);
    l1.push_back(200);
    l1.push_back(300);
    l1.push_back(40);
    l1.push_back(50);

    list<int>l2;
    l2.assign(10, 100);

    cout << "swap before" <<  endl;
    printList(l1);
    printList(l2);

    l1.swap(l2);
    cout << "swap end" << endl;

    printList(l1);
    printList(l2);
}


int main(){
 
 
    system("pause");
    return 0;
 
}