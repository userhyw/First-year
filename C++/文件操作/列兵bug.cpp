#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;

class student
{
public:
    int num;
    string name;
    float sub1, sub2, sub3, sub4;
};

void Findmax(float* q, student* p, int n)
{
    student iTemp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (q[i] > q[j])
            {
                iTemp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = iTemp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "请输入学生的人数 : ";
    cin >> n;
    student* p = (student*)malloc(sizeof(student) * n);
    float* a_p = (float*)malloc(sizeof(float) * n);
    float* s_p = (float*)malloc(sizeof(float) * n);
    if (p == NULL)
    {
        return 0;
    }
    memset(p, 0, sizeof(student) * n);
    cout << "请分别输入学生的学号、姓名和四门考试的成绩 : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> (p + i)->num;
        cin >> (p + i)->name;
        cin >> (p + i)->sub1;
        cin >> (p + i)->sub2;
        cin >> (p + i)->sub3;
        cin >> (p + i)->sub4;

    }
    for (int i = 0; i < n; i++)
    {
        s_p[i] = (p + i)->sub1 + (p + i)->sub2 + (p + i)->sub3 + (p + i)->sub4;
        a_p[i] = s_p[i] / 4.0;
    }

    Findmax(s_p, p, n);

    cout << endl << "学生的成绩排名是 : " << endl;
    cout << "排名\t学号\t姓名\t成绩一\t成绩二\t成绩三\t成绩四\t总成绩\t平均成绩" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t"
            << (p + i)->num << "\t"
            << (p + i)->name << "\t"
            << (p + i)->sub1 << "\t"
            << (p + i)->sub1 << "\t"
            << (p + i)->sub3 << "\t"
            << (p + i)->sub4 << "\t"
            << s_p[i] << "\t"
            << a_p[i] << endl;
    }
    free(p);
    free(s_p);
    free(a_p);
    return 0;
}
