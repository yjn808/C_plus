#include <iostream>
#include <string>
#include "speech.h"
using namespace std;
 




int main(){
    
    //创建管理类对象
    SpeedManager sm;

    

    while (true)
    {
        sm.menu();
        cout << " please input your selection " << endl;


        ////测试
        //for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
        //{
        //    cout << "code: " << it->first << "speaker: " << it->second.m_name << "socore: " << it->second.m_score[0] << endl;
        //}


        int choice = 0;
        cin >> choice;

        switch (choice)
        {
        case 1://开始比赛
            sm.StartSpeech();
            break;
        case 2://查看往届记录
            sm.showRcord();
            break;
        case 3://清空比赛记录
            sm.clearRecord();
            break;
        case 0://退出系统
            sm.exitManager();
            break;
        default:
            system("cls");//清屏
            break;
        }







    }

 
    system("pause");
    return 0;
 
}