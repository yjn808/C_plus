#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
using namespace std;



class person
{
public:
    person(string name,int age)
    {
        this->m_age = age;
        this->m_name = name;
    }

    //重载 == 底层find知道如何对比person数据类型
    bool operator==(const person& p)
    {
        if (this->m_age == p.m_age && this->m_name == p.m_name)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_name;
    int m_age;

};



void  test()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //查找容器中是否有这几个元素

    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if (it == v.end())
    {
        cout << "not find" << endl;
    }
    else
    {
        cout << "find it" <<*it<< endl;
    }






}

void test02()
{
    vector<person>v;
    person p1("123", 20);
    person p2("56441", 20);
    person p3("12", 20);
    person p4("20", 20);
    


    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);


    vector<person>::iterator it = find(v.begin(), v.end(), p2);
     

}





int main(){
 
 
    system("pause");
    return 0;
 
}