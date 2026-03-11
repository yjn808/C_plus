#include <iostream>
#include <string>
using namespace std;
#include<queue>


class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }


    string m_name;
    int m_age;
};



//队列
void test01()
{
    queue<Person>q;

    //准备数据
    Person p1("monkey", 1000);
    Person p2("pig", 500);
    Person p3("fish", 4000);
    Person p4("father", 20);



    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    //判断只要队列不为空 查看队头队尾 出队


    while (!q.empty())
    {
        //查看队头
        cout << "queue head-name:" << q.front().m_name << "age:" << q.front().m_age << endl;

        //查看队尾
        cout << "queue back-name:" << q.back().m_name << "age:" << q.back().m_age << endl;

        q.pop();

        

    }
    cout << "queue size" << q.size() << endl;


}





int main(){
    test01();
 
    system("pause");
    return 0;
 
}