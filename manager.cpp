#include "manager.h"
manager::manager(int a, string name, int b)
{
	this->id = a;
	this->name = name;
	this->workadress = b;
	

}
void manager::idShow()
{
	cout << "\t员工id为" << this->id;
	cout << "\t员工姓名" << this->name;
	cout << "\t员工部门编号" << this->workadress;
	cout << "\t岗位职责，完成老板交代的任务" << endl;


}
string manager::getwadress()
{
	
	return string("经理");
}