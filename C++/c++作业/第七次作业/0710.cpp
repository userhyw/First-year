//*********************************************************
//File name	 : 0710
//Author  	 : he yang
//Date   	 : 2021/11/27
//Student ID   : 2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;
void Count(char *p1, int * p2);
int main(void)
{
    int iCount[4];
    char str[80];
    cout << "ÇëÊäÈëÒ»´®×Ö·û" << endl;
    cin.getline(str, 80);
    Count(str, iCount);
    for (int i = 0; i < 4; i++){
        cout << iCount[i] << endl;
    }

    system("pause");
    return 0;
}
void Count(char *p1, int *p2)
{
    for (int i = 0; i < 4 ; i++){
        p2[i] = 0;
    }
    while (*p1){
        if (*p1 >= 'a' && *p1 <= 'z'){
            p2[1]++;
        }
        else if (*p1 >= 'A' && *p1 <= 'Z'){
            p2[0]++;
        }
        else if (*p1 >= '0' && *p1 <= '9'){
            p2[2] ++;
        }
        else {
            p2[3] ++;
        }
        p1++;
}

return ;
}
