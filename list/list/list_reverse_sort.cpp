#include <iostream>
#include <string>
using namespace std;
#include<list>
#include<algorithm>
//list容器的翻转和排序



void printList(const list<int>& p)
{
    for (list<int>::const_iterator it = p.begin(); it != p.end(); it++)
    {
        cout << *it << " ";

    }
    cout << endl;
}





 
void test01()
{
    list<int>l;
    l.push_back(20);
    l.push_back(10);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);

    printList(l);

    l.reverse();
    printList(l);


}

bool myCompare(int v1,int v2)
{
    //降序 就让第一个数》第二个数
    return v1 > v2;
}


//排序
void test02()
{
    list<int>l;
    l.push_back(20);
    l.push_back(10);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);

    //所有不支持随机访问迭代器的容器不支持访问标准算法
    //不支持随机访问迭代器的容器，内部会提供对应的一些算法
    /*sort(l.begin(), l.end());*/
    l.sort();


}





int main(){
 
 
    system("pause");
    return 0;
 
}