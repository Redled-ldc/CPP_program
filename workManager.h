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
	//展示菜单函数
	void Show_Menu();
	void Exit_System();
	int emnumber;//记录职工人数
    Worker** emp;//职工数组指针
	void add();//添加职工
	void save();//保存文件
	bool fileempty;
	int getnum();//统计文件中的人数
	void temp();//初始化数组
	~workManager();

	

};