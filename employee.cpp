#include"employee.h"
Employee::Employee(int a, string name, int b)
{
	this->id = a;
	this->name = name;
	this->workadress = b;
	

}
void Employee::idShow()
{
	cout << "\t员工id为" << this->id;
	cout << "\t员工姓名" << this->name;
	cout << "\t员工部门编号" << this->workadress;
	cout << "\t岗位职责，完成经理交代的任务" << endl;


}
string Employee::getwadress()
{
	
	return string("员工");
 }