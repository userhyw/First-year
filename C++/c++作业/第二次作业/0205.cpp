//*********************************************************
//File name	 : 0205
//Author  	 : ����
//Date   	 : 2021/10/20
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
 using namespace std;
 #include<math.h>
 #include<stdlib.h>
 int main(void)
 {
     float x, y, z, d, x1, y1, z1;
     cout << "��ֱ�����x, y, z������"<< endl;
     cin >> x >> y >> z;
     d = sqrt(x * x + y * y + z * z);
     x1 = acos(x/d);
     y1 = acos(y/d);
     z1 = acos(z/d);
     cout << "�õ㵽ԭ��ľ���Ϊ��"<< d << endl;
     cout << "�õ���x��н�Ϊ��" << x1 << endl;
     cout << "�õ���y��н�Ϊ��" << y1 << endl;
     cout << "�õ���z��н�Ϊ��" << z1 << endl;

     system("pause");

     return 0;
 }
