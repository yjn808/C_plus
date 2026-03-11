#include<iostream>
using namespace std;
#include<string>


//拼接
void test01()
{
	string str1 = "wo";
	str1 += "play game";
	cout << "str1= " << str1 << endl;


	str1 += ':';
	cout << "str1= " << str1 << endl;

	string str2="LOL";
	str1 += str2;
	cout << "str1= " << str1 << endl;

	string str3 = "I";
	str3.append("love ");
	cout<< "str3= " << str3 << endl;

	str3.append("game abcde", 4);
	cout << "str3= " << str3 << endl;




}














int main()
{

	/*test01();*/

	system("pause");
	return 0;
}
