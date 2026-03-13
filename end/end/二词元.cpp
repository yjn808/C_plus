#include <iostream>
#include <string>
#include<vector>
using namespace std;
#include<algorithm>
//二元谓词


class mycompare
{
public:
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
        
};




int main(){
 
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);


    sort(v.begin(),v.end());

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";

    }
    //使用函数对象改变算法策略，改为排序规则为从大到小
    sort(v.begin(), v.end(), mycompare());
    








    system("pause");
    return 0;
 
}