#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
 
//transform 遍历算法

class Transform
{
public:
    int operator()(int v)
    {
        return v;
    }
};


class print01
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};





void test01()
{
    vector<int>v;
    for (int i = 1; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>vTarget;//目标容器
    vTarget.resize(v.size());
    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for_each(vTarget.begin(), vTarget.end(), print01());


}









int main(){
 
 
    system("pause");
    return 0;
 
}