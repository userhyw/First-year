#include<iostream>
using namespace std;
void cheng(double* p, double* q, int m, int  n, int a, int b, int c, int d) {
    double sum = 0;
    for (int c = 0; c < m; c++) //����С�ڵ��ڵ�һ�����������
    {
        for (int d = 0; d < m; d++) //����С�ڵ��ڵڶ������������
        {
            int sum = 0;
            for (int k = 0; k < n; k++) //��һ�����������͵ڶ�����������
            {
                sum += a[c][k] * b[d][k];//����
            }
            char  h[c][d] = sum;
        }
    }
    for (int c = 0; c < m; c++)
    {
        for (int d = 0; d < b; d++)
        {
            cout << h[c][d] << endl;
        }
    }
}
int main(void)
{
    double a[100][100], b[100][100], h[100][100];
    int m, n, p, q, i, j, k, l, c, d;
    cin >> m >> n;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];//�����һ������
        }
    }
    cin >> p >> q;//�ڶ������������
    for (l = 0; l < p; l++)
    {
        for (k = 0; k < q; k++)
        {
            cin >> b[l][k];//����ڶ�������
        }
    }
    cheng(*a, *b, m, n, p, q ,c , d);

    return 0;
}