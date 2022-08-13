//*********************************************************
//File name	 : 32
//Author  	 : he yang
//Date   	 : 2021/12/02
//Student ID   : 2021218148
//*********************************************************

/*目的：完成对主字符串中的子串查找，并记录位置输出！*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;


void FindPrintf(char* abs, char* abs2, int Lenth);
int Lenthstr2(char* str2);


int main(void)
{
	//str承载主字符串，str2承载子串，lenth记录子串的长度
	char str[80], str2[20];
	int lenth = 0;
	cout << "请输入一个字符串" << endl;
	cin.getline(str, 80);

	cout << "请输入您要查找的字串：" << endl;
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


	//注释：abs++的地方 i也++；要保持主字符串的移位于i同步
	while (*abs) {

		if (*abs == *abs2) {
			j = 0;//每一次进入下面的循环，j的值都为0，防止单个子串中的元素使j累计；
			
			while (*abs2) {
				
				if (*abs == *abs2) {
					j++;
					//cout << j << endl;//调试过程窥探中间过程
					//cout << i << endl;//调试过程窥探中间过程
				}
				else if (*abs != *abs2) { 
					abs2 = Head;//类似于头指针，要保留子串数组的第一个位置；
					break;
				 }
				i++;
				abs++;
				abs2++;
			}
			if (j == Lenth) {
              WhereAreYou = i;//此时记录的是读完子串的位置，多出来的个数为长度！！！
				break;
			}
		}
		i++;
		abs++;
	}


	if (j != Lenth) {
		cout << "不包含该子串哦！" << endl;
		return;
	}

	WhereAreYou -= Lenth;
	cout << "下标为： " << WhereAreYou << endl;
	return;
}

//获得子串的长度！！！
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