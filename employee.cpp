#include"employee.h"
Employee::Employee(int a, string name, int b)
{
	this->id = a;
	this->name = name;
	this->workadress = b;
	

}
void Employee::idShow()
{
	cout << "\tԱ��idΪ" << this->id;
	cout << "\tԱ������" << this->name;
	cout << "\tԱ�����ű��" << this->workadress;
	cout << "\t��λְ����ɾ�����������" << endl;


}
string Employee::getwadress()
{
	
	return string("Ա��");
 }