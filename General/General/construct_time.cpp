#include<iostream>
using namespace std;
#include<string>

//类模板中成员函数的创建时机
//类模板中成员函数在调用时才去创建
class Person1
{
public:
	void showPerson1()
	{
		cout << "Perosn1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Perosn2 show" << endl;
	}
};

template<class T>
class Myclass
{
public:
	T obj;

	//类模板中的成员函数
	void func()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};

void test01()
{
	Myclass<Person1>m;
	m.func();
	/*m.func2();*/
}



int main()
{


	test01();
	/*test02();*/

	system("pause");
	return 0;
}