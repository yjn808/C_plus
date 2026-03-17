#pragma once
#include<iostream>
#include "identity.h"
#include<string>

using namespace std;




class Teacher:public Identity
{
public:
	
	//Default Construction
	Teacher();



	//Parameterized Constructor
	Teacher(int empid, string name, string pwd);


	//Menu Interface
	virtual void operMenu();


	//View All Appointments
	void showAllOrder();

	//Review Appointment
	void validOrder();



	//Employee ID
	int m_EmpID;



};










