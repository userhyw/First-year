//*********************************************************
//File name	 : 0211
//Author  	 : ����
//Date   	 : 2021/10/18
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
using namespace std;

#include<stdlib.h>
int main(void)
{
    char a, b;

	cout << "������һ���ַ�" << endl;
	cin >> b;
	a = (int) b;
	if (a >= 48 && a <= 57)
    {
        cout << "����һ�������ַ�" << endl;
    }
	else if (a >= 65 && a <= 90)
    {
        cout << "����һ����д��ĸ" << endl;
    }
	else if (a >= 97 && a <= 122)
    {
        cout << "����һ��Сд��ĸ" << endl;
    }
	else
    {
        cout << "����һ�������ַ�"<< endl;
    }


	system("pause");

	return 0;



}
