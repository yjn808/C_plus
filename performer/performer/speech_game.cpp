#include <iostream>
#include <string>
#include "speech.h"

using namespace std;



SpeedManager::SpeedManager()
{
    //初始化容器和属性
    this->initSpeech();

    //创建12名选手
    this->CreateSpeaker();

    //加载往届记录
    this->loadRecord();

    

}

void SpeedManager::menu()
{
    cout << "Please section" << endl;
    cout << "*************************************************" << endl;
    cout << "******** weclome to take part in this  **********" << endl;
    cout << "********      1.start speed game       **********" << endl;
    cout << "********      2.show before list       **********" << endl;
    cout << "********      3.clear game history     **********" << endl;
    cout << "********      0.exit this              **********" << endl;
    cout << "*************************************************" << endl;
    cout << endl;
}

void SpeedManager::initSpeech()
{
    //保证容器置空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    //初始化比赛轮数
    this->m_Index = 1;

    //初始化记录容器（清空）
    this->M_Record.clear();
}

void SpeedManager::CreateSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "Speaker ";
        name += nameSeed[i];
        //创建选手
        Speaker sp;
        sp.m_name = name;
        
        for (int j = 0; j < 2; j++)
        {
            sp.m_score[j] = 0;
        }

        //创建选手编号并放入v1容器
        this->v1.push_back(i + 10001);

        //选手编号以及对应选手放入map容器
        this->m_Speaker.insert(make_pair(i + 10001, sp));



    }
}
void SpeedManager::speedDraw()
{
    cout << "this is << " << this->m_Index << " >>cycle" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Draw end : " << endl;

    random_device rd;
    mt19937 g(rd());

    if (this->m_Index == 1)
    {
        //第一轮比赛
        shuffle(v1.begin(), v1.end(),g);
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        //第二轮比赛
        shuffle(v2.begin(), v2.end(),g);
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    cout << "-------------------------------------" << endl;
    system("pause");
    cout << endl;

}

void SpeedManager::Speechcontest()
{
    cout << "--------------for" << this->m_Index << " cycle was start---------------" << endl;

    //准备临时容器 存放小组成绩
    multimap<double, int, greater<double>> groupScore;

    int num = 0;//用于记录人员个数


    vector<int>v_src;//比赛选手容器
    if (this->m_Index == 1)
    {
        v_src = v1;
    }
    else
    {
        v_src = v2;
    }

    for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
    {
        num++;
        //评委打分 
        deque<double>d;
        for (int i = 0; i < 10; i++)
        {
            double score = rand()%401+600/10.f;//600~1000
            //cout << score<<" ";
            d.push_back(score);
        }

        //cout << endl;
        sort(d.begin(), d.end(), greater<double>());//排序
        d.pop_front();//去除最高分
        d.pop_back();//去除最低分


        double sum = accumulate(d.begin(), d.end(), 0.0f);//总分
        double avg = sum / (double)d.size();//平均分

        //打印平均分
        //cout << "code: " << *it << "name: " << this->m_Speaker[*it].m_name << "get avg score" << avg << endl;

        //将平均分放入map容器
        this->m_Speaker[*it].m_score[this->m_Index - 1] = avg;


        //将打分数据存入临时容器
        groupScore.insert(make_pair(avg, *it));//key是得分，value是具体选手编号

        //每6人取出前3名
        if (num % 6 == 0)
        {
            cout << " the one is  : " << num / 6 << "group" << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "code:" << it->second << "name:" 
                    << this->m_Speaker[it->second].m_name 
                    << this->m_Speaker[it->second].m_score[this->m_Index-1] << endl;
            }

            //取走前三名
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin() ; it != groupScore.end() && count < 3; it++, count++)
            {
                if (this->m_Index)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    vVictory.push_back((*it).second);
                }
            }
            groupScore.clear();//临时容器清空
        }



    }

    cout << "-------------this speech"<<this->m_Index<<"cycle end" << endl;

}

