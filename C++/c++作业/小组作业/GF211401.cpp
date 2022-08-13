//*********************************************************
//File name	 : 01
//Author  	 : he yang
//Date   	 : 2021/12/02
//Student ID   : 2021218148
//*********************************************************
/*目的：实现经典的狐狸抓兔子问题！！！*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

#define N 1000

//在有限次数中记录狐狸找到的洞的序号
void Unsafewhere(int a, int b, int * p) 
{
	int i = 0, flage = 0;
	while (flage <= b) {
		 *p = (a % 10);//当狐狸寻找间隔大于10时，取余数便可解决！！！
		i++;
		a += i;
		p++;
		flage++;
	}
	return;
}

//筛出安全的洞
void Findsavewhere(int* p, int b)
{
	int i = 0, flage = 0, *p2;
	p2 = p;//保持数组第一个位置

	cout << "安全的洞如下： " << endl;
	for (int i = 0; i < 10; i++) {
		p = p2;
		flage = 0;
		for (int j = 0; j < b; j++) {//j < b 不进行多余的循环
			if (i == *p) {
				flage++;
			}
			p++;
		}
		if (flage == 0) {
			cout << i << "  ";
		}
	}
}

//初始化数组,以开始找的第一个洞来初始化数组;
void baibai(int* p, int n, int a)
{
	for (int i = 0; i < n; i++) {
		p[i] = a;
	}
}

int main(void)
{
	int a, b;//a作开始找的第一个洞的序号 b作让狐狸找的次数
	
	cout << "请输入要开始寻找的洞的序号（在0~9之间）" << endl;
	cin >> a;
	cout << "输入您想让狐狸寻找的次数(1000以内）" << endl;
	cin >> b;

	if (b > 1000) {
		cout << "狐狸已经累死了！" << endl;
		return 0;
	}
	int c[N];

	baibai(c, b, a);//初始化数组函数
	Unsafewhere(a, b, c);//将不安全的洞都记录下来
	Findsavewhere(c, b);//通过遍历将安全的再筛选出来

	system("pause");

	return 0;
}