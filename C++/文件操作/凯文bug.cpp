#include<iostream>
#include<cstdlib>
using namespace std;
int main() {
	float* fPBuff, fAvr = 0;//����ָ���ƽ������
	int i, n, iCount = 0;
	cin >> n;
	fPBuff = (float*)malloc(n * sizeof(float));
	if (fPBuff == NULL)
	{
		cout << "error" << endl;
		return 1;
	}
	for (i = 0; i < n; i++) {
		cin >> fPBuff[i];
	}for (i = 0; i < n; i++) {
		fAvr += (fPBuff[i] / n);
	}
	free(fPBuff);
	return 0;
}
