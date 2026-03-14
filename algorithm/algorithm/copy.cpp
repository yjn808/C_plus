#include <iostream>
#include <string>
#include<algorithm>
#include<vector>


using namespace std;
 //常用拷贝替换算法copy






void myPrint(int val)
{
    cout << val << endl;
}



void test01()
{
    vector<int>v1;


    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    vector<int>v2;
    v2.resize(v1.size());

    copy(v1.begin(),v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), myPrint);


    cout << endl;



}













int main(){
 
 
    system("pause");
    return 0;
 
}