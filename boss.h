#pragma once
#include "worker.h"
class boss :public Worker//Ա����
{
public:

	boss(int a, string name, int b);
	virtual void idShow();//��ʾid
	virtual string getwadress();//��ʾԱ������


};