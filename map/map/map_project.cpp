#include <iostream>
#include <string>
#include<map>
using namespace std;
#include<vector>
#define CEHUA 0
#define MEISHU 1
#define YANFA 2
#include<ctime>


class worker
{
public:




    string m_name;
    int m_salary;
};


void createWorker(vector<worker>& W)
{
    string nameSEED = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        worker Worker;
        Worker.m_name = "people";
        Worker.m_name += nameSEED[i];

        Worker.m_salary = rand() % 10000 + 10000;//10000~19999
        //将员工放入融器
        W.push_back(Worker);

    }
}

void setGroup(vector<worker>& v, multimap<int, worker>& m)
{
    for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        //产生随机部门编号
        int deptId = rand() % 3;//0 1 2
        //将员工插入到分组中
        //key是部门编号 value具体员工
        m.insert(make_pair(deptId, *it));

    }
}

void showWorkerByGroup(multimap<int, worker>& m)
{
    //0: A,B,C
    cout << "plan out" << endl;
    multimap<int, worker>::iterator pos=m.find(CEHUA);

    int cnt=m.count(CEHUA);//统计策划部门人数
    int index = 0;
    for (; pos != m.end() && index<cnt; pos++ ,index++)
    {
        cout << "name:" << pos->second.m_name << "salary" << pos->second.m_salary << endl;
    }


    cout << "figure" << endl;
    multimap<int, worker>::iterator pos = m.find(CEHUA);

    int cnt = m.count(MEISHU);//统计策划部门人数
    int index = 0;
    for (; pos != m.end() && index < cnt; pos++, index++)
    {
        cout << "name:" << pos->second.m_name << "salary" << pos->second.m_salary << endl;
    }



    cout << "experience" << endl;
    multimap<int, worker>::iterator pos = m.find(CEHUA);

    int cnt = m.count(YANFA);//统计策划部门人数
    int index = 0;
    for (; pos != m.end() && index < cnt; pos++, index++)
    {
        cout << "name:" << pos->second.m_name << "salary" << pos->second.m_salary << endl;
    }

}


int main(){

    srand((unsigned int)time(NULL));


    //1.创建员工
    vector<worker>Worker;
    createWorker(Worker);

    //测试
    /*for (vector<worker>::iterator it = Worker.begin(); it != Worker.end(); it++)
    {
        cout << "name is =" << it->m_name << "salary " << it->m_salary << endl;
    }*/

    //2.员工分组
    multimap<int, worker>mworker;
    setGroup(Worker,mworker);


    //3.分组显示员工
    showWorkerByGroup(mworker);
 
    system("pause");
    return 0;
 
}