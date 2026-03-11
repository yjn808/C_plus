#include<iostream>
using namespace std;
#include<string>
#include "Person.hpp"//类模板
//#include "Person.h"
//1.直接包含源文件
//#include "Person.cpp"

//2.将.h和.cpp中的内容写到一起，将后缀改为.hpp;


//类模板的分文件编写问题及解决

//template<class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	/*{
//		this->m_Age = age;
//		this->m_Name = name;
//	}*/
//	void showPerson();
//	/*{
//		cout << "name:" << this->m_Name << "age:" << this->m_Age << endl;
//	}*/
//
//
//	T1 m_Name;
//	T2 m_Age;
//};
//
////构造函数类外实现
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_Age = age;
//	this->m_Name = name;
//}
//
////成员函数类外实现
//template<class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "name:" << this->m_Name << "age:" << this->m_Age << endl;
//}

void test01()
{
	Person<string, int>p("Tom", 20);
	p.showPerson();
}



int main()
{
	test01();

	system("pause");
	return 0;
}


