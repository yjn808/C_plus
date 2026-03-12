#include <iostream>
#include <string>
#include<map>
using namespace std;
 

//map大小和交换



void printMap(const map<int, int>& M)
{
    for (map<int, int>::const_iterator it = M.begin(); it != M.end(); it++)
    {
        cout << (*it).first << it->second << endl;
    }
}


void test01()
{
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(5, 100));
    m.insert(pair<int, int>(4, 30));
    m.insert(pair<int, int>(2, 15));
    m.insert(pair<int, int>(6, 50));

    if (m.empty())
    {
        cout << "m is empty" << endl;
    }
    else
    {
        cout << "m not empty" << endl;
        cout << m.size() << endl;
    }
    map<int, int>m2;
    m2.insert(pair<int, int>(2, 30));
    m2.insert(pair<int, int>(10, 200));
    m2.insert(pair<int, int>(54, 60));
    m2.insert(pair<int, int>(4, 22));
    m2.insert(pair<int, int>(3, 53));
    

    cout << "swap before" << endl;

    m.swap(m2);


    cout << "swap end" << endl;


}








int main(){
 
 
    system("pause");
    return 0;
 
}