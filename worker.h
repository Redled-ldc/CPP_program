#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker
{ public:
	virtual void idShow()=0;//显示个人信息
	virtual string getwadress() = 0;//显示员工岗位名称

	int id;//职工id
	string name;//职工姓名
	int workadress;//工作部门编号
	

 };
