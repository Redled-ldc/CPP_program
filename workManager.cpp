#include "workManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <string>
workManager::workManager()
{//1，文件不存在
	ifstream ifs;
	ifs.open("filename", ios::in);//读文件
	if (!ifs.is_open())
	{

		//cout << "文件不存在" << endl;
		//初始化人数
		this->emnumber = 0;
		//初始化数组指针
		this->emp = NULL;
		//初始化文件是否为空
		this->fileempty = true;
		ifs.close();
		return;
		

	}
	//2,文件存在但没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->emnumber = 0;
		//初始化数组指针
		this->emp = NULL;
		//初始化文件是否为空
		this->fileempty = true;
		ifs.close();
		return;

	}
	//3，文件存在，有数据
	
	int num = this->getnum();
	//cout << "有" << num << "个员工" << endl;
	this->emnumber = num;//更新员工人数
	this->emp = new Worker * [this->emnumber];//根据职工数创建职工数值指针
	this->temp();//初始化职工将文件中的数据存入数组中
	/*for (int i=0; i < this->emnumber; i++)
	{
		cout << "职工编号:" << this->emp[i]->id<<" ";
		cout << "职工姓名:" << this->emp[i]->name<<" ";
		cout << "职工部门编号:" << this->emp[i]->workadress << endl;


	}*/
	

	
}
void workManager::Show_Menu()
{
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "@@欢迎使用职工管理系统@@" << endl;
	cout << "@@@@@0.退出管理程序@@@@" << endl;
	cout << "@@@@@1.增加职工信息@@@@" << endl;
	cout << "@@@@@2.显示职工信息@@@@" << endl;
	cout << "@@@@@3.删除离职职工@@@@" << endl;
	cout << "@@@@@4.修改职工信息@@@@" << endl;
	cout << "@@@@@5.查询职工信息@@@@" << endl;
	cout << "@@@@@7.清空所有文档@@@@" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << endl;
}
void workManager::Exit_System()
{

	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void workManager::add()
{
	cout << "增加员工数量" << endl;
	int addnum;
	cin >> addnum;

	if (addnum > 0)
	{

		int newNum = this->emnumber + addnum;//计算新空间的大小
		Worker** newspace = new Worker * [newNum];//开辟新空间


		if (this->emp != NULL)//将原空间内容放到新空间下
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
				cout << "请输入第：" << i + 1 << "个职工的id是："<<endl;
				cin >> id;
				cout << "请输入第：" << i + 1 << "个职工的姓名是：" << endl;
				cin >>name;
				cout << "选择该员工的岗位" << endl;
				cout << "1, 普通员工" << endl;
				cout << "2, 经理" << endl;
				cout << "3，老板" << endl;
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
			delete[]this->emp;//释放原来的空间
			this->emp = newspace;//指向新空间
			this->emnumber = newNum;//更新新的个数
			this->fileempty = false;//更新职工不为空
			cout << "添加成功" << newNum << "个员工" << endl;//提示信息
			this->save();

		
	}
	else
	{
		cout << "添加失败输入有误！" << endl;

	}

	system("pause");//按任意键清屏返回上一级

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
			woker = new Employee(id, name,idd );//员工

		}
		else if (idd == 2)
		{

			woker = new manager(id, name, idd);//经理

		}
		else
		{

			woker = new boss(id, name, idd);//老板
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