#include <iostream>
#include <string>
#include<vector>
#include<algorithm>



using namespace std;


void myPrint(int val)
{
    cout << val << endl;
}


class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};





//常用拷贝构造算法 replace
void test01()
{
    vector<int>v;

    v.push_back(20);
    v.push_back(20);
    v.push_back(320);
    v.push_back(50);
    v.push_back(40);

    cout << "replace before" << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
    replace(v.begin(), v.end(), 20, 2000);


    cout << "replace before" << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;


}



 
int main(){
 
 
    system("pause");
    return 0;
 
}