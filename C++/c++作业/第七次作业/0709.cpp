//*********************************************************
//File name	 : 0709
//Author  	 : he yang
//Date   	 : 2021/11/27
//Student ID   : 2021218148
//*********************************************************
#include "0709.h"
int main(void)
{
    double (*p1) (float);
     p1 = isinx;
    double (*p2)(float);
     p2 = icosx;
    cout << "sin30 +cos60 = " << (*p1)(30) + (*p2)(60) << endl;

    system("pause");
    return 0;
}
 double isinx(float x)
{
    double rad =  (PI/180.) * x;
     double n = 0, c = 1;
    int sign = 1;
    int d = 1;
    for (int  i = 1; c  > 1e-6 ; i += 2){
        c = 1.0/d * rad;
        n += sign * c;
        sign = -sign;
        rad *= rad *rad;
        d *= (i + 1) * (i + 2);
    }
    return n;
}
 double icosx(float x)
{
     double rad =  (PI/180.) * x;
     double n = 0, c = 1;
    int sign = 1;
    int d = 1;
    for (int  i = 0; c  > 1e-6 ; i += 2){
        c = 1.0/d ;
        n += sign * c;
        sign = -sign;
        c *= rad *rad;
        d *= (i + 1) * (i + 2);
    }
    return n;
}
