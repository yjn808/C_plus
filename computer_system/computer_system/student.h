#pragma once
#include<iostream>
#include "identity.h"
#include<string>
#include<vector>
#include "computerroom.h"
#include<fstream>
#include "globalFile.h"
#include "orderfile.h"

using namespace std;


//student
class Student:public Identity
{
public:

	//Default Construction
	Student();

	//Parameterized Constructor
	Student(int id, string name, string pwd);


	//Menu Interface
	virtual void operMenu();



	//Request an Appointment
	void applyOrder();


	void myOrder();


	//View All Appointments
	void showAllOrder();


	//Cancel Appointment
	void cancelOrder();


	//Student ID Number
	int m_ID;

	vector<ComputerRoom>vCom;


};











