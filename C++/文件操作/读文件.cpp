#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

#include <fstream>
//读文件
void test02()
{
	//1.头文件

	//2.创建对象
	ifstream ifs;

	//3.指定打开方式，并判断是否成功打开
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "打开失败！你个锤子在储存文件夹里没有这个东西！" << endl;
		return;
	}

	//4.开始读数据四种方法
	//第一种
	/*char buf[1024] = { 0 };
	while (ifs >> buf) {
		cout << buf << endl;
	}*/

	//第二种打开方式
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf))){
	//	cout << buf << endl;
	//}

	//第三种打开方式
	//string buf;
	//while (getline(ifs, buf)) {
	//	cout << buf << endl;
	//}

	//第四种方法//end of file文件尾部的意思
	//是一个一个的读的，效率很低，不推荐
	char c;
	while ((c = ifs.get()) != EOF) {
		cout << c;
	}
		
	//5.关闭文件
	ifs.close();

}

int main(void)
{

	test02();



	system("pause");
	return 0;
}