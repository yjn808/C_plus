#include <iostream>
#include <string>
#include<algorithm>
#include<vector>

using namespace std;
 
//count 查找算法
//统计自定义数据类型
//统计内置数据类型



class Person
{
public:
    Person(string name, int age)
    {
        this->m_age = age;
        this->m_name = name;
    }
    bool operator==(const Person& p)
    {
        if (this->m_age == p.m_age)
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




void test02()
{
    vector<Person>v1;

    Person p1("zhangfei", 15);
    Person p2("liubei", 20);
    Person p3("monkey", 100);
    Person p4("pig", 20);
    Person p5("fish", 10);


    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    v1.push_back(p5);

    int num = count(v1.begin(), v1.end(), p1);
}








void test01()
{
    vector<int>v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(40);
    v.push_back(10);
    v.push_back(30);




    int num=count(v.begin(), v.end(), 40);
    cout << num << endl;





}






int main(){
 
 
    system("pause");
    return 0;
 
}