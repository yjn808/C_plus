#include<iostream>
using namespace std;
#include<string>


//string 字符存取
void test01()
{
	string str1 = "hello";
	cout << "str1= " << str1 << endl;
	string str2 = "hello";

	//通过[]访问单个字符
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << endl;
	}
	cout << endl;


	//通过at方式访问单个字符
	for (int i = 0; i < str2.size(); i++)
	{
		cout << str2.at(i)<< " ";
	}
	cout << endl;


	str1[0] = 'x';


	str2.at(2) = 'x';
}

int main()
{

	/*test01();*/

	system("pause");
	return 0;
}
