#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>



//vector容器中存放自定义数据类型
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


void test01()
{
	vector<Person>v;

	Person p1("monkey", 10);
	Person p2("pig", 20);
	Person p3("dog", 30);
	Person p4("rea", 40);
	Person p5("blue", 50);

	//向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历容器中的数据
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "name:" << (*it).m_Name << "age:" << (*it).m_Age << endl;
		cout << "name:" << it->m_Name << "age:" << it->m_Age<< endl;
	}

}


//存放自定义数据类型的指针
void test02()
{
	vector<Person*>v;

	Person p1("monkey", 10);
	Person p2("pig", 20);
	Person p3("dog", 30);
	Person p4("rea", 40);
	Person p5("blue", 50);

	//向容器中添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "name:" << (*it)->m_Name << "age:" << (*it)->m_Age << endl;
	}





}





int main()
{

	/*test01();*/

	system("pause");
	return 0;
}