#include <iostream>

using namespace std;
const int N = 50;
const int n = 15;

//这个题目直接拉跨，答案是错的。出卷子答案搞好，不然狠浪费大家时间的。

void circle(int a[N]);
int main(void)
{
	int a[N] = { 0 };
	for (int i = 0; i < N; i++) {
		a[i] = i;
	}

	circle(a);

	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

void circle(int a[N])
{
	int cnt = n;
	int t = -1;
	int N1 = N;
	while (cnt) {
		for (int i = 0; i < N; i++) {
			if (a[i] == i) {
				t++;
			}
			if (t == 7 && cnt > 0) {
				cnt--;
				t = 0;
				a[i] = 0;
			}
		}
	}

}