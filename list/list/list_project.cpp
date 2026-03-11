#include <iostream>
#include <string>
using namespace std;
#include<list>






class Person
{
public:

    Person(string name, int age, int height)
    {
        this->m_age = age;
        this->m_height = height;
        this->m_name = name;
    }



    string m_name;
    int m_age;
    int m_height;
};


//指定排序规则
bool comparePerson(Person &p1,Person &p2)
{
    //按照年龄升序
    if (p1.m_age == p2.m_age)
    {
        //年龄相同按照身高降序
        return p1.m_height > p2.m_height;
    }
    return p1.m_age < p2.m_age;
}

void test01()
{
    list<Person>P;


    Person p1("monkey",10, 1000);
    Person p2("pig", 20, 30);
    Person p3("dog", 10, 40);
    Person p4("cat", 30, 50);

    //向容器中插入数据
    P.push_back(p1);
    P.push_back(p2);
    P.push_back(p3);
    P.push_back(p4);

    for (list<Person>::iterator it = P.begin(); it != P.end(); it++)
    {
        cout << "age is " << (*it).m_age << "name is " << (*it).m_name << "height is " << (*it).m_height << endl;
    }


    //排序
    cout << "sort end" << endl;

    P.sort();





}




int main(){
    test01();
 
    system("pause");
    return 0;
 
}