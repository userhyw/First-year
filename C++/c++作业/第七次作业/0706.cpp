//*********************************************************
//File name	 : 0706
//Author  	 : he yang
//Date   	 : 2021/10/20
//Student ID   : 2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <stdlib.h>

int fun(int n, int *p1, int *p2);
// very complex
using namespace std;
bool flage =0;
int main(void)
{
     int a[2], b[2];
    int n;
    cout << "please enter a four digits and no zero :" << endl;
    cin >> n;
    fun(n, a, b);
    if (flage != 0 ){
            cout << "wrong" << endl;
        return 0;
    }
    cout << a[0] << a[1] << "  "<< b[0] << b[1] << endl;
    system("pause");
    return 0;
}
int fun(int n, int *p1, int *p2)
{
    if (n < 0){
    	return flage = 1;
	}
    int i = 0;
    while (i < 2){
        *p1 = n%10;
        p1++;
        if (n%10==0){
            flage++;
        }
        n /=10;
        i++;
    }
    while (i < 4){
        *p2 = n%10;
        p2++;
        if (n%10==0){
            flage++;
        }
        n /=10;
        i++;
    }
        return flage;
}
