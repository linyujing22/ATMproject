#include "account.h"
#define MAX_day_takeCASH 500000
#define MAX_single_takeCASH 100000
#define Number_of_account 19
#define Number_of_ID_card 18
#define MIN_multiple_CASH 100
#define Number_of_password 6
//保存
void account::save()
{
	string temp = ID + ".txt";
	ofstream ofs(temp);
	ofs << "账号：" << ID << endl;
	ofs << "姓名：" << name << endl;
	ofs << "身份证：" << ID_card << endl;
	ofs << "密码：" << password << endl;
	ofs << "余额：" << balance << endl;
	ofs << "单日取款金额：" << MAX_day_tCash << endl;
	ofs << "账号冻结情况：" << FLAG << endl;
	ofs.close();
}

//返回冻结情况
int account::getFLAG()
{
	return atoi(FLAG.c_str());
}

//展示欢迎词
void account::showWelcome()
{
	cout << "********************************" << endl;
	cout << "***   " << "欢迎使用ATM自助服务" << "    ***" << endl;
	cout << "***     " << "请输入卡号插卡！" << "     ***" << endl;
	cout << "********************************" << endl;
	cout << "*** 若您输入一个不存在的卡号 ***" << endl;
	cout << "***      将为您自动开户      ***" << endl;
	cout << "*** 开户后，初始密码为050429 ***" << endl;
	cout << "********************************" << endl;
}

//输入账号
void account::setID()
{

	string number;
	bool flag = true;

	while (flag)
	{
		cin >> number;
		if (number.size() == Number_of_account)
		{
			flag = false;
			for (int i = 0; i < number.size(); i++)
			{
				
				if (number[i] < '0' || number[i] > '9')
				{
					flag = true;//如果账户有误，返回true重新进入循环输入卡号
				}
			}
		}
		if (flag)
		{
			cout << "你输入的卡号有误，请重新输入" << endl;
		}
	}

	ID = number;
	ifstream ifs;
	ifs.open(ID + ".txt", ios::in);
	if (!ifs.is_open())
	{
		//打开失败，创建新账户并保存
		cout << "自动开户中..." << endl;
		cout << "请输入你的姓名" << endl;
		string name;
		cin >> name;
		this->name = name;
		cout << "请输入你的身份证" << endl;
		string ID_card;
		while (true)
		{
			cin >> ID_card;
			if (ID_card.size() == Number_of_ID_card)
			{
				break;
			}
			cout << "身份证输入格式错误，请重新输入" << endl;
		}


		this->ID_card = ID_card;
		cout << "开户成功!" << endl;
		system("pause");
		system("cls");
		save();//
	}
	else
	{
		//打开文件成功，读取文件信息
		string str[7];
		for (int i = 0; i < 8; i++)
		{
			ifs >> str[i];
		}
		ID = str[0].substr(6);
		name = str[1].substr(6);
		ID_card = str[2].substr(8);
		password = str[3].substr(6);
		balance = str[4].substr(6);
		MAX_day_tCash = str[5].substr(14);
		FLAG = str[6].substr(14,1);
	}
	ifs.close();
}

//展示菜单
void account::showMenu()
{
	cout << "*******************************" << endl;
	cout << "***       登陆成功!         ***" << endl;
	cout << "***       1-余额查询        ***" << endl;
	cout << "***       2-存入现金        ***" << endl;
	cout << "***       3-提取现金        ***" << endl;
	cout << "***       4-现金转账        ***" << endl;
	cout << "***       5-修改密码        ***" << endl;
	cout << "***       6-退卡            ***" << endl;
	cout << "***  请以数字输入你的选择   ***" << endl;
	cout << "*******************************" << endl;
}

//判断密码
bool account::isPassword()
{
	cout << "请输入您的现密码： " << endl;
	string n;
	cin >> n;
	string p = password;
	if (n == p)
	{
		system("pause");
		system("cls");
		return true;
	}
	else
	{
		cout << "密码错误！您还有2次输入机会，请重新开始！" << endl;
		cin >> n;
		if (n == p)
		{
			system("pause");
			system("cls");
			return true;
		}
		else
		{
			cout << "密码错误！您还有1次输入机会，请重新开始！" << endl;
			cin >> n;
			if (n == p)
			{
				system("pause");
				system("cls");
				return true;
			}
			else
			{
				cout << "输入密码错误三次，您的账号已冻结" << endl;
				FLAG = "0";//对帐户进行冻结
				save();
				system("pause");
				system("cls");
				return false;

			}
		}
	}
	system("pause");
	system("cls");
}

//1-查询余额
void account::seeBalance()
{
	cout << "您的余额为： " << balance << endl;
	system("pause");
	system("cls");
}

