#include<iostream>
using namespace std;
#include<vector>






//vector 容器的容量大小操作

void printvector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
}



void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	printvector(v1);




	if (v1.empty())//为真代表容器为空
	{
		cout << "v1 is empty " << endl;
	}
	else
	{
		cout << "v1 is not empty" << endl;
		cout << "v1 capacity is" << v1.capacity();
		cout << "v1 size is " << v1.size();
	}

	//重新指定大小
	v1.resize(15);//利用重载版本可以指定默认填充值
	printvector(v1);//如果重新指定过长默认用0扩充

	v1.resize(5);
	printvector(v1);//如果指定短了则删除





}




int main()
{

	/*test01();*/

	system("pause");
	return 0;
}

