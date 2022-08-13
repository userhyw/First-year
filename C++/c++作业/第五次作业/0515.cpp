 //*********************************************************
//File name	 : 0515
//Author  	 : heyang
//Date   	 : 2021/11/5
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;

int main(void)
{
    int s1 = 0, s2 = 0, s3 = 0, s4  = 0, s5 = 0;
    int a[5][5] ={{17,24,1,8,15},{23,5,7,14,16},{4,6,13,20,22},{10,12,19,21,3},{11,18,25,2,9}};
    bool flage1  = 1, flage2 = 1, flage3 = 1;

    for (int j = 0; j < 5; j++){
        s1 += a[0][j];

    }
    // cout << s1 << endl;

     int i  = 1, j = 0;
     do{
            s2 = 0;
        for(int j = 0; j < 5; j++){
            s2 += a[i][j];
            //cout << s2 << endl;
        }
        if (s1 != s2){
            flage1 = 0;
        }
        i++;
     }while(flage1 && i < 5);

 int k  = 0, l = 0;
     do{
            s3 = 0;
        for(int l = 0; l < 5; l++){
            s3 += a[l][k];
        }
        //cout << s3 << endl;
        if (s1 != s3){
            flage2 = 0;
        }
     k++;
     }while(flage2 && k < 5);

     int p = 0;
    for (int h = 0; h < 5 ; h++){
        s4 += a[h][h];
        s5 += a[h][4-h];
    }
    //cout << s3 << s4 << endl;

     if(flage1 == 1 && flage2 == 1 ){
        if(s4 == s3){
            if (s4 == s1){
                cout << "这是一个魔方矩阵" << endl;
            }
        }
     }
    else{
        cout << "这不是魔方矩阵" << endl;
    }

    system("pause");
    return 0;
}
