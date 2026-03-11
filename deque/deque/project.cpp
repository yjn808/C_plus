#include <iostream>
#include <string>
using namespace std;
#include<vector>
#include<queue>
#include<algorithm>
#include<ctime>
//选手类
class Person
{
public:

    Person(string name, int score)
    {
        this->m_name = name;
        this->m_score = score;
    }
    string m_name;
    int m_score;

};

void creatPerson(vector<Person>& P)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "people";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);

        //将创建的Person对象放入容器
        P.push_back(p);

    }
}

void setscore(vector<Person>& v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        //将评委分数 放入deque容器
        deque<int>d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;//60~100
            d.push_back(score);
        }

        /*cout << "people" << it->m_name << "score:" << endl;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            cout << *dit << " ";
        }
        cout << endl;*/
        //排序
        sort(d.begin(), d.end());

        //去掉最高最低分 deque有这个函数操作
        d.pop_back();
        d.pop_front();

        //取平均分
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += (*dit);
        }
        int avg = sum / d.size();



        //将平均分赋值给选手

        it->m_score = avg;

    }
}
void showScore(vector<Person>& v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "People name is:" << it->m_name <<"score:" << it->m_score << endl;
    }
}

int main(){

    //随机种子
    srand((unsigned int)time(NULL));
    //创建5名选手
    vector<Person> p;
    creatPerson(p);

    //测试
  /*  for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
    {
        cout <<"name:" << (*it).m_name << "score:" << (*it).m_score;
    }
    cout << endl;*/
    
    //给5名选手打分
    setscore(p);



    //显示最后得分
    showScore(p);




 
    system("pause");
    return 0;
 
}