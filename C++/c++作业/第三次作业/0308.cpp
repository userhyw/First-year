//*********************************************************
//File name	 :0308
//Author  	 :heyang 
//Date   	 :10.28
//Student ID   :2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(void)
{
    float a, b, c, d;//������˵��д
    int s;//�����ܳɼ�
    cout << "��ֱ�����������.˵.��.д.�ɼ�" <<endl;
    cin >> a >> b >> c >> d;
    if(a >= 5 && b >= 5 && c >= 5 && d >=5)
    {
        s = (a + b + c + d)/4;
        if(s >= 6)
        {
            cout << "��ϲ������˼�ɼ��ϸ���" <<endl;
        }
        else
        {
            cout << "������˼����û�кϸ�" <<endl;
        }
    }
    else
    {
        cout << "������˼�ɼ�û�кϸ�" << endl;
    }

    system("pause");
    return 0;
}
