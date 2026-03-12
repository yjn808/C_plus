#include <iostream>
#include <string>
#include<map>
using namespace std;
 

//利用仿函数改变排序规则

class Mycompare
{
public:
    bool operator()(int a, int b)
    {
        //降序
        return a > b;
    }
};




void test01()
{
    map<int, int,Mycompare>m;


    m.insert(make_pair(10, 200));
    m.insert(make_pair(3,500));
    m.insert(make_pair(50, 10));
    m.insert(make_pair(5, 1000));
    m.insert(make_pair(6, 3));



    for (map<int, int, Mycompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key= " << it->first << "calue = " << it->second << endl;
    }




}














int main(){
    test01();
 
    system("pause");
    return 0;
 
}