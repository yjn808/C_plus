#include <iostream>
#include <string>
#include<set>
using namespace std;
 

//set容器排序，存放自定义数据类型






class Person
{
public:
    Person(string name, int age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }



    string m_Name;
    int m_Age;

};

//自定义数据类型指定排序规则
class Mycampare
{
public:
    bool operator()(const Person& p1, const Person& p2)
    {
        //按照年龄降序
        return p1.m_Age > p2.m_Age;
    }
};





void test01()
{
    set<Person, Mycampare>s;

    Person p1("pig", 100);
    Person p2("monkey", 20);
    Person p3("fish", 30);
    Person p4("dog", 300);


    for (set<Person, Mycampare>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << (*it).m_Age << (*it).m_Name << endl;
    }

    
}
















int main(){
    test01();
 
    system("pause");
    return 0;
 
}