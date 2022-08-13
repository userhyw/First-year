/*编写一个练习打字游戏，使用图形界面，练习打字
游戏规则为：
1. 游戏开始时，在游戏区域内随机出现若干个字母，并开始计时。
2. 用户根据出现的字母，通过键盘输入对应的字符。
3. 检测用户输入的字符，如果输入的字符在出现的字母中，则该字母消失，
并记为用户的得分。
4. 字母从游戏区域的上方不断往游戏区域的底端移动，直到用户输入了正
确的字符。当字母移动到游戏区域的底端后，字母消失。
5. 游戏时间到后，统计用户的正确率，给出该局游戏的得分。*/


#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <easyx.h> //X Y 图片插入等功能
#include <mmsystem.h>
#include <ctime>
#pragma comment(lib,"winmm.lib")  //音乐播放功能

#define N 1000 // 控制时间的量
#define MAX 20 //苹果数量的控制


//需要全局使用的变量
using namespace std;
int TIME, Flage, Score;
float Accuracy, Number1 = 0, Number2;
int Speed = 2;//初始化下落速度

//元素
//画面
//计算
//控制
//音乐

//素材
IMAGE backimg;//背景图片
IMAGE Apple[2];//苹果的两张图片

//添加一个类，来实现苹果的整体实现：
class AppleMany
{
public:
	//构造函数初始化字母
	AppleMany()
	{
		m_X = rand() % 14 * 50 + 100;//形成不等距;
		m_Y = rand() % 5 *( -50) - 50;//在上方形成高度差
		m_ch = rand() % 26 + 'A';
	}
	int m_X;
	int m_Y;
	char m_ch;
};

//超过边界，再次初始化！或者是击中后的初始化
void ManyApple(AppleMany &a)
{
	a.m_X = rand() % 14 * 50 + 100;//形成不等距;
	a.m_Y = rand() % 5 * (-50) - 50;//在上方形成高度差
	a.m_ch = rand() % 26 + 'A';
}

//坐标改变函数
void DateUpdate(AppleMany &a)
{
	a.m_Y += Speed;
}


//一把游戏结束后对所有数据再次初始化！！！
//因为图层关系分数无法在此再次初始化！！！
void BecomeStart()
{
	closegraph();
	Flage = 0;
	//Score = 0;

}


//游戏结束后输出分数！！！并将分数再次记为0！！！
void PrintfScore(AppleMany *howmany)
{
	if (Number1 != 0) Accuracy = Number2 / Number1;
	cout << "您消灭了：" << Number2 << "：个苹果！" << endl;
	cout << "您的得分为 ： " << Score << endl;
	cout << "您的正确率为 " << 100 * Accuracy << "%" << endl;
	cout << "干得漂亮！！！" << endl;
	system("pause");
	Score = 0;
	Number1 = 0;
	Number2 = 0;
	for (int i = 0; i < MAX; i++) {//之前写成N导致数组越界了！！！
		howmany[i].m_Y = rand() % 5 * (-50) - 50;
	}
}


//确认退出！！！
void SureExit()
{
	int Exit = 0;
	while (1) {
		cout << "输入 -1 确认退出！" << endl;
		cin >> Exit;
		system("pause");
		if (Exit == -1) {
			system("cls");
			return;
		}
	}


}


//画面 暂时罢工 start
void DrawPictures(AppleMany &a)
{
	//开始缓冲绘制;
	//BeginBatchDraw();
	//缓冲防闪->做成一帧一帧的在显示出来;

	//分先后好，不然会被遮挡！
	//putimage(0, 0, &backimg);//从窗口0.0坐标输出图片

	putimage(a.m_X - 18, a.m_Y - 18, &Apple[1], SRCPAINT);
	putimage(a.m_X - 18, a.m_Y - 18, &Apple[0], SRCAND);

	outtextxy(a.m_X, a.m_Y, a.m_ch);

	//EndBatchDraw();//结束缓冲绘制
}

//函数指针的知识！！！
//DWORD (WINAPI* PTHREAD_START_ROUTINE)(
//	LPVOID lpThreadParameter
//	);

//CreateThread //函数指针
DWORD WINAPI Boom(LPVOID lpThreadParameter)
{
	mciSendString(L"open 爆炸.mp3", 0, 0, 0);//卡顿，可以用多线程的方式去解决
	mciSendString(L"play 爆炸.mp3 wait", 0, 0, 0);
	mciSendString(L"close 爆炸.mp3", 0, 0, 0);
	return 0;
}


