#include <iostream>
#include <string>
#include<set>
#include<vector>
#include<numeric>
#include <algorithm>

using namespace std;
 

void myprint(int val)
{
    cout << val << " ";
}



//常用集合算法 set_intersection

void test01()
{
    vector<int>v;
    vector<int>v1;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        v1.push_back(i+5);
    }



    vector<int>vTarget;
    vTarget.resize(min(v.size(), v1.size()));

    //获取交集
    vector<int>::iterator itEnd=set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, myprint);
    cout << endl;


}



int main(){
 
 
    system("pause");
    return 0;
 
}