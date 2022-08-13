#include "bubble_sort.h"
#include "heap_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include <cstdlib>
#include <iomanip>  //精度控制函数位于该库中
#include <algorithm> //sort排序函数
#include <windows.h>//更换计时
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
	int *arr = new int[MAX], *useArr = new int[MAX];//开辟空间
	clock_t star, finish; //>= 10ms
	LARGE_INTEGER t1, t2, tc;
	myRandom(arr, MAX, MAX);//随机数初始化数组
	//quick_sort(arr, 0, MAX_FOUR - 1);

	int select = -1;
	while (select != 1008611)
	{
		init();
		cin >> select;
		system("cls");

		switch (select)
		{
		case 1://冒泡
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

			cout << "冒泡排序：" << endl;
			cout << "用时：" << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;
			cout << "比较次数：" << bubble_compare << endl;
			cout << "交换次数：" << bubble_swap << endl;
			//MyPrintf(useArr, MAX);
			break;
		}
		case 2://希尔排序
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
		
			cout << "希尔排序：" << endl;
			cout << "用时：" << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;
			cout << "比较次数：" << shell_compare << endl;
			cout << "交换次数：" << shell_swap << endl;
			//MyPrintf(useArr, MAX);
			break;
		}
		case 3://归并
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

			cout << "归并排序：" << endl;
			cout << "用时：" << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;
			cout << "比较次数：" << merge_compare << endl;
			cout << "交换次数：" << merge_swap << endl;
			//MyPrintf(useArr, MAX);
			break;
		}
		case 4://快速
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

			cout << "快速排序：" << endl;
			cout << "用时：" << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;
			cout << "比较次数：" << quick_compare << endl;
			cout << "交换次数：" << quick_swap << endl;
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

			cout << "堆排序：" << endl;
			cout << "用时：" << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;
			cout << "比较次数：" << heap_compare << endl;
			cout << "交换次数：" << heap_swap << endl;
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

//排序函数
bool cmp1(int a, int b)
{
	return a > b;
}

bool cmp2(int a, int b)
{
	return a < b;
}

//随机数生成
void myRandom(int arr[], int wide, int n)
{
	srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	for (int i = 0; i < n; i++)
		arr[i] = rand() % wide;
}

//打印数组元素
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

//复制数组
void copyArr(int arr[], int useArr[], int n)
{
	for (int i = 0; i < n; i++)
		useArr[i] = arr[i];
}

//打印提示信息
void init(void)
{
	cout << "1.进行冒泡排序" << endl;
	cout << "2.进行希尔排序" << endl;
	cout << "3.进行归并排序" << endl;
	cout << "4.进行快速排序" << endl;
	cout << "5.进行堆排序" << endl;
	cout << "6.查看当前数组" << endl;
	cout << "7.更换当前数组随机数" << endl;
	cout << "8.把当前数组改为升序" << endl;
	cout << "9.把当前数组改为降序" << endl;
	cout << "输入---1008611----退出" << endl;
}



