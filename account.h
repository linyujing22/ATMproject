#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define original_password "050429"
#define original_balance "10000"
class account
{
public:
	void save();//保存数据

	int getFLAG();//返回冻结情况

	void showWelcome();//展示欢迎词
	
	void setID();//输入账户，如果账户不存在就创建一个
	
	void showMenu();//展示菜单
	
	bool isPassword();//判断密码是否正确
	
	void seeBalance();//1-查余额
	
	void addCash();//2-存钱
	
	void takeCash();//3-取钱
	
	void tranPassword();//4-改密码
	
	void transfer();//5-转账
private:
	string ID;
	string name;
	string ID_card;
	string balance= original_balance;
	string password= original_password;
	string MAX_day_tCash="0";
	string FLAG = "1";//账户冻结
};