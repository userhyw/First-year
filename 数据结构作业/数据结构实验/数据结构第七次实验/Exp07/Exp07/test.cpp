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
	cout << "�������ݣ���1008611��������" <<endl;
	keytype x;
	int i = 0;
	while (cin >> x && x != 1008611) {
		A[i++].key = x;
	}
	cout << "����Ҫ���ҵ�Ԫ�أ���1008611��������" <<endl;
	while (cin >> x && x != 1008611) {
		if (bin_search(A, i, x) == -1) {
			cout << "�����ڸ�Ԫ�أ�" << endl;
		}
		cout << endl;
	}
	cin.get();
}
void test2() {
	createBst(root);
	cout << "���������\n";
	printBST(root);
}
void test3() {
	createBst(root);
	keytype x;
	cout << "����Ҫ���ҵ�Ԫ�أ���1008611��������"<<endl;
	while (cin >> x && x != 1008611) {
		node* addr = NULL;
		if (addr = BstSearch(root, x)) {
			cout << "��Ԫ�ص�ַΪ��" << addr << endl;
		}
		else {
			cout << "�����ڸ�Ԫ��!" << endl;
		}
		cout <<endl;
	}
}
void test4() {
	createBst(root);
	keytype x;
	cout << "ɾ��ǰ��\n";
	printBST(root);
	cout << "����Ҫɾ����Ԫ�أ���1008611��������"<<endl;
	while (cin >> x && x != 1008611) {
		remove(root, x);
		cout << "ɾ����" << endl;
		printBST(root);
	}
}
void test5() {
	cout << "�������ݣ���1008611��������" <<endl;
	keytype x;
	while (cin >> x && x != 1008611) {
		AVLinsert(AVL, x);
	}
	cout << "�����ɹ���" << endl;
	printBST(AVL);
	cout << "������������߶ȣ�";
	if (AVL->lc) {
		cout << AVL->lc->height << endl;
	}
	else cout << 0 << endl;
	cout << "������������߶ȣ�";
	if (AVL->rc) {
		cout << AVL->rc->height << endl;
	}
	else cout << 0 << endl;
}

void init_my(void)
{
        cout << "1.�Ը������ݱ����ö��ֲ����㷨ʵ�ֲ��ң��������ҹ����������Ƚϵ�Ԫ�أ����±꣩��" <<endl;
		cout << "2.���������й�������������" << endl;
		cout << "3.�ڶ����������в���ָ��ֵ�Ľ��" << endl;
		cout << "4.�ڶ�����������ɾ���ض�ֵ�Ľ�㡣" << endl;
		cout << "5.����AVL��" << endl;
		cout << "����---1008611---�˳���" << endl;
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
