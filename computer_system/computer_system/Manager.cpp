#include <iostream>
#include <string>
#include "Manager.h"
#include<fstream>
#include "globalFile.h"

using namespace std;
 
//默认构造
Manager::Manager()
{






}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;

    //初始化容器 获取文件中学生老师信息
    this->initVector();


    //初始化机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom com;
    while (ifs >> com.m_Comid && ifs >> com.max_num)
    {
        vCom.push_back(com);
    }
    ifs.close();
    cout << "num compter" << vCom.size() << endl;
    
}

//菜单界面
void Manager::operMenu()
{
    cout << "========================wlcome manager =================================" << endl;
    cout << "\t\t---------------------------------------------\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                1.  add person              |\n";
    cout << "\t\t|                2.  show person             |\n";
    cout << "\t\t|                3.  show computer           |\n";
    cout << "\t\t|                4.  clean reserve           |\n";
    cout << "\t\t|                0.  delete                  |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|                                            |\n";
    cout << "\t\t|--------------------------------------------|\n";
    cout << "please input your selection:  ";
}


//添加账号
void Manager::addPerson()
{
    cout << "please input count type" << endl;
    cout << "1.add studen" << endl;
    cout << "2.add teacher" << endl;

    string fileName;//操作的文件名
    string tip;//提示id号


    string erroTip;//错误重复提示

    ofstream ofs;//文件操作对象

    int select = 0;
    cin >> select;
    if (select == 1)
    {
        //添加的是学生
        fileName = STUDENT_FILE;
        tip = "please input your id";
        erroTip = "id repeat";
    }
    else
    {
        fileName = TEACHER_FILE;
        tip = "please input your tid";
        erroTip = "id repeat";
    }

    //利用追加的方式写文件
    ofs.open(fileName, ios::out | ios::app);

    int id;
    string name;
    string pwd;

    while (true)
    {
        cin >> id;
        bool ret=checkRepeat(id, select);
        if (ret)
        {
            cout << erroTip << endl;
        }
        else
        {
            break;
        }

    }

    cout << tip << endl;
    cin >> id;

    cout << "please input your name" << endl;
    cin >> name;

    cout << "please input your key" << endl;
    cin >> pwd;

    //向文件中添加数据
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "add sucessful" << endl;
    system("pause");
    system("cls");
    ofs.close();


    //调用初始化容器接口 重新获取文件中的数据
    this->initVector();
}


void printStudent(Student& s)
{
    cout << "id" << s.m_ID << "name" << s.m_name << "code" << s.m_pwd << endl;

}
void printTeacher(Teacher& s)
{
    cout << "id" << s.m_EmpID << "name" << s.m_name<< "code" << s.m_pwd<< endl;

}


//显示账号
void Manager::showPerson()
{
    cout << "please selection show context" << endl;
    cout << " 1. show student" << endl;
    cout << "2.show teacher" << endl;

    int select = 0;//接收用户选择
    cin >> select;


    if (select == 1)
    {
        //查看学生
        cout << "all student message" << endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    }
    else
    {
        cout << "all teacher message" << endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }

    system("pause");
    system("cls");




}

//查看机房信息

void Manager::showCompeter()
{
    cout << "computer message is" << endl;
    for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
    {
        cout << "code of computer is" << (*it).m_Comid << "num of computer" << it->max_num << endl;
    }
}


//清空预约记录
void Manager::cleanFile()
{
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "clean sucessfull" << endl;
    system("pause");
    system("cls");


}



//初始化容器
void Manager::initVector()
{
    //确保容器清空
    vStu.clear();
    vTea.clear();

    //读取信息  学生、老师
    ifstream ifs;

    ifs.open(STUDENT_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "file read erro" << endl;
        return;

    }
    
    Student s;
    while (ifs >> s.m_ID && ifs >> s.m_name && ifs >> s.m_pwd)
    {
        vStu.push_back(s);
    }

    cout << "number of student " << vStu.size() << endl;
    ifs.close();


    //读取信息  老师
    ifs.open(TEACHER_FILE, ios::in);
    Teacher t;
    while (ifs >> t.m_EmpID && ifs >> t.m_name && ifs >> t.m_pwd)
    {
        vTea.push_back(t);
    }

    cout << "the teacher number is" << endl;
    ifs.close();




}

bool Manager::checkRepeat(int id, int type)
{
    if (type == 1)
    {
        //检测学生
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
        {
            if (id == it->m_ID)
            {
                return true;
            }

        }
    }
    else
    {
        //检测老师
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
        {
            if (id == it->m_EmpID)
            {
                return true;
            }
        }


    }
    return false;
}





