//#include<iostream>
//using namespace std;
//
////普通函数和函数模板的区别
//
////1.普通函数调用可以发生隐式类型转换
////2.函数模板用自动类型推导，不可以发生隐式类型转换
////3.函数模板用显示指定类型，可以发生隐式类型准换
//
////普通函数
//int MyAdd(int a, int b)
//{
//	return a + b;
//}
//
////函数模板
//template<class T>
//T MyAdd02(T a, T b)
//{
//	return a + b;
//}
//
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	char c = 'c';//ascii a=97,c=99
//	cout << MyAdd(a, c) << endl;
//
//	//自动类型推导
//	cout << MyAdd02(a, b) << endl;
//	/*cout << MyAdd02(a, c) << endl;*///错误
//	cout << MyAdd02<int>(a, c) << endl;
//}
//
//
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