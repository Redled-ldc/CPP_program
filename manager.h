#pragma once
#include "worker.h"
class manager :public Worker 
{

public:

	manager(int a, string name, int b);
	virtual void idShow();//显示id
	virtual string getwadress();//显示员工部门


};