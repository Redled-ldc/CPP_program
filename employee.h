#pragma once
#include"worker.h"
class Employee :public Worker//员工类
{  
public:
	
	Employee(int a, string name, int b);
	virtual void idShow();//显示id
	virtual string getwadress();//显示员工部门


};
