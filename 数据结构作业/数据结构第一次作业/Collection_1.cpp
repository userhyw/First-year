#include <iostream>
#define NEWLINE cout << endl

#define A 10
#define B 10
#define C  (A + B)
using namespace std;

int Colle_1(int *a1, int n1, int *b1, int n2, int *c1);//函数声明加分号


int main(void)
{
    //目的是用顺序表表示集合，然后实现交集，并集这些功能。
    //函数来实现。

//    int a1[A], b1[B], c1[C];

    //为了调试方便，这里直接在程序中写好数组
    int a1[A] = {1, 2, 3, 4, 5, 6, 7,  8, 9, 10};
    int b1[B] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int c1[C];

    //调用函数实现并
    int m_c = Colle_1(a1, A, b1, B, c1);

    for (int i = 0; i < m_c; i++)
    {
        cout << c1[i] <<"\t";
    }
    NEWLINE;


}

//函数实现集合的并, 返回的是c1中数组的长度
int Colle_1(int *a1, int n1, int *b1, int n2, int *c1)
{
    //实现并，将元素存到C数组中

    bool Flage1 = true;//判断元素是否相同标志
    int k = 0;//记录c1数组的长度

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a1[i] == b1[j])
            {
                Flage1 = false;
                break;
            }
        }
        if (Flage1)
        {
            //找到一个不是相同元素的，直接加入到C中
            c1[k] = a1[i];
            k++;
        }
        else
        {
            Flage1 = true;//元素相同，继续遍历
        }

    }

    //循环结束后，a1中所有和b不同的已经加入到了c1中
    //现在把b1中所有元素放入c1中
    for (int j = 0; j < n2; j++){
        c1[k] = b1[j];
        k++;
    }
        return k;

}







