//*********************************************************
//File name	 : 0615
//Author  	 : heyang
//Date   	 : 2021/11/14
//Student ID   : 2021218148
//*********************************************************
#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int main(void)
{
    float a[3][4] = {{3,2,8,3},
                     {5,9,7,8},
                     {9,19,11,12}};
    float s1, s2, s3;
    double S1 = 0, S2 = 0, S3 = 0;
    float *p2 = NULL;
    p2 = a[0];
    while (p2 < a[0] + 12){
        if (p2 < a[0] + 4){
            s1 += *p2;
        }
        else if (p2 < a[0] + 8){
            s2 += *p2;
        }
        else if (p2 < a[0] + 16){
            s3 += *p2;
        }
        p2++;
    }
    s1 /= 4.0;
    s2 /= 4.0;
    s3 /= 4.0;

    p2 = a[0];
    while (p2 < a[0] + 12){
        if (p2 < a[0] + 4){
           S1 += (s1 - (*p2)) * (s1 - (*p2));
        }
        else if (p2 < a[0] + 8 ){
            S2 += (s2 - (*p2)) * (s2 - (*p2));
        }
        else if (p2 < a[0] + 16){
             S3 += (s3 - (*p2)) * (s3 - (*p2));
        }
        p2++;
    }
    S1 /= 4.0;
    S2 /= 4.0;
    S3 /= 4.0;

    float b[3][2] = {s1,S1,s2,S2,s3,S3};//莫名其妙的东西
     p2 = b[0];
     while (p2 < b[0] + 6){
        cout << *p2 << endl;
        p2++;
     }
    system("pause");
    return 0;
}
