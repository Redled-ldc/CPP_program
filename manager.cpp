#include "manager.h"
manager::manager(int a, string name, int b)
{
	this->id = a;
	this->name = name;
	this->workadress = b;
	

}
void manager::idShow()
{
	cout << "\tԱ��idΪ" << this->id;
	cout << "\tԱ������" << this->name;
	cout << "\tԱ�����ű��" << this->workadress;
	cout << "\t��λְ������ϰ彻��������" << endl;


}
string manager::getwadress()
{
	
	return string("����");
}