void SpeedManager::showScore()
{
    cout << "-----------cycle:" << this->m_Index << "speaker----------" << endl;

    vector<int>v;
    if (this->m_Index == 1)
    {
        v = v2;
    }
    else
    {
        v = vVictory;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "code:" << *it << "name:" << this->m_Speaker[*it].m_name
            << "score:" << this->m_Speaker[*it].m_score[this->m_Index - 1] << endl;
    }
    cout << endl;

    system("pause");
    system("cls");
    this->menu();

}

void SpeedManager::StartSpeech()
{
    //第一论开始比赛

    //1.抽签
    this->speedDraw();
    //2.比赛
    this->Speechcontest();
    //3.显示晋级结果
    this->Speechcontest();
    //第二轮开始比赛
    this->m_Index++;
    //1.抽签
    this->speedDraw();
    //2.比赛
    this->Speechcontest();
    //3.显示最终结果
    this->Speechcontest();
    //保存分数到文件
    this->saveRecord();


    //重置比赛获取记录
    //初始化容器和属性
    this->initSpeech();

    //创建12名选手
    this->CreateSpeaker();

    //加载往届记录
    this->loadRecord();


    cout << "game end" << endl;
    system("pause");
    system("cls");



}
void SpeedManager::saveRecord()
{
    ofstream ofs;

    ofs.open("speech.csv", ios::out | ios::app);

    //将每个选手数据写入文件中
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
    {
        ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
    }
    ofs << endl;

    //关闭
    ofs.close();
    cout << "file save" << endl;

    //更改文件不为空的状态
    this->fileempty = false;

}

void SpeedManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in);

    if (!ifs.is_open())
    {
        this->fileempty = true;
        /*cout << "file not find" << endl;*/
        ifs.close();
        return;
    }

    //文件清空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //cout << "file empty" << endl;
        this->fileempty = true;
        ifs.close();
        return;

    }

    //文件不为空
    this->fileempty = false;
    ifs.putback(ch);//将上面读取的单个字符读回来

    string data;
    int index = 0;


    while (ifs >> data)
    {
        /*cout << data << endl;*/

        int pos = -1;//查到“，”位置的变量
        int start = 0;

        vector<string>v;//为了存放6个string的字符串

        while (true)
        {
            pos = data.find(",", start);
            if (pos == -1)
            {
                //没有找到
                break;

            }
            string temp = data.substr(start, pos - start);
            //cout << temp << endl;
            v.push_back(temp);
            start = pos + 1;

        }
        this->M_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();


   /* for (map<int, vector<string>>::iterator it = M_Record.begin(); it != M_Record.end(); it++)
    {
        cout << it->first << "code" << it->second[0] << "score" << it->second[1] << endl;
    }*/

}

void SpeedManager::showRcord()
{
    if (this->fileempty)
    {
        cout << "file is empty or notfind it" << endl;
    }
    else
    {
        for (int i = 0; i < this->M_Record.size(); i++)
            {
                cout << " this" << i + 1 << "game" 
                    << "one code is:" << this->M_Record[i][0] <<"score" << this->M_Record[i][1] 
                    << "two code is:" << this->M_Record[i][2] << "score" << this->M_Record[i][3] 
                    << "one code is:" << this->M_Record[i][4] << "score" << this->M_Record[i][5] << endl;
            }
    }
    system("pause");
    system("cls");
}


void SpeedManager::clearRecord()
{

    cout << "is clear file?" << endl;
    cout << "1. yes" << endl;
    cout << "2. no" << endl;
    int select = 0;
    if (select == 1)
    {
        //确认清空
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        //初始化容器和属性
        this->initSpeech();

        //创建12名选手
        this->CreateSpeaker();

        //加载往届记录
        this->loadRecord();

        cout << "clear sucessful" << endl;

    }
    system("pause");
    system("cls");


}

void SpeedManager::exitManager()
{
    cout << " welcome next apply " << endl;
    system("pause");
    exit(0);
}
SpeedManager::~SpeedManager()
{



}



 
