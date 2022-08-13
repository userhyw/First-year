//*********************************************************
//File name	 : 0806.2
//Author  	 :he yang
//Date   	 : 01.11
//Student ID   :2021218148
//*********************************************************
#include <iostream>
#include <fstream>

using namespace std;

#define NEWLINE cout << endl

int main(void)
{
	fstream fs("Cyb.dat", ios::in | ios::binary);//二进制文件打开的方式来读取！
	char ch2, Key1;
	int ch3;//EOF表示整形的-1，用int类型来接收，读到末尾！

	cout << "请输入您加密时的密钥：" << endl;
	cin >> Key1;
	NEWLINE;
	
	if (!fs.is_open()) {
		cout << "文件打开失败，解密失败！" << endl;
	}


	while ((ch3 = fs.get()) != EOF) {//逐个符号读取，直到读到文件末尾；

		//移动位数不能超过八！！！
		//ch2 = (char)(ch3 >>( Key1 - '0') | ch3 << 8 - (Key1 - '0'));//方法二
		ch2 = (ch3 ^ Key1);//方法一
		cout << ch2;
	}
	NEWLINE;

	cout << "解密文件如上！" << endl;
	NEWLINE;

	system("pause");
	return 0;
}
