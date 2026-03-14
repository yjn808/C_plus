#include <iostream>
#include <string>
#include<vector>
#include<algorithm>



using namespace std;
 


void myprint(int val)
{
    cout <<val<< endl;
}

void test01()
{
    vector<int>v1;
    vector<int>v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }


    vector<int>vTarget;
    //提前给目标容器分配空间 不然崩溃
    vTarget.resize(v1.size() + v2.size());



    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), myprint);
    cout << endl;


}







int main(){
 
 
    system("pause");
    return 0;
 
}