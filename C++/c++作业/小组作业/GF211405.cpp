//*********************************************************
//File name	 : 05
//Author  	 : he yang
//Date   	 : 2021/12/02
//Student ID   : 2021218148
//*********************************************************
/*Ŀ�ģ�����һ���ַ��������е������±�λ�õ�Сд��ĸ���ɶ�Ӧ�Ĵ�д��ĸ�����಻�䣬��������*/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void Transform(char* abs);

int main(void)
{
	char str[80];
	cout << "������һ���ַ���" << endl;
	cin.getline(str, 80);
	Transform(str);
	cout << str << endl;

	system("pause");
	return 0;
}

//�����������ҵ������±��Сд��ĸ������ת��������
void Transform(char * abs)
{
	int flage = 0;
	while (*abs) {
		if (flage % 2 != 0) {
			if (*abs >= 'a' && *abs <= 'z') {
					*abs -= 32;
			}
		}
		flage++;
		abs++;
	}

	return;
}