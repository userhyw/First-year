#include<iostream>
#include<cstring>
#include<iomanip>
#include<stdlib.h>
using namespace std;


struct Student//创建学生结构体
{
    struct Student() {
        name = "hello";
        num = "cao";

        for (int i = 0; i < 4; i++) {
            arr[i] = 0;
        }
    }

    string name;
    string num;
    float arr[4];
    float All_s;
    float Avr_s;
    void culculate()
    {
        for (int i = 0; i < 4; i++)
        {
            All_s += arr[i];
        }
        Avr_s = All_s / 4.0;
    }
};

void getgrades(Student* p, int n)
{
    for (int i = 0; i < n; i++) {
        p[i].culculate();
    }

}

void putin(struct Student* p, int n)
{
    cout << "woaini " << endl;
    for (int j = 0; j < n; j++)
    {
        cout << "请输入姓名 学号和四门成绩" << endl;
        string name, num;
        //float arr0, arr1, arr2, arr3;
        //cin >> name >> num;
        //cin >> arr0 >> arr1 >> arr2 >> arr3;
        p[j].name = name;
        //p[j].num = num;
        //p[j].arr[0] = arr0;
        //p[j].arr[1] = arr1;
        //p[j].arr[2] = arr2;
        //p[j].arr[3] = arr3;
          cin >> p[j].name
              >>p[j].num
              >>p[j].arr[0]
              >>p[j].arr[1]
              >>p[j].arr[2]
              >>p[j].arr[3];
        cout << "输入完毕" << endl;
        //  system("pause");
           //system("cls");
    }
    cout << "wocaibuaini" << endl;
}

void order(Student* p, int n)//对学生进行分数排序(冒泡排序)
{
    for (int i = 0; i < n - 1; i++)
    {
        float imax = p[i].All_s;
        for (int j = i + 1; j < n; j++)
        {
            if (imax < p[j].All_s)
            {
                struct Student iTmp = p[j];
                p[j] = p[i];
                p[i] = iTmp;
            }
        }
    }
}
void putout(Student* p, int n)
{
    cout << "   姓名： " << "   学号：" << "     " << "   sub1： " << "  sub2： " << "   sub3： " << "   sub4： " << "   ALL： " << "   Avr： " << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i].name << setw(7) << p[i].num << "     "
            << p[i].arr[0] << setw(7) << p[i].arr[1] << setw(7) << p[i].arr[2] << setw(7)
            << p[i].arr[3] << setw(7)
            << p[i].All_s << setw(7) << p[i].Avr_s << endl;
    }
    cout << "显示完毕 成绩表如上，任意键返回选择系统" << endl;
    system("pause");
    //system("cls");
}

int main(void) {
    int n, Choice;
    cout << "请输入学生的数量" << endl;
    cin >> n;
    struct Student* p = (struct Student*)calloc(n, sizeof(struct Student));
    if (p == NULL) {
        cout << "分配内存失败" << endl;
        return 1;
    }
    while (1) {
        cout << "学生成绩管理系统欢迎您的使用" << endl;
        cout << "1.输入学生的姓名，学号和四门成绩" << endl;
        cout << "2.查看学生的总分排名列表" << endl;
        cout << "3.退出系统" << endl;
        cout << "请选择系统操作" << endl;

        cin >> Choice;
        switch (Choice)
        {
        case 1://输入学生信息
            putin(p, n);
            cout << "111111111111" << endl;
            break;
        case 2://查看学生信息
            order(p, n);
            putout(p, n);
            cout << "2222222222222222" << endl;
            break;
        case 3://退出系统
            cout << "33333333" << endl;
            delete p;
            return 0;
        }
    }
    return 0;
}