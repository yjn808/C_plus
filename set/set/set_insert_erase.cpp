#include <iostream>
#include <string>
#include<set>
using namespace std;
 
//set容器的插入和删除
void printSet(const set<int>& p)
{
    for (set<int>::const_iterator it = p.begin(); it != p.end(); it++)
    {
        cout << *it << " ";

    }
    cout << endl;
}

void test01()
{

    set<int>s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(340);
    s.insert(50);


    set<int>::iterator pos=s.find(30);

    if (pos != s.end())
    {
        cout << "find it" << endl;
    }
    else
    {
        cout << "not find it" << endl;
    }

    printSet(s);


    s.erase(s.begin());

    s.clear();


}



void test02()
{
    set<int>s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(340);
    s.insert(50);


    int num = s.count(30);

    cout << "num of s" << endl;
}

int main(){
 
 
    system("pause");
    return 0;
 
}