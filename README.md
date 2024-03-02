# project实验报告书——――ATM模拟程序的设计与实现

## 1.需求分析

ATM模拟程序的设计与实现的需求如下：

```
①显示欢迎词及提示信息；②用户插卡，ATM验证用户账号及密码有效性，输入错误3次即被锁卡；③余额查询：初始余额为10000元；④取款功能：每次取款余额为100的整数倍，有单笔和单日金额限制；⑤转账功能：可将本账户中的存款转入其他账户，转入账户账号需两次输入确认；⑥修改密码：密码为6位数字，新密码需要两次输入确认；⑦退卡。
①显示欢迎词及提示信息：直接使用C++中的标准输出流即可实现
②用户插卡：要求用户输入一个19位的数字，而long long虽然有19位，却不能涵盖所有的19位数字，因此用string实现并判断格式的准确性。与此同时输入密码，输入三次锁卡，并将账号等信息记录于文件中，方便继续使用。
③余额查询：返回余额并输出
④取款功能：取款额度为100的整数倍，即“number%100=0；”，要求设计一天取款的金额上限，这就要求将取款的金额累加保存在文件中，并在取款时加以限制。
⑤转账功能：需要用户输入两次账户以确认，同时和插卡时类似，需要判断格式，同时要求文件的查找功能。
⑥修改密码：修改密码时需要输入原密码，所改密码也要两次确认
⑦退卡
```

## 2.系统设计

```
//设计时，考虑到代码量比较大，可以利用分文件进行编写，同时，各功能用函数实现（除了非常简单的退卡），提供充分的注释，提高代码的可读性。设计账户（account）类，对账户进行初始化和保存操作时比较简便。具体的代码可以在附件中查看。同时请在VS2022的64位下运行该代码。
①显示欢迎词及提示信息
void showWelcome();//展示欢迎词
②用户插卡
void setID();//输入账户，如果账户不存在就创建一个
③余额查询
void seeBalance();//1-查余额
④取款功能
void takeCash();//3-取钱
⑤转账功能
void transfer();//5-转账
⑥修改密码
void tranPassword();//4-改密码
⑦退卡
cout << "欢迎下次使用" << endl;
system("pause");
return 0;
break;
```

## 3.系统实现

**1、显示欢迎词及提示信息**

同时进行异常处理（输入错误卡号）

```
********************************
***   欢迎使用ATM自助服务    ***
***     请输入卡号插卡！     ***
********************************
*** 若您输入一个不存在的卡号 ***
***      将为您自动开户      ***
*** 开户后，初始密码为050429 ***
********************************
123
你输入的卡号有误，请重新输入
1qw
你输入的卡号有误，请重新输入
```

**2、自动开户时提醒用户输入姓名和身份证，并进行异常处理：**

```
1231231231231231231
自动开户中...
请输入你的姓名
qqq
请输入你的身份证
123445
身份证输入格式错误，请重新输入
123123123123123123
开户成功!
请按任意键继续. . .
```

**3、判断密码的正确性：**

```
请输入您的现密码：
1234
密码错误！您还有2次输入机会，请重新开始！
234556
密码错误！您还有1次输入机会，请重新开始！
050429
请按任意键继续. . .
```

PS:初始密码为050429

**4、密码正确后进入菜单界面，提醒用户输入数字1~6，如果用户没有输入正确的数字，提醒用户重新输入：**

```
*******************************
***       登陆成功!         ***
***       1-余额查询        ***
***       2-存入现金        ***
***       3-提取现金        ***
***       4-现金转账        ***
***       5-修改密码        ***
***       6-退卡            ***
***  请以数字输入你的选择   ***
*******************************
132
您的输入有误，请重新输入
请按任意键继续. . .
```

**5、余额查询**

在此操作中，用户如果不想存了，也可以按0并回车返回主菜单

```
1
您的余额为： 10000
请按任意键继续. . .
```

**6、提取现金**

```
3
请输入你要取款的数额（100的倍数且不超过100000 ，单日取款不超过500000），或按0返回主菜单
您今日已取款： 0
224
你输入的金额错误，请重新输入
2000
取款成功！
请按任意键继续. . .
```

**7、转账**

如果用户输入账户错误，提醒输入的账户错误

同时不能转入自己的原账户

也实现了需要两次确认的功能

```
4
请输入你要转入的账户（或按0返回主菜单）:
1111111111111111111
请再次输入该账户以确认
1111111111111111111
该账户不存在，请重新输入
请输入你要转入的账户（或按0返回主菜单）:
1234567890987654321
请再次输入该账户以确认
1234567890987654321
该账户不存在，请重新输入
请输入你要转入的账户（或按0返回主菜单）:
1234567890123456789
请再次输入该账户以确认
1234567890123456789
请输入你要转入该账户的金额（或按0返回主菜单）
1234
转账成功！
请按任意键继续. . .
```

**8、修改密码**

修改密码时需要输入原密码确认身份，如果三次未输入成功也会对账户进行冻结

```
5
请输入您的现密码：
1
密码错误！您还有2次输入机会，请重新开始！
050429
请按任意键继续. . .
```

```
请输入修改后的密码
111111
请确认修改后的密码
111111
密码修改成功!
请按任意键继续. . .
```

**9、退卡**

```
6
欢迎下次使用
请按任意键继续. . .
```

**10、其他功能**

①在取款时如果输入一个大于余额的金额，会提醒用户余额不足，同时输入一个小于0的数也会提醒用户取款失败

```
3
请输入你要取款的数额（100的倍数且不超过100000 ，单日取款不超过500000），或按0返回主菜单
您今日已取款： 2000
12343455436
您的余额不足qwq，请重新输入!
-1234
你输入的金额错误，取款失败
请按任意键继续. . .
```

②冻结

输入错误三次密码即对账户进行冻结并记录（下次无法登录该账户并且无法向该账户转账）

```
4
请输入你要转入的账户（或按0返回主菜单）:
1231231231231231231
请再次输入该账户以确认
1231231231231231231
该账户已被冻结，转账失败
请按任意键继续. . .
```

```
1231231231231231231
您的账户已被冻结
```

③考虑代码的可维护性

\#define MAX_day_takeCASH 500000

\#define MAX_single_takeCASH 100000

\#define Number_of_account 19

\#define Number_of_ID_card 18

\#define MIN_multiple_CASH 100

\#define Number_of_password 6

\#define original_password "050429"

\#define original_balance "10000"

定义常量，方便后续进行修改和维护

## 4、参考文献

[1]刘瑞芳、肖波、许桂平、孙勇、徐慧民.《C++语言程序设计》[M].西安市太白路2号:西安电子科技大学出版社,2017.