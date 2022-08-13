//*********************************************************
//File name	 : 0802
//Author  	 : he yang
//Date   	 : 2021/12/3
//Student ID   : 2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(void)
{
	int m, n;
	float** ARR;
	cout << "请输入m, n的值" << endl;
	cin >> m >> n;

	//进行动态内存分配，其连接方式与指针十分相似；
	ARR = new float* [m];
	for (int i = 0; i < m; i++) {
		ARR[i] = new float[n];
	}

	//对抽象的二维数组进行随机赋值
	//rand函数的随机为伪随机，需要改变它的种子;
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			ARR[i][j] = (float)(rand()) / 10;
		}
	}

	//通过遍历找到最小值，并输出及其行列下表 (double)(rand)
	float iMin = ARR[0][0];
	int k = 0, L = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (ARR[i][j] < iMin) {
				iMin = ARR[i][j];
				k = i;
				L = j;
			}
		}
	}

	cout << "最小值为： " << iMin << endl;
	cout << "最小值的下标为： " << k << " " <<  L << endl;

	//new 多少， delete 多少
	for (int i = 0; i < m; i++) {
		delete[] ARR[i];
	}
	delete[]ARR;

	system("pause");
	return 0;

}