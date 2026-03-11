#include<iostream>
using namespace std;
#include<string>


//string查找和替换
void test01()
{

	string str1 = "abcdefg";
	int pos=str1.find("de");

	if (pos == -1)
	{
		cout << "not char" << endl;
	}
	else
	{
		cout << "find it" << pos << endl;
	}

	cout << "pos= " << pos << endl;



	//rfind
	//rfind从右往左 find从左往右查找
	int rpos = str1.rfind("de");
	cout << "pos= " << pos << endl;

}

//替换
void test02()
{
	string str1 = "abcdef";
	str1.replace(1, 3, "1111");
	cout << "str: " << str1 << endl;
}




int main()
{

	test01();

	system("pause");
	return 0;
}
