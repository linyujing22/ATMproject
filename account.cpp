#include "account.h"
#define MAX_day_takeCASH 500000
#define MAX_single_takeCASH 100000
#define Number_of_account 19
#define Number_of_ID_card 18
#define MIN_multiple_CASH 100
#define Number_of_password 6
//����
void account::save()
{
	string temp = ID + ".txt";
	ofstream ofs(temp);
	ofs << "�˺ţ�" << ID << endl;
	ofs << "������" << name << endl;
	ofs << "���֤��" << ID_card << endl;
	ofs << "���룺" << password << endl;
	ofs << "��" << balance << endl;
	ofs << "����ȡ���" << MAX_day_tCash << endl;
	ofs << "�˺Ŷ��������" << FLAG << endl;
	ofs.close();
}

//���ض������
int account::getFLAG()
{
	return atoi(FLAG.c_str());
}

//չʾ��ӭ��
void account::showWelcome()
{
	cout << "********************************" << endl;
	cout << "***   " << "��ӭʹ��ATM��������" << "    ***" << endl;
	cout << "***     " << "�����뿨�Ų忨��" << "     ***" << endl;
	cout << "********************************" << endl;
	cout << "*** ��������һ�������ڵĿ��� ***" << endl;
	cout << "***      ��Ϊ���Զ�����      ***" << endl;
	cout << "*** �����󣬳�ʼ����Ϊ050429 ***" << endl;
	cout << "********************************" << endl;
}

//�����˺�
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
					flag = true;//����˻����󣬷���true���½���ѭ�����뿨��
				}
			}
		}
		if (flag)
		{
			cout << "������Ŀ�����������������" << endl;
		}
	}

	ID = number;
	ifstream ifs;
	ifs.open(ID + ".txt", ios::in);
	if (!ifs.is_open())
	{
		//��ʧ�ܣ��������˻�������
		cout << "�Զ�������..." << endl;
		cout << "�������������" << endl;
		string name;
		cin >> name;
		this->name = name;
		cout << "������������֤" << endl;
		string ID_card;
		while (true)
		{
			cin >> ID_card;
			if (ID_card.size() == Number_of_ID_card)
			{
				break;
			}
			cout << "���֤�����ʽ��������������" << endl;
		}


		this->ID_card = ID_card;
		cout << "�����ɹ�!" << endl;
		system("pause");
		system("cls");
		save();//
	}
	else
	{
		//���ļ��ɹ�����ȡ�ļ���Ϣ
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

//չʾ�˵�
void account::showMenu()
{
	cout << "*******************************" << endl;
	cout << "***       ��½�ɹ�!         ***" << endl;
	cout << "***       1-����ѯ        ***" << endl;
	cout << "***       2-�����ֽ�        ***" << endl;
	cout << "***       3-��ȡ�ֽ�        ***" << endl;
	cout << "***       4-�ֽ�ת��        ***" << endl;
	cout << "***       5-�޸�����        ***" << endl;
	cout << "***       6-�˿�            ***" << endl;
	cout << "***  ���������������ѡ��   ***" << endl;
	cout << "*******************************" << endl;
}

//�ж�����
bool account::isPassword()
{
	cout << "���������������룺 " << endl;
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
		cout << "�������������2��������ᣬ�����¿�ʼ��" << endl;
		cin >> n;
		if (n == p)
		{
			system("pause");
			system("cls");
			return true;
		}
		else
		{
			cout << "�������������1��������ᣬ�����¿�ʼ��" << endl;
			cin >> n;
			if (n == p)
			{
				system("pause");
				system("cls");
				return true;
			}
			else
			{
				cout << "��������������Σ������˺��Ѷ���" << endl;
				FLAG = "0";//���ʻ����ж���
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

//1-��ѯ���
void account::seeBalance()
{
	cout << "�������Ϊ�� " << balance << endl;
	system("pause");
	system("cls");
}

//2-��Ǯ
void account::addCash()
{
	cout << "��������Ҫ���������,��0�������˵�" << endl;
	long long n;
	long long b = atoi(balance.c_str());
	bool flag = true;
	while (flag)
	{
		cin >> n;
		if (n == 0)
		{
			cout << "���سɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (n < 0)
		{
			cout << "������Ϊ�������ʧ��" << endl;
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
		cout << "������Ľ���������������" << endl;
	}
}

//3-ȡǮ
void account::takeCash()
{
	long long t = atoi(MAX_day_tCash.c_str());
	cout << "��������Ҫȡ������"
		<<MIN_multiple_CASH<<"�ı����Ҳ�����"
		<< MAX_single_takeCASH<<" ������ȡ�����"
		<<MAX_day_takeCASH<<"������0�������˵�" << endl;
	cout << "��������ȡ� " << t << endl;
	long long n;
	long long b = atoi(balance.c_str());
	bool flag = true;
	while (flag)
	{
		cin >> n;
		if (n < 0)
		{
			cout << "������Ľ�����ȡ��ʧ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (n == 0)
		{
			cout << "���سɹ�" << endl;
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
				cout << "ȡ��ɹ���" << endl;
				save();//����
				system("pause");
				system("cls");
				return;
			}
			cout << "������Ľ���������������" << endl;
		}
		else
		{
			cout << "��������qwq������������!" << endl;
		}
	}
}

//4-������
void account::tranPassword()
{
	if (isPassword())
	{
		string s1, s2;
		while (true)
		{
			while (true)
			{
				cout << "�������޸ĺ������ " << endl;
				cin >> s1;
				if (s1.size() == Number_of_password)
				{
					break;
				}
				cout << "�����ʽ����" << endl;
			}
			cout << "��ȷ���޸ĺ������ " << endl;
			cin >> s2;
			if (s1 == s2)
			{
				password = s1;
				cout << "�����޸ĳɹ�!" << endl;
				save();
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "�����޸�ʧ��" << endl;
			}
		}


	}

}

//5-ת��
void account::transfer()
{
	string number1,number2;
	bool flag1 = true;
	bool flag2 = true;
	
	
	while (true)
	{
		flag1 = true;
		flag2 = true;
		cout << "��������Ҫת����˻�����0�������˵���: " << endl;
		//�жϵ�һ�������˻���ʽ����ȷ��
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
				cout << "������Ŀ�����������������" << endl;
			}
		}
		cout << "���ٴ�������˻���ȷ��" << endl;
		//�жϵڶ��������˻���ʽ����ȷ��
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
				cout << "������Ŀ�����������������" << endl;
			}
		}
		if (number1 == number2)
		{
			ifstream ifs;
			ifs.open(number1 + ".txt", ios::in);
			if (!ifs.is_open())
			{
				cout << "���˻������ڣ�����������" << endl;
				continue;
			}
			else if (number1 == ID)
			{
				cout << "����������Լ���ԭ�˻�������������" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		cout << "�������벻һ�£�����������" << endl;
	}
	//����������ȷ���˻��󣬽���ת�˲���
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
		//�޷��Ա�������˻�����ת��
		cout << "���˻��ѱ����ᣬת��ʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "��������Ҫת����˻��Ľ���0�������˵���" << endl;

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			cout << "���سɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if (n < 0)
		{
			cout << "ת�˽��Ϊ����ת��ʧ�ܣ�����������" << endl;
		}
		else if (n > _balance)
		{
			cout << "���㣬���������루��0�������˵���" << endl;
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
			ofs << "��" << s_balance << endl;
			ofs << str[5] << endl;
			ofs << str[6] << endl;
			ofs.close();
			save();

			cout << "ת�˳ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}


	
}
