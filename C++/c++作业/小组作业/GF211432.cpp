//*********************************************************
//File name	 : 32
//Author  	 : he yang
//Date   	 : 2021/12/02
//Student ID   : 2021218148
//*********************************************************

/*Ŀ�ģ���ɶ����ַ����е��Ӵ����ң�����¼λ�������*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;


void FindPrintf(char* abs, char* abs2, int Lenth);
int Lenthstr2(char* str2);


int main(void)
{
	//str�������ַ�����str2�����Ӵ���lenth��¼�Ӵ��ĳ���
	char str[80], str2[20];
	int lenth = 0;
	cout << "������һ���ַ���" << endl;
	cin.getline(str, 80);

	cout << "��������Ҫ���ҵ��ִ���" << endl;
	cin.getline(str2, 20);

	lenth = Lenthstr2(str2);
	FindPrintf(str, str2, lenth);
	system("pause");
	return 0;
}
void FindPrintf(char* abs, char * Head, int Lenth)
{
	int WhereAreYou = 0;int i = 0, j = 0;
	char* abs2 = NULL;
	abs2 = Head;


	//ע�ͣ�abs++�ĵط� iҲ++��Ҫ�������ַ�������λ��iͬ��
	while (*abs) {

		if (*abs == *abs2) {
			j = 0;//ÿһ�ν��������ѭ����j��ֵ��Ϊ0����ֹ�����Ӵ��е�Ԫ��ʹj�ۼƣ�
			
			while (*abs2) {
				
				if (*abs == *abs2) {
					j++;
					//cout << j << endl;//���Թ��̿�̽�м����
					//cout << i << endl;//���Թ��̿�̽�м����
				}
				else if (*abs != *abs2) { 
					abs2 = Head;//������ͷָ�룬Ҫ�����Ӵ�����ĵ�һ��λ�ã�
					break;
				 }
				i++;
				abs++;
				abs2++;
			}
			if (j == Lenth) {
              WhereAreYou = i;//��ʱ��¼���Ƕ����Ӵ���λ�ã�������ĸ���Ϊ���ȣ�����
				break;
			}
		}
		i++;
		abs++;
	}


	if (j != Lenth) {
		cout << "���������Ӵ�Ŷ��" << endl;
		return;
	}

	WhereAreYou -= Lenth;
	cout << "�±�Ϊ�� " << WhereAreYou << endl;
	return;
}

//����Ӵ��ĳ��ȣ�����
int Lenthstr2(char* str2)
{
	int i = 0;
	while (*str2) {
		str2++;
		i++;
	}
	//cout << i << endl;
	return i;

}