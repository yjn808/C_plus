#include <iostream>
using namespace std;
#include "MyArray.hpp"


void printarray(MyArray<int>& p)
{
	cout << "capacity:" << p.getCapacity() << "Size:" << p.getSize();
}






void test01()
{
	MyArray<int> arr1(5);

	for (int i = 0; i < 5; i++)
	{
		//利用尾插法向数组中插入数据
		arr1.Push_back(i);
	}

	cout << "arr1 print:" << endl;

	printarray(arr1);



	MyArray<int> arr2(arr1);
	printarray(arr2);
	arr2.Pop_Back();
	cout << "capacity:" << arr2.getCapacity() << "Size:" << arr2.getSize();



	/*MyArray<int>arr3(100);
	arr3 = arr1;*/
}



//测试自定义数据类型
class Person
{
public:
	Person() {};
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}

	string m_name;
	int m_age;
};



void printpersonarray(MyArray<Person>& p)
{
	for (int i = 0; i < p.getSize(); i++)
	{
		cout << "name:" << p[i].m_name << "age:" << p[i].m_age << endl;
	}
}

void test02()
{
	MyArray<Person>arr(10);
	Person p1("monky", 100);
	Person p2("zhap yun", 30);
	Person p3("anqila", 80);


	//将数据插入数组中
	arr.Push_back(p1);
	arr.Push_back(p2);
	arr.Push_back(p3);

	printpersonarray(arr);
	cout << "arr capacity" << arr.getCapacity() << endl;
	cout << "arr size" << arr.getSize() << endl;
}




int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}