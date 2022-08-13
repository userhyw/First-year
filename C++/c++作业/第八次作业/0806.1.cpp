//*********************************************************
//File name	 : 0806.1
//Author  	 :he yang
//Date   	 : 01.11
//Student ID   :2021218148
//*********************************************************
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	fstream fs("hamlet.txt", ios::in | ios::binary);
	fstream fs2("Cyb.dat", ios::out | ios::binary);
	char ch, ch2, Key;

	if (!fs.is_open()) {
		cout << "文件打开失败, 加密失败！" << endl;
		return 1;
	}

	cout << "请输入您的密钥：" << endl;
	cin >> Key;

	
	while ((ch = fs.get()) != EOF) {
/*		ch2 = (ch << (Key - '0')%8 | ch >> 8 - (Key - '0')%8);*///左移大于8位取余
		ch2 = (ch ^ Key);
		fs2.write(&ch2, sizeof(ch2));
	}

	cout << "加密成功！" << endl;
	cout << "加密文件已存入Cyb.dat中！" << endl;

	fs.close();
	fs2.close();

	system("pause");
	return 0;
}
