#include<iostream>
using namespace std;
#include<string>

//字符串插入删除


void test01()
{
	string str = "hello";

	//插入
	str.insert(1, "111");


	cout << "str= " << str << endl;

	//删除
	str.erase(1, 3);
}


//string求子串
void test02()
{
	string str = "abcdefr";
	string substr = str.substr(1, 3);
	cout << "substr= " << substr << endl;


}

void test03()
{
	string email = "zhangsan@gmail,com";

	int pos = email.find("@");


	string username = email.substr(0, pos);
}












int main()
{

	/*test01();*/

	system("pause");
	return 0;
}