//控制 + 伴随音乐
void PlayGame(AppleMany *a)
{
	char key;			//接受按键的字符变量
	if (_kbhit())		 //是否有按键的动作
	{
		key = _getch();   //接受用户的按键
		if (key == '1') {
			//Speed = 2;
			
			//慢速度调试
			Speed = 1;

			//mci media contorl interface
			mciSendString(L"close IOU02.mp3", 0, 0, 0);
			mciSendString(L"close IOU03.mp3", 0, 0, 0);
			mciSendString(L"open IOU01.mp3", 0, 0, 0);
			mciSendString(L"play IOU01.mp3", 0, 0, 0);
		}
		else if (key == '2') {
			Speed = 4;
			mciSendString(L"close IOU01.mp3", 0, 0, 0);
			mciSendString(L"close IOU03.mp3", 0, 0, 0);
			mciSendString(L"open IOU02.mp3", 0, 0, 0);
			mciSendString(L"play IOU02.mp3", 0, 0, 0);
		}
		else if (key == '3') {
			Speed = 6;
			mciSendString(L"close IOU01.mp3", 0, 0, 0);
			mciSendString(L"close IOU02.mp3", 0, 0, 0);
			mciSendString(L"open IOU03.mp3", 0, 0, 0);
			mciSendString(L"play IOU03.mp3", 0, 0, 0);

		}
		else if ( key == ' ') {
			mciSendString(L"close IOU03.mp3", 0, 0, 0);
			mciSendString(L"close IOU02.mp3", 0, 0, 0);
			mciSendString(L"close IOU01.mp3", 0, 0, 0);

			//做一个空格暂停的操作！
			while (_getch() != ' ') {
				
			}
		}
		else {

			Number1++;

	
			//创建数组来记录！
			int SameApple[MAX] = { 0 };
			int j;
			j = 0;

			for (int i = 0; i < MAX; i++) {
				if (key == a[i].m_ch) {
					//CreateThread(0, 0, Boom, 0, 0, 0);
					//Number2++;
					//Score += 10;

					//解决出现多个相同字母时，哪一个先消失的问题
					//首先进行完这个循环，筛出相同字母的下标！
					SameApple[j] = i;
					j++;

					//ManyApple(a[i]);//初始化延后！
					//break;//目的：出现相同字母时，不会一起消失，方便计算得分！！！
				}
			}
			if (j != 0) {//确定出现正确的字母再进行判断！

				int LocaTion;
				LocaTion = SameApple[0];//数量少时，单独出现一个为基础情况

				for (int i = 0; i < j - 1; i++) {

					int iMax = SameApple[i];

					for (int k = i + 1; k < j; k++) {

						if (a[iMax].m_Y < a[SameApple[k]].m_Y)
						{
							iMax = SameApple[k];
							SameApple[k] = SameApple[i];
							SameApple[i] = iMax;

						}
					}
					break;//取冒泡排序的第一次就可以，只需要最大的值
				}

				CreateThread(0, 0, Boom, 0, 0, 0);
				Number2++;
				Score += 10;
				ManyApple(a[SameApple[0]]);
			}

		}
	}
}


//游戏时间控制
int ShowTime()
{
	Flage++;
	if (Flage < N) {
		return 0;
	}
	else {
		return 1;
	}

}


//入口界面信息介绍的函数
void imformation()
{
	cout << "*******  按下7进入游戏！-7退出游戏！但在这之前请您仔细阅读游戏说明： *******" << endl;
	cout << "*******  进入游戏后，按一下 1 表示第一难度，并有伴随音乐  *******" << endl;
	cout << "*******  进入游戏后，按一下 2 表示第二难度，并有伴随音乐  *******" << endl;
	cout << "*******  进入游戏后，按一下 3 表示第三难度，并有伴随音乐  *******" << endl;
	cout << "*******  进入游戏后，按下空格键为暂停，再按继续！  *******" << endl;
	cout << "*******  进入游戏后，按一下 4 游戏暂时暂停，音乐也会随之暂停  *******" << endl;
	cout << "*******  每次游戏时间为一分钟， 您将会看到您的得分与正确率！  *******" << endl;
	cout << "*******  温馨提示：您打错的字母也会被记录进最后的正确率中！  ******* " << endl;
}

//退出时关闭所有的音乐
void CloseMusci()
{
	mciSendString(L"close IOU03.mp3", 0, 0, 0);
	mciSendString(L"close IOU02.mp3", 0, 0, 0);
	mciSendString(L"close IOU01.mp3", 0, 0, 0);

}

//************************************************************主函数***************************************************
int main(void)
{
	int select;
	srand(time(NULL));//实现随机！！！而不是伪随机！！！
	class AppleMany HowMany[MAX];


	while (1) {
		imformation();
		cin >> select;
		system("cls");
		switch (select) {
		case 7:
			initgraph(800, 600);
			loadimage(&backimg, L"01.jpg", 800, 600);
			loadimage(&Apple[0], L"100.jpg", 50, 50);//两张苹果图片，手动抠图！！！
			loadimage(&Apple[1], L"99.jpg", 50, 50);
			setbkmode(0);//设置背景模式
		//	putimage(0, 0, &backimg);
			//输出背景图片
			while (1) {
				PlayGame(HowMany);
				BeginBatchDraw();
				putimage(0, 0, &backimg);
				for (int i = 0; i < MAX; i++){
					DrawPictures(HowMany[i]);
					DateUpdate(HowMany[i]);
					if (HowMany[i].m_Y > 600) {//让苹果掉下去接着在上来
						ManyApple(HowMany[i]);
						Number1++;				//计算正确率！！！
					}
				}
				Sleep(50);
				EndBatchDraw();
				
				int IOU = ShowTime();//控制游戏时间的标志
				if (IOU == 1) {
					//将之前的数据再次初始化！！！
					BecomeStart();


					//关闭音乐
					CloseMusci();


					//输出分数，之后将分数便为0;
					PrintfScore(HowMany);


					//确认退出
					SureExit();

					break;
				}
			}
			break;

		case -7:
			//按键安全退出！！！
			system("cls");
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;

		default:
			break;
		}


	}
	system("pause");
	return 0;
}

/*2022, 01, 03, 17:06完毕！！！*/