//2-存钱
void account::addCash()
{
	cout << "请输入你要存入的数额,或按0返回主菜单" << endl;
	long long n;
	long long b = atoi(balance.c_str());
	bool flag = true;
	while (flag)
	{
		cin >> n;
		if (n == 0)
		{
			cout << "返回成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (n < 0)
		{
			cout << "存入金额为负，存款失败" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (true)
		{
			b += n;
			balance =to_string(b);
			save();
			system("pause");
			system("cls");
			return;
		}
		cout << "你输入的金额错误，请重新输入" << endl;
	}
}

//3-取钱
void account::takeCash()
{
	long long t = atoi(MAX_day_tCash.c_str());
	cout << "请输入你要取款的数额（"
		<<MIN_multiple_CASH<<"的倍数且不超过"
		<< MAX_single_takeCASH<<" ，单日取款不超过"
		<<MAX_day_takeCASH<<"），或按0返回主菜单" << endl;
	cout << "您今日已取款： " << t << endl;
	long long n;
	long long b = atoi(balance.c_str());
	bool flag = true;
	while (flag)
	{
		cin >> n;
		if (n < 0)
		{
			cout << "你输入的金额错误，取款失败" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (n == 0)
		{
			cout << "返回成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (b >= n)
		{
			if (n % 100 == 0 && n <= MAX_single_takeCASH && t <= MAX_day_takeCASH)
			{
				b -= n;
				t += n;
				balance = to_string(b);
				MAX_day_tCash = to_string(t);
				cout << "取款成功！" << endl;
				save();//保存
				system("pause");
				system("cls");
				return;
			}
			cout << "你输入的金额错误，请重新输入" << endl;
		}
		else
		{
			cout << "您的余额不足qwq，请重新输入!" << endl;
		}
	}
}

//4-改密码
void account::tranPassword()
{
	if (isPassword())
	{
		string s1, s2;
		while (true)
		{
			while (true)
			{
				cout << "请输入修改后的密码 " << endl;
				cin >> s1;
				if (s1.size() == Number_of_password)
				{
					break;
				}
				cout << "密码格式错误" << endl;
			}
			cout << "请确认修改后的密码 " << endl;
			cin >> s2;
			if (s1 == s2)
			{
				password = s1;
				cout << "密码修改成功!" << endl;
				save();
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "密码修改失败" << endl;
			}
		}


	}

}

//5-转账
void account::transfer()
{
	string number1,number2;
	bool flag1 = true;
	bool flag2 = true;
	
	
	while (true)
	{
		flag1 = true;
		flag2 = true;
		cout << "请输入你要转入的账户（或按0返回主菜单）: " << endl;
		//判断第一次输入账户格式的正确性
		while (flag1)
		{
			cin >> number1;
			if (number1 == "0")
			{
				system("pause");
				system("cls");
				return;
			}
			if (number1.size() == Number_of_account)
			{
				flag1 = false;
				for (int i = 0; i < number1.size(); i++)
				{

					if (number1[i] < '0' || number1[i] > '9')
					{
						flag1 = true;
					}
				}
			}
			if (flag1)
			{
				cout << "你输入的卡号有误，请重新输入" << endl;
			}
		}
		cout << "请再次输入该账户以确认" << endl;
		//判断第二次输入账户格式的正确性
		while (flag2)
		{
			cin >> number2;
			if (number2.size() == Number_of_account)
			{
				flag2 = false;
				for (int i = 0; i < number2.size(); i++)
				{

					if (number2[i] < '0' || number2[i] > '9')
					{
						flag2 = true;
					}
				}
			}
			if (flag2)
			{
				cout << "你输入的卡号有误，请重新输入" << endl;
			}
		}
		if (number1 == number2)
		{
			ifstream ifs;
			ifs.open(number1 + ".txt", ios::in);
			if (!ifs.is_open())
			{
				cout << "该账户不存在，请重新输入" << endl;
				continue;
			}
			else if (number1 == ID)
			{
				cout << "您输入的是自己的原账户，请重新输入" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		cout << "两次输入不一致，请重新输入" << endl;
	}
	//两次输入正确的账户后，进行转账操作
	ifstream ifs;
	ifs.open(number1 + ".txt", ios::in);
	string str[7];
	for (int i = 0; i < 7; i++)
	{
		ifs >> str[i];
	}
	ifs.close();
	long long t_balance = atoi(str[4].substr(6).c_str());
	long long _balance = atoi(balance.c_str());
	int flag = atoi(str[6].substr(14, 1).c_str());

	if (flag == 0)
	{
		//无法对被冻结的账户进行转账
		cout << "该账户已被冻结，转账失败" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请输入你要转入该账户的金额（或按0返回主菜单）" << endl;

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			cout << "返回成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if (n < 0)
		{
			cout << "转账金额为负，转账失败，请重新输入" << endl;
		}
		else if (n > _balance)
		{
			cout << "余额不足，请重新输入（或按0返回主菜单）" << endl;
		}
		else
		{
			
			_balance -= n;
			t_balance += n;
			balance = to_string(_balance);
			string s_balance = to_string(t_balance);

			string temp = number1 + ".txt";
			ofstream ofs(temp);
			ofs << str[0] << endl;
			ofs << str[1] << endl;
			ofs << str[2] << endl;
			ofs << str[3] << endl;
			ofs << "余额：" << s_balance << endl;
			ofs << str[5] << endl;
			ofs << str[6] << endl;
			ofs.close();
			save();

			cout << "转账成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}


	
}
