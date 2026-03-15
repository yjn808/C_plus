#include <iostream>
#include <string>
#include<vector>
#include<algorithm>


using namespace std;

void myprint(int val)
{
    cout << val << endl;
}





//集合文件set_union

void test01()
{
    vector<int>v1;
    vector<int>v2;


    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v1.push_back(i+5);
    }

    vector<int>vTarget;
    //目标容器要提前开辟空间
    vTarget.resize(v1.size() + v2.size());

    vector<int>::iterator itEnd=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myprint);


    cout << endl;

}



 
int main(){
 
 
    system("pause");
    return 0;
 
}