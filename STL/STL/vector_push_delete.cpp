#include<iostream>
using namespace std;
#include<vector>


void printvector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test01()
{
	vector<int>v1;
	//尾插法
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	//遍历
	printvector(v1);

	//尾删
	v1.pop_back();
	printvector(v1);

	//插入
	v1.insert(v1.begin(), 100);
	printvector(v1);

	v1.insert(v1.begin(), 2, 1000);
	printvector(v1);

	//删除 参数也是迭代器
	v1.erase(v1.begin());
	printvector(v1);

	v1.clear();

	

}






int main()
{

	/*test01();*/

	system("pause");
	return 0;
}
