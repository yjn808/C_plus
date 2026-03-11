//#include<iostream>
//using namespace std;
//#include<string>
//
//
//
////类模板和函数模板的区别
////template<class NameType,class AgeType>
//template<class NameType, class AgeType=int>//pig
//class Person
//{
//public:
//
//	Person(NameType name, AgeType age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	void showPerson()
//	{
//		cout << "name= " << this->m_name << "age= " << this->m_age << endl;
//	}
//
//
//
//	NameType m_name;
//	AgeType m_age;
//
//};
//
////1.类模板没有自动类型推导使用方式
//void test01()
//{
//	Person<string, int>p("monkey", 999);
//	p.showPerson();
//}
//
////2.类模板在模板参数列表中可以有默认参数
//void test02()
//{
//	Person<string>p("pig", 200);
//}
//
//int main()
//{
//
//
//	/*test01();*/
//	/*test02();*/
//
//	system("pause");
//	return 0;
//}