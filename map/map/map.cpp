#include <iostream>
#include <string>
#include<map>
using namespace std;
 





void printMap(const map<int, int>& p)
{
    for (map<int, int>::const_iterator it = p.begin(); it != p.end(); it++)
    {
        cout << (*it).first << it->second << " ";
    }
    cout << endl;
}

//map容器构造和赋值

void test01()
{
    //创建map容器
    map<int, int>m;


    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(3, 30));


    printMap(m);


    //拷贝构造
    map<int, int>m2(m);


    //赋值
    map<int, int>m3;
    m2 = m3;
    printMap(m3);


}






int main(){
    test01();
 
    system("pause");
    return 0;
 
}