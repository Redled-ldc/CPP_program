#pragma once
#include "worker.h"
class boss :public Worker//员工类
{
public:

	boss(int a, string name, int b);
	virtual void idShow();//显示id
	virtual string getwadress();//显示员工部门


};