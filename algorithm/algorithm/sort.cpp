#include <iostream>
#include <string>
#include<vector>
#include<algorithm>



using namespace std;

//sort

void myprint(int val)
{
    cout << val << endl;
}


void test01()
{
    vector<int>v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(15);
    v.push_back(12);


    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myprint);

    cout << endl;


    //改为降序
    sort(v.begin(), v.end(), greater<int>());

}


int main(){
 
 
    system("pause");
    return 0;
 
}