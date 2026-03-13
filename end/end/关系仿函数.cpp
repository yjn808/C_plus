#include <iostream>
#include <string>
#include<vector>
using namespace std;
#include<algorithm>
#include<functional>

//内建的仿函数
//大于 greater

class mycompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};









void test01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    v.push_back(10);


    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    cout << endl;


    //降序
    sort(v.begin(), v.end(), mycompare());
    sort(v.begin(), v.end(), greater<int>());//系统内建


}
















int main(){
 
 
    system("pause");
    return 0;
 
}