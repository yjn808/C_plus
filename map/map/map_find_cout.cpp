#include <iostream>
#include <string>
#include<map>
using namespace std;
 

//find and count  map容器



void test01()
{
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));



    map<int, int>::iterator pos = m.find(3);

    if (pos != m.end())
    {
        cout << "find it " << (*pos).first << "value= " << pos->second << endl;
    }
    else
    {
        cout << "not find it" << endl;
    }

    //统计
    int num = m.count(3);//结果为0或1，multimap的count统计可能大于1




}







int main(){
    test01();
 
    system("pause");
    return 0;
 
}