#include <iostream>
#include <string>
#include<numeric>
#include<vector>

using namespace std;
 



void test01()
{
    vector<int>v;


    for (int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }
    //参数三是起始累加值
    int total=accumulate(v.begin(), v.end(), 0);

    cout << "total=" << total << endl;






}






int main(){
 
 
    system("pause");
    return 0;
 
}