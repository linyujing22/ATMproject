#include"account.h"

int main()
{
	
	account a;
	a.showWelcome();
	a.setID();
	if (a.getFLAG() == 0)
	{
		cout << "您的账户已被冻结" << endl;
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
		case 1://查询余额
			a.seeBalance();
			break;
		case 2://存入现金
			a.addCash();
			break;
		case 3://提取现金
			a.takeCash();
			break;
		case 4://转账
			a.transfer();
			break;
		case 5://修改密码
			a.tranPassword();
			break;
		case 6://退卡
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "您的输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
		
	}
	return 0;
}

