#pragma once
#include"worker.h"
class Employee :public Worker//Ա����
{  
public:
	
	Employee(int a, string name, int b);
	virtual void idShow();//��ʾid
	virtual string getwadress();//��ʾԱ������


};
