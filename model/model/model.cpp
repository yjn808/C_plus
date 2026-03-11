#include<iostream>
using namespace std;
#include<string>
//类模板对象做函数参数

template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "name:" << this->m_Name << "age:" << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;

};


//1.指定传入类型

void PrintPerson1(Person<string, int>&p)
{
	p.showPerson();
}

void test01()
{
	Person<string, int>p("monkey", 100);
	PrintPerson1(p);
}



//2.参数模板化
template<class T1,class T2>
void PrintPerson2(Person<T1, T2>&p)
{
	p.showPerson();
	cout << "T1 type is" << typeid(T1).name() << endl;
	cout << "T2 type is" << typeid(T2).name() << endl;
}

void test02()
{
	Person<string, int>p2("pig", 99);
	PrintPerson2(p2);
}


//3.整个类模拟化
template<class T>
void PrintPerson3(T &p)
{
	p.showPerson();
	cout << "T type is" << typeid(T).name() << endl;
}



void test03()
{
	Person<string, int>p("fish", 200);
	PrintPerson3(p);
}




int main()
{
	test01();
	test02();
	test03();


	system("pause");
	return 0;
}