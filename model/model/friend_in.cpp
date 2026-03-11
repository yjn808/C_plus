#include<iostream>
using namespace std;
#include <string>


//提前让编译器知道Person类存在
template<class T1, class T2>
class Person;

//类外实现
template<class T1, class T2>
void PrintPerson2(Person<T1, T2> p)
{
	cout << "lei_out name:" << p.m_name << "lei_out age:" << p.m_age << endl;
}


//通过全局函数打印Person信息
template<class T1,class T2>
class Person
{
	//全局函数类内实现
	friend void PrintPerson(Person<T1, T2> p)
	{
		cout << "name:" << p.m_name << "age:" << p.m_age << endl;
	}

	//全局函数看类外实现
	//加上空模板参数列表
	//如果全局函数类外实现 需要让编译器提前知道这个函数存在
	friend void PrintPerson2<>(Person<T1, T2> p);

public:

	Person(T1 name, T2 age)
	{
		this->m_name = name;
		this->m_age = age;
	}


private:
	T1 m_name;
	T2 m_age;
};





//1.全局函数在类内实现
void test01()
{
	Person<string,int>p("monkey",100);
	PrintPerson(p);

}

void test02()
{
	Person<string, int>p("pig", 99);
	PrintPerson2(p);

}




int main()
{
	test01();

	system("pause");
	return 0;
}