
#include "workManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{

	/*Worker* woker = NULL;//���Դ���
	woker = new Employee(1, "����", 1);
	woker->idShow();
	woker->getwadress();
	delete woker;

	
	woker = new manager(2, "����", 2);
	woker->idShow();
	woker->getwadress();
	delete woker;

	
	woker = new boss(3, "����", 3);
	woker->idShow();
	woker->getwadress();
	delete woker;*/
	int choice = 0;
	workManager wm;
	while (true)
	{
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;


		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.Exit_System();

			break;
		case 1:
			wm.add();

			break;
		case 2:


			break;
		case 3:


			break;
		case 4:


			break;
		case 5:


			break;
		case 6:


			break;
		case 7:


			break;
		default:
			system("cls");
			break;

		}
	} 

	system("pause");

	return 0;
}