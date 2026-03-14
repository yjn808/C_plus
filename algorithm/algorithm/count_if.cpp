#include <iostream>
#include <string>
#include<algorithm>
#include<vector>


using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_age = age;
        this->m_name = name;
    }



    string m_name;
    int m_age;



};
class PersonGreater20
{
public:
    bool operator()(const Person& p)
    {
        return p.m_age > 20;
    }
};

class Greater20
{
public:
    bool operator()(int val)
    {
        return val > 20;
    }
};


//conut_if 统计内置数据类型
void test01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);

    int num=count_if(v.begin(), v.end(), Greater20());
    cout << num << endl;


}
//count_if 统计自定义数据类型
void test02()
{
    vector<Person>P;

    Person p1("zhangfei", 15);
    Person p2("liubei", 20);
    Person p3("monkey", 100);
    Person p4("pig", 20);
    Person p5("fish", 10);

    P.push_back(p1);
    P.push_back(p2);
    P.push_back(p3);
    P.push_back(p4);
    P.push_back(p5);


    int sum=count_if(P.begin(), P.end(), PersonGreater20());
}


int main(){
 
 
    system("pause");
    return 0;
 
}