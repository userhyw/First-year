#include <iostream>

using namespace std;

void ScanfValue(int **a1, int &M, int &N);
void Travel(int **a1, int &M, int &N);
void ChengFa(int **a1, int &M, int &N, int **b1, int &P, int &Q, int **c1); 
//输入两个二维矩阵（阶数自定），求其乘积并输出
int main(void)
{
	int M, N, P, Q;
	int **a1 = NULL, **b1 = NULL, **c1 = NULL; 
	cout << "请分别输入两个矩阵的阶数：" << endl;
	cin >> M >> N >> P >> Q; 
	
	a1 = new int *[M];
	if (a1 == NULL) return 1;
	
	for (int i = 0; i < M; i++){
		a1[i] = new int [N];
	}
	
	b1 = new int *[P];
	if (b1 == NULL) return 1;
	
	for (int i = 0; i < P; i++){
		b1[i] = new int [Q];
	}
	
	c1 = new int *[M];
	if (c1 == NULL) return 1;
	
	for (int i = 0; i < M; i++){
		c1[i] = new int [Q];
	}
	
	for (int i = 0; i < M; i++){
		for (int j = 0; j < Q; j++){
			c1[i][j] = 0;
		}
	}
	
	cout << "请分别输入两个矩阵的各个元素：" << endl;
	ScanfValue(a1, M, N);
	ScanfValue(b1, P, Q);
	//Travel(a1, M, N);
	//Travel(b1, P, Q);
	
	ChengFa(a1, M, N, b1, P, Q, c1) ;
	Travel(c1, M, Q);
	
	system("pause");
	return 0;
	
}

//输入矩阵的值
void ScanfValue(int **a1, int &M, int &N)
{
	
	for (int i = 0; i <M; i++){
		for (int j = 0; j < N; j++){
			cin >> a1[i][j];
		}
	}
	
}


//输出测试 
void Travel(int **a1, int &M, int &N)
{
	
	for (int i = 0; i <M; i++){
		for (int j = 0; j < N; j++){
			cout << a1[i][j] << "  ";
		}
		cout << endl;
	}
	
}

//对矩阵经行乘法运算
void ChengFa(int **a1, int &M, int &N, int **b1, int &P, int &Q, int **c1) 
{
	for (int i = 0; i < M; i++){
		for (int j = 0; j < Q; j++){
			for (int k = 0; k < N; k++){
				c1[i][j] += a1[i][k] * b1[k][j];
			}
		}
	}
		
	
}


