#include <iostream>
#include <string>
#include<numeric>
#include<vector>
#include<algorithm>


using namespace std;
 

void myprint(int val)
{
    cout << val << " ";
}

//fill
void test01()
{
    vector<int>v;
    v.resize(10);


    //后期重新填充
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), myprint);
    cout << endl;



}




int main(){
 
 
    system("pause");
    return 0;
 
}