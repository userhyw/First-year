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
	cout << "������m, n��ֵ" << endl;
	cin >> m >> n;

	//���ж�̬�ڴ���䣬�����ӷ�ʽ��ָ��ʮ�����ƣ�
	ARR = new float* [m];
	for (int i = 0; i < m; i++) {
		ARR[i] = new float[n];
	}

	//�Գ���Ķ�ά������������ֵ
	//rand���������Ϊα�������Ҫ�ı���������;
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			ARR[i][j] = (float)(rand()) / 10;
		}
	}

	//ͨ�������ҵ���Сֵ����������������±� (double)(rand)
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

	cout << "��СֵΪ�� " << iMin << endl;
	cout << "��Сֵ���±�Ϊ�� " << k << " " <<  L << endl;

	//new ���٣� delete ����
	for (int i = 0; i < m; i++) {
		delete[] ARR[i];
	}
	delete[]ARR;

	system("pause");
	return 0;

}