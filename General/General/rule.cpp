//#include<iostream>
//using namespace std;
//
////普通函数和函数模板的调用规则
////1.如果函数模板和普通函数都能调用优先调用普通函数
////2.可以通过空模板参数列表 强制调用 函数模板
////3.函数模板可以发生函数重载
////4.如果函数模板可以产生更好的匹配优先调用函数模板
//
//void myprint(int a, int b);
////{
////	cout << "putong" << endl;
////
////}
//
//template<class T>
//void myPrint(T a, T b)
//{
//	cout << "moban" << endl;
//
//}
//
//template<class T>
//void myPrint(T a, T b,T c)
//{
//	cout << "moban" << endl;
//
//}
//
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	/*myPrint(a, b);*/
//	/*myPrint<>(a, b);*/
//
//	/*myPrint(a, b,c);*/
//	//如果函数模板可以产生更好的匹配优先调用函数模板
//	char c1 = 'a';
//	char c2 = 'b';
//	myPrint(c1, c2);
//
//}
//
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