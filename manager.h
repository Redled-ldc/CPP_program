#pragma once
#include "worker.h"
class manager :public Worker 
{

public:

	manager(int a, string name, int b);
	virtual void idShow();//��ʾid
	virtual string getwadress();//��ʾԱ������


};