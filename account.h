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
	void save();//��������

	int getFLAG();//���ض������

	void showWelcome();//չʾ��ӭ��
	
	void setID();//�����˻�������˻������ھʹ���һ��
	
	void showMenu();//չʾ�˵�
	
	bool isPassword();//�ж������Ƿ���ȷ
	
	void seeBalance();//1-�����
	
	void addCash();//2-��Ǯ
	
	void takeCash();//3-ȡǮ
	
	void tranPassword();//4-������
	
	void transfer();//5-ת��
private:
	string ID;
	string name;
	string ID_card;
	string balance= original_balance;
	string password= original_password;
	string MAX_day_tCash="0";
	string FLAG = "1";//�˻�����
};