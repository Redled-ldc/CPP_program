#include "boss.h"

boss::boss(int a, string name,int b )
{
	this->id = a;
	this->name = name;
	this->workadress = b;
	

}
void boss::idShow()
{
	cout << "\t员工id为" << this->id;
	cout << "\t员工姓名" << this->name;
	cout << "\t员工部门编号" << this->workadress;
	cout << "\t岗位职责，完成管理公司的任务" << endl;


}
string boss::getwadress()
{
	
	return string("老板");
}