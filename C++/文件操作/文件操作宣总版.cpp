#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

//宣总打开文件三部曲 :书写成功
void text01(void)
{
	fstream ofs("love.txt", ios::out);
	ofs << "我爱你，不要害怕." << endl;
	ofs << "我会一直在你身旁." << endl;
	ofs << "我们可能再也不会见面." << endl;
	ofs << "但，别忘记我!" << endl;

	ofs.close();
}

//打开看看；
void text02(void)
{
	fstream ifs("love.txt", ios::in);

	if (!ifs) {
		cout << "wrong" << endl;
		exit(1);
	}

	char buf[80];
	while (ifs >> buf) {
		cout << buf << endl;
	}
}


int main(void)
{
	text01();
	text02();




	system("pause");
	return 0;
}