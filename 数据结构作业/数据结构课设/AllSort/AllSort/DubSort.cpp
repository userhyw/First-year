#include "bubble_sort.h"
#include "heap_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include <cstdlib>
#include <iomanip>  //���ȿ��ƺ���λ�ڸÿ���
#include <algorithm> //sort������
#include <windows.h>//������ʱ
#define MAX 50000
using namespace std;
void myRandom(int arr[], int wide, int n);
void MyPrintf(int arr[], int n);
void copyArr(int arr[], int useArr[], int n);
void init(void);
bool cmp2(int a, int b);
bool cmp1(int a, int b);

int main(void)
{
	int *arr = new int[MAX], *useArr = new int[MAX];//���ٿռ�
	clock_t star, finish; //>= 10ms
	LARGE_INTEGER t1, t2, tc;
	myRandom(arr, MAX, MAX);//�������ʼ������
	//quick_sort(arr, 0, MAX_FOUR - 1);

	int select = -1;
	while (select != 1008611)
	{
		init();
		cin >> select;
		system("cls");

		switch (select)
		{
		case 1://ð��
		{
			star = 0;
			finish = 0;
			bubble_compare = 0;
			bubble_swap = 0;
			copyArr(arr, useArr, MAX);
			//star = clock();
			QueryPerformanceFrequency(&tc);
			QueryPerformanceCounter(&t1);
			bubble_sort(useArr, MAX);
			//finish = clock();
			QueryPerformanceCounter(&t2);

			cout << "ð������" << endl;
			cout << "��ʱ��" << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;
			cout << "�Ƚϴ�����" << bubble_compare << endl;
			cout << "����������" << bubble_swap << endl;
			//MyPrintf(useArr, MAX);
			break;
		}
		case 2://ϣ������
		{
			star = 0;
			finish = 0;
			shell_compare = 0;
			shell_swap = 0;
			copyArr(arr, useArr, MAX);
			//star = clock();
			QueryPerformanceFrequency(&tc);
			QueryPerformanceCounter(&t1);
			shell_sort(useArr, MAX);
			//finish = clock();
			QueryPerformanceCounter(&t2);
		
			cout << "ϣ������" << endl;
			cout << "��ʱ��" << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;
			cout << "�Ƚϴ�����" << shell_compare << endl;
			cout << "����������" << shell_swap << endl;
			//MyPrintf(useArr, MAX);
			break;
		}
		case 3://�鲢
		{
			star = 0;
			finish = 0;
			merge_compare = 0;
			merge_swap = 0;
			copyArr(arr, useArr, MAX);
			//star = clock();
			QueryPerformanceFrequency(&tc);
			QueryPerformanceCounter(&t1);
			merge_sort(useArr, MAX);
			//finish = clock();
			QueryPerformanceCounter(&t2);

			cout << "�鲢����" << endl;
			cout << "��ʱ��" << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;
			cout << "�Ƚϴ�����" << merge_compare << endl;
			cout << "����������" << merge_swap << endl;
			//MyPrintf(useArr, MAX);
			break;
		}
		case 4://����
		{
			star = 0;
			finish = 0;
			quick_compare = 0;
			quick_swap = 0;
			copyArr(arr, useArr, MAX);
			//star = clock();
			QueryPerformanceFrequency(&tc);
			QueryPerformanceCounter(&t1);
			quick_sort(useArr, 0, MAX - 1);
			QueryPerformanceCounter(&t2);
			//finish = clock();

			cout << "��������" << endl;
			cout << "��ʱ��" << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;
			cout << "�Ƚϴ�����" << quick_compare << endl;
			cout << "����������" << quick_swap << endl;
			MyPrintf(useArr, MAX);
			break;
		}
		case 5:
		{
			star = 0;
			finish = 0;
			heap_compare = 0;
			heap_swap = 0;
			copyArr(arr, useArr, MAX);
			//star = clock();
			QueryPerformanceFrequency(&tc);
			QueryPerformanceCounter(&t1);
			heap_sort(useArr, MAX);
			//finish = clock();
			QueryPerformanceCounter(&t2);

			cout << "������" << endl;
			cout << "��ʱ��" << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;
			cout << "�Ƚϴ�����" << heap_compare << endl;
			cout << "����������" << heap_swap << endl;
			//MyPrintf(useArr, MAX);
			break;
		}
		case 6:
		{
			MyPrintf(arr, MAX);
			break;
		}
		case 7:
		{
			myRandom(arr, MAX, MAX);
			cout << "OK" << endl;
			break;
		}
		case 8:
		{
			sort(arr, arr + MAX, cmp2);
			cout << "OK" << endl;
			break;
		}
		case 9:
		{
			sort(arr, arr + MAX, cmp1);
			cout << "OK" << endl;
			break;
		}
		default:
			break;
		}
		system("pause");
		system("cls");
	}



	delete[] arr;
	delete[] useArr;
	return 0;
}

//������
bool cmp1(int a, int b)
{
	return a > b;
}

bool cmp2(int a, int b)
{
	return a < b;
}

//���������
void myRandom(int arr[], int wide, int n)
{
	srand((int)time(0));  // �����������  ��0����NULLҲ��
	for (int i = 0; i < n; i++)
		arr[i] = rand() % wide;
}

//��ӡ����Ԫ��
void MyPrintf(int arr[], int n)
{
	long long c = 1;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
		if (c % 9 == 0) cout << endl;
		c++;
	}
}

//��������
void copyArr(int arr[], int useArr[], int n)
{
	for (int i = 0; i < n; i++)
		useArr[i] = arr[i];
}

//��ӡ��ʾ��Ϣ
void init(void)
{
	cout << "1.����ð������" << endl;
	cout << "2.����ϣ������" << endl;
	cout << "3.���й鲢����" << endl;
	cout << "4.���п�������" << endl;
	cout << "5.���ж�����" << endl;
	cout << "6.�鿴��ǰ����" << endl;
	cout << "7.������ǰ���������" << endl;
	cout << "8.�ѵ�ǰ�����Ϊ����" << endl;
	cout << "9.�ѵ�ǰ�����Ϊ����" << endl;
	cout << "����---1008611----�˳�" << endl;
}



