#include"bin_search.h"
#include"BST.h"
#include<cstdio>
#include<iostream>
#include<cstdlib>

#define MAXLEN 10000
using namespace std;

elementType A[MAXLEN];
node* root;
node* AVL;

void test1() {
	cout << "输入数据（以1008611结束）：" <<endl;
	keytype x;
	int i = 0;
	while (cin >> x && x != 1008611) {
		A[i++].key = x;
	}
	cout << "输入要查找的元素（以1008611结束）：" <<endl;
	while (cin >> x && x != 1008611) {
		if (bin_search(A, i, x) == -1) {
			cout << "不存在该元素！" << endl;
		}
		cout << endl;
	}
	cin.get();
}
void test2() {
	createBst(root);
	cout << "创建结果：\n";
	printBST(root);
}
void test3() {
	createBst(root);
	keytype x;
	cout << "输入要查找的元素（以1008611结束）："<<endl;
	while (cin >> x && x != 1008611) {
		node* addr = NULL;
		if (addr = BstSearch(root, x)) {
			cout << "该元素地址为：" << addr << endl;
		}
		else {
			cout << "不存在该元素!" << endl;
		}
		cout <<endl;
	}
}
void test4() {
	createBst(root);
	keytype x;
	cout << "删除前：\n";
	printBST(root);
	cout << "输入要删除的元素（以1008611结束）："<<endl;
	while (cin >> x && x != 1008611) {
		remove(root, x);
		cout << "删除后：" << endl;
		printBST(root);
	}
}
void test5() {
	cout << "输入数据（以1008611结束）：" <<endl;
	keytype x;
	while (cin >> x && x != 1008611) {
		AVLinsert(AVL, x);
	}
	cout << "创建成功！" << endl;
	printBST(AVL);
	cout << "根结点左子树高度：";
	if (AVL->lc) {
		cout << AVL->lc->height << endl;
	}
	else cout << 0 << endl;
	cout << "根结点右子树高度：";
	if (AVL->rc) {
		cout << AVL->rc->height << endl;
	}
	else cout << 0 << endl;
}

void init_my(void)
{
        cout << "1.对给定数据表，采用二分查找算法实现查找，给出查找过程依次所比较的元素（的下标）。" <<endl;
		cout << "2.由输入序列构建二叉排序树" << endl;
		cout << "3.在二叉排序树中查找指定值的结点" << endl;
		cout << "4.在二叉排序树中删除特定值的结点。" << endl;
		cout << "5.构建AVL。" << endl;
		cout << "输入---1008611---退出：" << endl;
}

int main() {
	int choose = -1;
	while (choose != 1008611) {
        init_my();
		cin >> choose;
        system("cls");
		switch (choose) {
		case 1:
			test1();
			break;
		case 2:
			test2();
			break;
		case 3:
			test3();
			break;
		case 4:
			test4();
			break;
		case 5:
			test5();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}
