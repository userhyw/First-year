#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

using namespace std;

//写一个文件
void test01()
{
	//1.include 头文件 fstream

	//2.创建对象
	ofstream ofs;

	//3.指定打开方式
	ofs.open("test.txt", ios::out);

	//4.写内容
	ofs << "爱而不得，人生遗憾！" << endl;
	ofs << "错过才是最遗憾的！" << endl;
	ofs << "你觉得呢？" << endl;

	//5.关闭文件
	ofs.close();
}


int main(void)
{
	test01();



	system("pause");
	return 0;
}

//ofstream out put fstream
//ifstream input fream
//fstream 既可以读又可以写；files;