#include"account.h"

int main()
{
	
	account a;
	a.showWelcome();
	a.setID();
	if (a.getFLAG() == 0)
	{
		cout << "�����˻��ѱ�����" << endl;
		return 0;
	}
	a.isPassword();
	int select = 0;
	while (a.getFLAG())
	{
		a.showMenu();
		string s;
		cin >> s;
		select = atoi(s.c_str());
		switch (select)
		{
		case 1://��ѯ���
			a.seeBalance();
			break;
		case 2://�����ֽ�
			a.addCash();
			break;
		case 3://��ȡ�ֽ�
			a.takeCash();
			break;
		case 4://ת��
			a.transfer();
			break;
		case 5://�޸�����
			a.tranPassword();
			break;
		case 6://�˿�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "����������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
		
	}
	return 0;
}

