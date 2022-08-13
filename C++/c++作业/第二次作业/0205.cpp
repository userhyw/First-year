//*********************************************************
//File name	 : 0205
//Author  	 : 贺洋
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
     cout << "请分别输入x, y, z的坐标"<< endl;
     cin >> x >> y >> z;
     d = sqrt(x * x + y * y + z * z);
     x1 = acos(x/d);
     y1 = acos(y/d);
     z1 = acos(z/d);
     cout << "该点到原点的距离为："<< d << endl;
     cout << "该点与x轴夹角为：" << x1 << endl;
     cout << "该点与y轴夹角为：" << y1 << endl;
     cout << "该点与z轴夹角为：" << z1 << endl;

     system("pause");

     return 0;
 }
