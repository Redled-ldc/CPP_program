#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker
{ public:
	virtual void idShow()=0;//��ʾ������Ϣ
	virtual string getwadress() = 0;//��ʾԱ����λ����

	int id;//ְ��id
	string name;//ְ������
	int workadress;//�������ű��
	

 };
