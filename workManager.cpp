#include "workManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <string>
workManager::workManager()
{//1���ļ�������
	ifstream ifs;
	ifs.open("filename", ios::in);//���ļ�
	if (!ifs.is_open())
	{

		//cout << "�ļ�������" << endl;
		//��ʼ������
		this->emnumber = 0;
		//��ʼ������ָ��
		this->emp = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->fileempty = true;
		ifs.close();
		return;
		

	}
	//2,�ļ����ڵ�û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->emnumber = 0;
		//��ʼ������ָ��
		this->emp = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->fileempty = true;
		ifs.close();
		return;

	}
	//3���ļ����ڣ�������
	
	int num = this->getnum();
	//cout << "��" << num << "��Ա��" << endl;
	this->emnumber = num;//����Ա������
	this->emp = new Worker * [this->emnumber];//����ְ��������ְ����ֵָ��
	this->temp();//��ʼ��ְ�����ļ��е����ݴ���������
	/*for (int i=0; i < this->emnumber; i++)
	{
		cout << "ְ�����:" << this->emp[i]->id<<" ";
		cout << "ְ������:" << this->emp[i]->name<<" ";
		cout << "ְ�����ű��:" << this->emp[i]->workadress << endl;


	}*/
	

	
}
void workManager::Show_Menu()
{
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "@@��ӭʹ��ְ������ϵͳ@@" << endl;
	cout << "@@@@@0.�˳��������@@@@" << endl;
	cout << "@@@@@1.����ְ����Ϣ@@@@" << endl;
	cout << "@@@@@2.��ʾְ����Ϣ@@@@" << endl;
	cout << "@@@@@3.ɾ����ְְ��@@@@" << endl;
	cout << "@@@@@4.�޸�ְ����Ϣ@@@@" << endl;
	cout << "@@@@@5.��ѯְ����Ϣ@@@@" << endl;
	cout << "@@@@@7.��������ĵ�@@@@" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << endl;
}
void workManager::Exit_System()
{

	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void workManager::add()
{
	cout << "����Ա������" << endl;
	int addnum;
	cin >> addnum;

	if (addnum > 0)
	{

		int newNum = this->emnumber + addnum;//�����¿ռ�Ĵ�С
		Worker** newspace = new Worker * [newNum];//�����¿ռ�


		if (this->emp != NULL)//��ԭ�ռ����ݷŵ��¿ռ���
		{
			for (int i = 0; i < this->emnumber; i++)
			{

				newspace[i] = this->emp[i];

			}
		}
			for (int i=0; i < addnum; i++)
			{

				int id;
				string name;
				int dselect;
				cout << "������ڣ�" << i + 1 << "��ְ����id�ǣ�"<<endl;
				cin >> id;
				cout << "������ڣ�" << i + 1 << "��ְ���������ǣ�" << endl;
				cin >>name;
				cout << "ѡ���Ա���ĸ�λ" << endl;
				cout << "1, ��ͨԱ��" << endl;
				cout << "2, ����" << endl;
				cout << "3���ϰ�" << endl;
				cin >> dselect;
				Worker* worker = NULL;
				switch (dselect)
				{case 1:
					worker = new Employee(id,name,1);
					break;
				case 2:
					worker = new manager(id, name, 2);
					break;
				case 3:
					worker = new boss(id, name, 3);
					break;
				default :
					break;
				}
				newspace[this->emnumber + i] = worker;


			}
			delete[]this->emp;//�ͷ�ԭ���Ŀռ�
			this->emp = newspace;//ָ���¿ռ�
			this->emnumber = newNum;//�����µĸ���
			this->fileempty = false;//����ְ����Ϊ��
			cout << "��ӳɹ�" << newNum << "��Ա��" << endl;//��ʾ��Ϣ
			this->save();

		
	}
	else
	{
		cout << "���ʧ����������" << endl;

	}

	system("pause");//�����������������һ��

	system("cls");
	


}
void workManager::save()
{
	ofstream ofs;
	ofs.open("filename", ios::out);
	for (int i = 0; i < this->emnumber; i++)
	{

		ofs << this->emp[i]->id << " "
			<< this->emp[i]->name << " "
			<< this->emp[i]->workadress << endl;

	}
	ofs.close();

}
int workManager::getnum()
{
	ifstream ifs;
	ifs.open("filename", ios::in);
	int id, idd;
	string name;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> idd)
	{

		num++;
	}
	ifs.close();
	return num;

}
void workManager::temp()
{

	ifstream ifs;
	ifs.open("filename", ios::in);
	int id, idd;
	string name;
	int index= 0;
	while (ifs >> id && ifs >> name && ifs >> idd)
	{

		Worker* woker = NULL;
		if (idd == 1)
		{
			woker = new Employee(id, name,idd );//Ա��

		}
		else if (idd == 2)
		{

			woker = new manager(id, name, idd);//����

		}
		else
		{

			woker = new boss(id, name, idd);//�ϰ�
		}


		this->emp[index] = woker;
		index++;
	}
	ifs.close();


}
workManager::~workManager()
{
	if (this->emp!=NULL)
	{
		delete[]this->emp;
		this->emp = NULL;


	}

}