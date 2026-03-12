#include <iostream>
#include <string>
#include<map>
using namespace std;

void printmap(const map<int, int>& m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << it->second << endl;
    }
}


void test01()
{
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));

    m.insert(map<int, int>::value_type(3, 30));


    m[4] = 40;

    cout << m[5] << endl;
    printmap(m);
    //不建议使用[]插入，用途可以利用key访问value
    //删除
    m.erase(m.begin());
    printmap(m);

    m.erase(3);//按照key删除

    //清空
    m.erase(m.begin(), m.end());

    m.clear();


}




 
int main(){
 
 
    system("pause");
    return 0;
 
}