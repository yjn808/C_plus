#include <iostream>
#include <string>
#include<algorithm>

#include<vector>
using namespace std;
 


void Print(int val)
{
    cout << val << endl;
}
//常用的排序算法
void test01()
{
    vector<int>v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);


    cout << "rsverse before" << endl;
    for_each(v.begin(), v.end(),Print);


    cout << "reverse end" << endl;


    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), Print);
    cout << endl;



}



int main(){
 
 
    system("pause");
    return 0;
 
}