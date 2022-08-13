//*********************************************************
//File name	 : 05
//Author  	 : he yang
//Date   	 : 2021/12/02
//Student ID   : 2021218148
//*********************************************************
/*目的：输入一串字符，将其中的奇数下标位置的小写字母表换成对应的大写字母，其余不变，并输出结果*/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void Transform(char* abs);

int main(void)
{
	char str[80];
	cout << "请输入一串字符串" << endl;
	cin.getline(str, 80);
	Transform(str);
	cout << str << endl;

	system("pause");
	return 0;
}

//遍历过程中找到奇数下标的小写字母并进行转化！！！
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