#include <iostream>

using namespace std;

//函数类型不同，个数不同，顺序不同;
//函数重载，提高复用性！！！

//1.在同一个作用域下
void func(int)
{
	cout << "func 的调用" << endl;

}

void func()
{
	cout << "func 的调用1" << endl;

}

int main(void)
{
	func(5);


	system("pause");
	return 0;
}