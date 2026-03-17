#include <iostream>
#include <string>
#include "student.h"
using namespace std;
 




//默认构造
Student::Student()
{

}

//有参构造
Student::Student(int id, string name, string pwd)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_pwd = pwd;

    //初始化机房信息
    ifstream ifs;

    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom com;
    while (ifs >> com.m_Comid && com.max_num)
    {
        //把读取的信息放入容器
        vCom.push_back(com);
    }
}


//菜单界面
void Student::operMenu()
{
    cout << "========================wlcome manager =================================" << endl;
    cout << "\t\t---------------------------------------------\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                1.  apply order             |\n";
    cout << "\t\t|                2.  show my order           |\n";
    cout << "\t\t|                3.  show all order          |\n";
    cout << "\t\t|                4.  canel order             |\n";
    cout << "\t\t|                0.  delete                  |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|--------------------------------------------|\n";
    cout << "please input your selection:  ";
}



//申请预约
void Student::applyOrder()
{
    cout << "computer open in 1~5" << endl;
    cout << "please input apply time" << endl;
    cout << " 1.Monday" << endl;
    cout << " 2.Tuesday" << endl;
    cout << " 3.Wednesday" << endl;
    cout << " 4.Thursday" << endl;
    cout << " 5.Friday" << endl;


    int date = 0;//日期
    int interval = 0;//时间段
    int room = 0;//机房编号

    while (true)
    {
        cin >> date;
        if (date >= 1 && date <= 5)
        {
            break;
        }
        cout << "input error please input" << endl;
    }
    cout << "please input interval" << endl;
    cout << "1.morning" << endl;
    cout << "2.afternoon" << endl;

    while (true)
    {
        cin >> interval;
        if (interval >= 1 && interval <= 2)
        {
            break;
        }
        cout << "input error please input" << endl;


    }
    cout << "please selection computer" << endl;

    for (int i = 0; i < vCom.size(); i++)
    {
        cout << vCom[i].m_Comid << " capacity is " << vCom[i].max_num << endl;
    }

    while (true)
    {
        cin >> room;
        if (room >= 1 && room <= 3)
        {
            break;
        }
        cout << "input error please input" << endl;
    }

    cout << "order sucessfull" << endl;

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);
    ofs << "date: " << date << " ";
    ofs << "interval: " << interval << " ";
    ofs << "stuid: " << this->m_ID << " ";
    ofs << "stuName: " << this->m_name << " ";
    ofs << "roomid: " << room << " ";
    ofs << "status: " << 1 <<endl;
    ofs.close();

    system("pause");
    system("cls");

}



//查看自身预约
void Student::myOrder()
{
    OrderFile of;

    if (of.m_Size == 0)
    {
        cout << "not order" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < of.m_Size; i++)
    {
        //string 转int
        //string 利用 .c_str()转const char*
        //利用atoi (const char*)转int
        if (this->m_ID == atoi(of.m_orderData[i]["stuid"].c_str()))
        {
            //找到自身预约
            cout << "order time: 1~5" << of.m_orderData[i]["date"];
            cout << "order time: morning or tomorrow" << of.m_orderData[i]["interval"];
            cout << "order time: computer" << of.m_orderData[i]["roomid"];
            string status = "status: ";
            if (of.m_orderData[i]["status"] == "1")
            {
                status += "running";
            }
            else if (of.m_orderData[i]["status"] == "2")
            {
                status += "order sucessful";
            }
            else if (of.m_orderData[i]["status"] == "-1")
            {
                status += "erro";
            }
            else
            {
                status += "not";
            }
            cout << status << endl;
        }

        system("pause");
        system("cls");

    }







}


//查看所有预约
void Student::showAllOrder()
{
    OrderFile of;
    if (of.m_Size == 0)
    {
        cout << "not list" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < of.m_Size; i++)
    {
        cout << i + 1 << " ";
        cout << "date is : " << of.m_orderData[i]["date"];
        cout << "interval is : " << (of.m_orderData[i]["interval"] == "1" ? "morning" : "afternoon");
        cout << "id is : " << of.m_orderData[i]["stuid"];
        cout << "name is : " << of.m_orderData[i]["stuName"];
        cout << "roomid is : " << of.m_orderData[i]["roomid"];

        string status = "status: ";
        if (of.m_orderData[i]["status"] == "1")
        {
            status += "running";
        }
        else if (of.m_orderData[i]["status"] == "2")
        {
            status += "order sucessful";
        }
        else if (of.m_orderData[i]["status"] == "-1")
        {
            status += "erro";
        }
        else
        {
            status += "not";
        }
        cout << status << endl;
    }
    system("pause");
    system("cls");

}


//取消预约
void Student::cancelOrder()
{
    OrderFile of;
    if (of.m_Size == 0)
    {
        cout << "not list" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << " please Cancel" << endl;


    vector<int>v;//存放在最大容器的下标编号
    int index = 1;
    for (int i = 0; i < of.m_Size; i++)
    {
        //先判断是自身id
        if (this->m_ID == atoi(of.m_orderData[i]["stuid"].c_str()))
        {
            //筛选状态
            if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
            {
                v.push_back(i);
                cout << index++ << " ";
                cout << "date : " << of.m_orderData[i]["date"];
                cout << "interval : " << (of.m_orderData[i]["interval"] == "1" ? "morning" : "afternoon");
                cout << "roomid : " << of.m_orderData[i]["roomid"];

                string status = "status";
                if (of.m_orderData[i]["status"] == "1")
                {
                    status += "running";
                }
                else if (of.m_orderData[i]["status"] == "2")
                {
                    status += "order sucessful";
                }
                cout << status << endl;

            }
        }
    }


    cout << "please input canel Record" << endl;
    int select = 0;

    while (true)
    {
        cin >> select;

        if (select >= 0 && select <= v.size())
        {
            if (select == 0)
            {
                break;
            }
            else
            {
                of.m_orderData[v[select - 1]]["status"] = "0";

                of.updateOrder();
                cout << "cancel sucessful" << endl;
            }

        }
        cout << "input erro" << endl;





    }
    system("pause");
    system("cls");
}























