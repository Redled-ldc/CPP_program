#include "boss.h"

boss::boss(int a, string name,int b )
{
	this->id = a;
	this->name = name;
	this->workadress = b;
	

}
void boss::idShow()
{
	cout << "\tԱ��idΪ" << this->id;
	cout << "\tԱ������" << this->name;
	cout << "\tԱ�����ű��" << this->workadress;
	cout << "\t��λְ����ɹ���˾������" << endl;


}
string boss::getwadress()
{
	
	return string("�ϰ�");
}