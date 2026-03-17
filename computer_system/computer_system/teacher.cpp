#include <iostream>
#include <string>
#include "teacher.h"
#include<vector>
#include "computerroom.h"
#include<fstream>
#include "globalFile.h"
#include "orderfile.h"



using namespace std;
 






//Default Construction
Teacher::Teacher()
{

}



//Parameterized Constructor
Teacher::Teacher(int empid, string name, string pwd)
{
	this->m_EmpID = empid;
	this->m_name = name;
	this->m_pwd = pwd;



}


//Menu Interface
void Teacher::operMenu()
{
    cout << "========================wlcome manager =================================" << endl;
    cout << "\t\t---------------------------------------------\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                1.  show all order          |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                2.  Review order            |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                0.  delete                  |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|--------------------------------------------|\n";
    cout << "please input your selection:  ";
}


//View All Appointments
void Teacher::showAllOrder()
{
    OrderFile of;
    if(of.m_Size == 0)
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

//Review Appointment
void Teacher::validOrder()
{
    OrderFile of;
    if (of.m_Size == 0)
    {
        cout << "not list" << endl;
        system("pause");
        system("cls");
        return;
    }


    vector<int>v;
    int index = 0;

    cout << "Review order " << endl;

    for (int i = 0; i < of.m_Size; i++)
    {
        if (of.m_orderData[i]["status"] == "1")
        {
            v.push_back(i);
            cout << ++index << " 、";
            cout << "reserve date is " << of.m_orderData[i]["date"];
            cout << "interval is " << (of.m_orderData[i]["interval"] == "1" ? "morning" : "afternoon");
            cout << "id is : " << of.m_orderData[i]["stuid"];
            cout << "name is : " << of.m_orderData[i]["stuName"];
            cout << "roomid is : " << of.m_orderData[i]["roomid"];

            string status = "status:running";
            cout << status << endl;







        }
    }

    cout << "please input review list " << endl;
    int select = 0;
    int ret = 0;//接受预约结果

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
                cout << "1. yes" << endl;
                cout << "2.no" << endl;
                cin >> ret;
                if (ret == 1)
                {
                    //通过情况
                    of.m_orderData[v[select - 1]]["status"] = "2";
                }
                else
                {
                    //不通过情况
                    of.m_orderData[v[select - 1]]["status"] = "-1";
                }
                of.updateOrder();
                cout << "review ok" << endl;
                break;

            }
            cout << "input erro please input" << endl;

        }





    }

    system("pause");
    system("cls");


}














