//#include<iostream>
//using namespace std;
//
//
////函数模板注意事项
//template<class T>
//void My_Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
////1.自动类型推导，必须推导出一致的数据类型T
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	My_Swap(a, b);
//	cout << "a= " << endl;
//	cout << "b= " << endl;
//}
////2.模板必须要确定出T的数据类型才能使用
//template<class T>
//void func()
//{
//	cout << "func apply" << endl;
//}
//
//
//
//void test02()
//{
//	func<int>();
//}
//
//
//int main()
//{
//	test02();
//
//
//	system("pause");
//	return 0;
//}
//
//
//
//
//
