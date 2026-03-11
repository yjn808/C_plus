#include<iostream>
using namespace std;
#include<vector>

//vector 容器互换



void printvector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//1.基本使用
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);

	}
	printvector(v1);

	vector<int>v2;

	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);

	}
	printvector(v2);

	cout << "swap before" << endl;



	v1.swap(v2);
	printvector(v1);
	printvector(v2);


	

}
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
	}

	cout << "v capacity is " << v.capacity() << endl;
	cout << "v size is" << v.size() << endl;


	//使用swap收缩内存
	vector<int>(v).swap(v);
	cout << "v capacity is " << v.capacity() << endl;
	cout << "v size is" << v.size() << endl;





}








int main()
{

	/*test01();*/

	system("pause");
	return 0;
}
