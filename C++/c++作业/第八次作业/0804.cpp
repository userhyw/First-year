//*********************************************************
//File name	 : 0804
//Author  	 :he yang
//Date   	 : 01.11
//Student ID   :2021218148
//*********************************************************
#include <iostream>
#include <windows.h>

using namespace std;

#define N 5 //黄灯显示的时间，单位为秒！
typedef  unsigned  char BYTEPORT;

//创建一个结构体，包含6bit的变量a;
typedef struct ControlSystem
{
	//初始化，一开始是红灯、绿灯，后面考虑时间差！红绿黄 红绿黄：100 100;
	ControlSystem() { a = 34; }

	//使用一个字节八位中的六位！！！ 
	BYTEPORT a : 6;

}CSM;

void DelayTime(int iTime);

int main(void)
{
	//创建结构体变量
	CSM p;

	//创建红灯绿灯时间代表的数据！！！
	int NR, NG, SR, SG;//NR -> north red!

	//输入提示！
	cout << "请分别输入南北向的红灯时间和绿灯时间，以及东西向的红灯时间和绿灯时间" << endl;
	cout << "输入的时间必须满足：红灯 > （绿灯 + 黄灯） * 3；若不满足，则会带来危险！！！" << endl;
	cout << "黄灯默认五秒！红灯多出的时间会用于人行道时间！" << endl;

	//输入红灯和绿灯的时间
	cin >> NR >> NG >> SR >> SG;

	//根据 a 的值来控制转变红绿灯！！！
	while (1) {
		system("cls");
		if (p.a == 36) {
			cout << "南北：红！" << "   " << "东西：红！" << endl;
			DelayTime(NG + N + SG + N);
			if (NR > NG + N + SG + N + SG + N) {
				cout << "现在是人行道时间！" << endl;
				DelayTime(NR -( NG + N + SG + N + SG + N));
			}
			p.a = 20;//010 100
		}
		else if (p.a == 20) {
			cout << "南北：绿！" << "   " << "东西：红！" << endl;
			DelayTime(NG);
			p.a = 12;//001 100
		}
		else if (p.a == 12) {
			cout << "南北：黄！" << "   " << "东西：红！" << endl;
			DelayTime(N);
			p.a = 34;//100 010
		}
		else if (p.a == 34) {
			cout << "南北：红！" << "   " << "东西：绿！" << endl;
			DelayTime(SG);
			p.a = 33;//100 001
		}
		else if (p.a == 33) {
			cout << "南北：红！" << "   " << "东西：黄！" << endl;
			DelayTime(N);
			p.a = 36;//100 100
		}
	}

	system("pause");
	return 0;
}

//实现根据参数实现的延时函数
void DelayTime(int iTime)
{
	Sleep(1000 * iTime);
}
