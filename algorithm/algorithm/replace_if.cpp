#include <iostream>
#include <string>
#include<vector>
#include<algorithm>




using namespace std;

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};


class Greater20
{
public:

    bool operator()(int val)
    {
        return val > 20;
    }


};


void test01()
{
    vector<int>v1;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(50);
    v1.push_back(320);
    v1.push_back(20);
    v1.push_back(40);



    cout << "replace before" << endl;
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;





    replace_if(v1.begin(), v1.end(), Greater20(),3000);
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;


}









 
int main(){
 
 
    system("pause");
    return 0;
 
}