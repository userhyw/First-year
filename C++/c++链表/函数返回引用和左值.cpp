#include <iostream>

using namespace std;
int &text01()
{
	static int a = 10;
	return a;
}

//引用的本质就是一个指针常量，指向的方向无法修改;
// 内部给我们写的一个常量指针;
//指针常量不可更改，这也说明了为什么我们创建引用也不可以更改;
// int * const c = &a;
int main(void)
{
	//静态变量的引用是可以通过函数安全返回的
	//在常常用到一个数据且要改变时，很方便。
	int &c = text01();
	cout << c << endl;
	cout << c << endl;

	//函数的左值
	text01() = 1000;
	cout << c << endl;
	cout << c << endl;
	system("pause");
	return 0;
}