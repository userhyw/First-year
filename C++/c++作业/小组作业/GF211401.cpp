//*********************************************************
//File name	 : 01
//Author  	 : he yang
//Date   	 : 2021/12/02
//Student ID   : 2021218148
//*********************************************************
/*Ŀ�ģ�ʵ�־���ĺ���ץ�������⣡����*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

#define N 1000

//�����޴����м�¼�����ҵ��Ķ������
void Unsafewhere(int a, int b, int * p) 
{
	int i = 0, flage = 0;
	while (flage <= b) {
		 *p = (a % 10);//������Ѱ�Ҽ������10ʱ��ȡ������ɽ��������
		i++;
		a += i;
		p++;
		flage++;
	}
	return;
}

//ɸ����ȫ�Ķ�
void Findsavewhere(int* p, int b)
{
	int i = 0, flage = 0, *p2;
	p2 = p;//���������һ��λ��

	cout << "��ȫ�Ķ����£� " << endl;
	for (int i = 0; i < 10; i++) {
		p = p2;
		flage = 0;
		for (int j = 0; j < b; j++) {//j < b �����ж����ѭ��
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

//��ʼ������,�Կ�ʼ�ҵĵ�һ��������ʼ������;
void baibai(int* p, int n, int a)
{
	for (int i = 0; i < n; i++) {
		p[i] = a;
	}
}

int main(void)
{
	int a, b;//a����ʼ�ҵĵ�һ��������� b���ú����ҵĴ���
	
	cout << "������Ҫ��ʼѰ�ҵĶ�����ţ���0~9֮�䣩" << endl;
	cin >> a;
	cout << "���������ú���Ѱ�ҵĴ���(1000���ڣ�" << endl;
	cin >> b;

	if (b > 1000) {
		cout << "�����Ѿ������ˣ�" << endl;
		return 0;
	}
	int c[N];

	baibai(c, b, a);//��ʼ�����麯��
	Unsafewhere(a, b, c);//������ȫ�Ķ�����¼����
	Findsavewhere(c, b);//ͨ����������ȫ����ɸѡ����

	system("pause");

	return 0;
}