#include<iostream>
#include<cstring>
#include<iomanip>
#include<stdlib.h>
using namespace std;


struct Student//����ѧ���ṹ��
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
        cout << "���������� ѧ�ź����ųɼ�" << endl;
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
        cout << "�������" << endl;
        //  system("pause");
           //system("cls");
    }
    cout << "wocaibuaini" << endl;
}

void order(Student* p, int n)//��ѧ�����з�������(ð������)
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
    cout << "   ������ " << "   ѧ�ţ�" << "     " << "   sub1�� " << "  sub2�� " << "   sub3�� " << "   sub4�� " << "   ALL�� " << "   Avr�� " << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i].name << setw(7) << p[i].num << "     "
            << p[i].arr[0] << setw(7) << p[i].arr[1] << setw(7) << p[i].arr[2] << setw(7)
            << p[i].arr[3] << setw(7)
            << p[i].All_s << setw(7) << p[i].Avr_s << endl;
    }
    cout << "��ʾ��� �ɼ������ϣ����������ѡ��ϵͳ" << endl;
    system("pause");
    //system("cls");
}

int main(void) {
    int n, Choice;
    cout << "������ѧ��������" << endl;
    cin >> n;
    struct Student* p = (struct Student*)calloc(n, sizeof(struct Student));
    if (p == NULL) {
        cout << "�����ڴ�ʧ��" << endl;
        return 1;
    }
    while (1) {
        cout << "ѧ���ɼ�����ϵͳ��ӭ����ʹ��" << endl;
        cout << "1.����ѧ����������ѧ�ź����ųɼ�" << endl;
        cout << "2.�鿴ѧ�����ܷ������б�" << endl;
        cout << "3.�˳�ϵͳ" << endl;
        cout << "��ѡ��ϵͳ����" << endl;

        cin >> Choice;
        switch (Choice)
        {
        case 1://����ѧ����Ϣ
            putin(p, n);
            cout << "111111111111" << endl;
            break;
        case 2://�鿴ѧ����Ϣ
            order(p, n);
            putout(p, n);
            cout << "2222222222222222" << endl;
            break;
        case 3://�˳�ϵͳ
            cout << "33333333" << endl;
            delete p;
            return 0;
        }
    }
    return 0;
}