#include <iostream>
#include <string>
#include "identity.h"
#include <fstream>
#include "globalFile.h"
#include "student.h"
#include "Manager.h"
#include "teacher.h"
using namespace std;
 


//进入管理员子菜单界面
void managerMenu(Identity*& manager)
{
    while (true)
    {
        //调用管理员子菜单
        manager->operMenu();

        //将父类指针 转为子类指针 调用子类里其他接口
        Manager* man = (Manager*)manager;

        int select = 0;
        //接收用户选择
        cin >> select;

        if (select == 1)
        {
            cout << "add count" << endl;
            man->addPerson();
        }
        else if (select == 2)
        {
            cout << "show count" << endl;
            man->showPerson();
        }
        else if (select == 3)
        {
            cout << "show computer" << endl;
            man->showCompeter();
        }
        else if (select == 4)
        {
            cout << "clean reserve" << endl;
            man->cleanFile();
        }
        else
        {
            delete manager;
            cout << "delete sucessful" << endl;
            system("pause");
            system("cls");
            return;
        }

        
    }
}


//进入学生子菜单管理界面
void studentMenu(Identity*& student)
{
    while (true)
    {
        //调用学生子菜单
        student->operMenu();
        

        Student* stu = (Student*)student;

        int select=0;
        cin >> select;//接收用户选择

        if (select == 1)//申请预约
        {
            stu->applyOrder();
        }
        else if (select == 2)
        {
            stu->myOrder();
        }
        else if (select == 3)//查看所有人预约
        {
            stu->showAllOrder();
        }
        else if (select == 4)//取消预约
        {
            stu->cancelOrder();

        }
        else
        {
            //注销登录
            delete student;
            cout << "delete sucessful" << endl;
            system("pause");
            system("cls");
            return;
        }






    }
}


//进入老师菜单界面
void teacherMenu(Identity*& teacher)
{

    while (true)
    {
        teacher->operMenu();


        Teacher* tea = (Teacher*)teacher;
        int select = 0;
        cin >> select;

        if (select == 1)
        {
            tea->showAllOrder();
        }
        else if (select == 2)
        {
            tea->validOrder();
        }
        else
        {
            delete teacher;
            cout << "delete sucessful" << endl;
            system("pause");
            system("cls");
            return;

        }



    }





}





//登录功能  1.操作文件名  2. 操作身份类型
void login(string fileName,int type)
{


    //父类指针指向子类对象
    Identity* person = NULL;

    //读文件
    ifstream ifs;
    ifs.open(fileName, ios::in);


    //判断文件存在？
    if (!ifs.is_open())
    {
        cout << "file is not find" << endl;
        ifs.close();
        return;
    }
    //准备接收用户信息
    int id = 0;
    string name;
    string pwd;



    //判断身份
    if (type == 1)
    {
        cout << "please input your id" << endl;
        cin >> id;
    }
    else if(type==2)
    {
        cout << "please input your teacher id" << endl;
        cin >> id;
    }
    
    cout << "please input name" << endl;
    cin >> name;


    cout << "please input key" << endl;
    cin >> pwd;

    if (type == 1)
    {
        //学生身份验证

        //从文件读取的id
        int fid;
        string fName;//从文件获取的姓名
        string fPwd;//从文件获取的密码
        while (ifs >> fid && ifs >> fName && ifs >> fPwd)
        {
            //与用户输入信息做对比
            if (fid == id && fName == name && fPwd == pwd)
            {
                cout << "student login scessful" << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);

                //进入学生身份子菜单
                studentMenu(person);

                return;

            }
        }  



    }
    else if (type == 2)
    {
        //教师身份验证
        int fID;//文件获取id
        string fName;//文件获取姓名
        string fPwd;//文件获取密码

        while (ifs >> fID && ifs >> fName && ifs >> fPwd)
        {
            if (fID == id && fName == name && fPwd == pwd)
            {
                cout << "login sucessful" << endl;
                system("pause");
                system("cls");

                person = new Teacher(id, name, pwd);


                //进入教师子菜单界面
                teacherMenu(person);
                return;

            }
        }



    }
    else if (type == 3)
    {
        //管理员身份验证
        string fName;
        string fPwd;

        while (ifs >> fName && ifs >> fPwd)
        {
            if (fName == name && fPwd == pwd)
            {
                cout << "login sucessful" << endl;
                system("pause");
                system("cls");

                person = new Manager(name, pwd);



                //进入管理员子菜单界面
                managerMenu(person);

                return;
            }
        }


    }

    cout << "login error" << endl;
    system("pause");
    system("cls");

    return;

}























int main(){

    int select = 0;//用于接收用户选择
    while (true)
    {
        cout << "========================wlcome to this system =================================" << endl;
        cout << "please your identity " << endl;
        cout << "\t\t---------------------------------------------\n";
        cout << "\t\t|                                            |\n";
        cout << "\t\t|                                            |\n";
        cout << "\t\t|                1.  student                 |\n";
        cout << "\t\t|                                            |\n";
        cout << "\t\t|                2.  teacher                 |\n";
        cout << "\t\t|                                            |\n";
        cout << "\t\t|                3.  manager                 |\n";
        cout << "\t\t|                                            |\n";
        cout << "\t\t|                0.  exit                    |\n";
        cout << "\t\t|                                            |\n";
        cout << "\t\t|--------------------------------------------|\n";
        cout << "please input your selection:  ";

        cin >> select;

        switch (select)
        {
        case 1:
            login(STUDENT_FILE, 1);
            break;
        case 2:
            login(TEACHER_FILE, 2);
            break;
        case 3:
            login(ADMIN_FILE, 3);
            break;
        case 0://退出系统
            cout << "welcome next apply" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "input error,please input" << endl;
            system("pause");
            system("cls");
            break;
        }
        

   
    }

    system("pause");
    system("cls");
    return 0;
 
}