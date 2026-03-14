#include <iostream>
#include <string>
#include<algorithm>
#include<vector>

using namespace std;
 

//查找的元素必须为有序序列

void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    bool ret = binary_search(v.begin(), v.end(), 9);


}









int main(){
 
 
    system("pause");
    return 0;
 
}