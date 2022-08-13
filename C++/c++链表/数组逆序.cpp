#include <iostream>
#include <iomanip>

using namespace std;

//写一个函数实现数组逆置 
//奇偶均成功实现！

void IOU(int* p, int n) {

	int* q;
	q = p + n - 1;

	for (; p < q; p++, q--) {

		int temp = *p;
		*p = *q;
		*q = temp;
	}

}

int main()
{
	int a[10], b[7];
	cout << "输入数组a的十个整形元素" << endl;
	for (int i = 0; i < 7; i++) {
		cin >> b[i];
	}

	IOU(b, 7);

	for (int i = 0; i < 7; i++) {
		cout << b[i] << " ";
	}

	system("pause");
	return 0;
}