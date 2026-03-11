//#include<iostream>
//using namespace std;
//
////实现一个通用对数组排序的函数
////从大到小
////算法 选择
////测试 char 数组 、int 数组
//
////交换函数模板
//template<class T>
//void My_Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
////排序算法
//template<class T>
//void mySort(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;
//		for (int j = i + 1; j < len; j++)
//		{
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			My_Swap(arr[max], arr[i]);
//		}
//
//	}
//}
//
////打印数组模板
//template<class T>
//void printarray(T arr[], int len)
//{
//	for(int i=0;i<len;i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//
//void test01()
//{
//	char Arr[] = "budhgagj";
//
//	int len = sizeof(Arr) / sizeof(char);
//	mySort(Arr, len);
//	printarray(Arr, len);
//}
//
//void test02()
//{
//	int arr[] = { 7,5,4,69,87,7,22,4,4 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	mySort(arr, num);
//	printarray(arr, num);
//
//
//}
//
//int main()
//{
//
//
//	/*test01();*/
//	test02();
//
//	system("pause");
//	return 0;
//}