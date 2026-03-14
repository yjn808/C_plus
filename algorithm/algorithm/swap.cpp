#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
 


//常用拷贝替换算法 swap(同种容器）

void myprint(int val)
{
    cout << val << endl;
}




void test()
{
    vector<int>v;


    vector<int>c;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        v.push_back(i + 10);
    }


    cout << "swap before" << endl;
    for_each(v.begin(), v.end(), myprint);
    cout << endl;
    for_each(c.begin(), c.end(), myprint);
    cout << endl;



    cout << "swap  end" << endl;
    swap(v, c);
    for_each(v.begin(), v.end(), myprint);
    cout << endl;
    for_each(c.begin(), c.end(), myprint);
    cout << endl;


}











int main(){
 
 
    system("pause");
    return 0;
 
}