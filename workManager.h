#pragma once
#include <iostream>
#include"worker.h"
#include <fstream>
constexpr auto filename = "empfile.txt";
using namespace std;
class workManager
{
 public:
	workManager();
	//չʾ�˵�����
	void Show_Menu();
	void Exit_System();
	int emnumber;//��¼ְ������
    Worker** emp;//ְ������ָ��
	void add();//���ְ��
	void save();//�����ļ�
	bool fileempty;
	int getnum();//ͳ���ļ��е�����
	void temp();//��ʼ������
	~workManager();

	

};