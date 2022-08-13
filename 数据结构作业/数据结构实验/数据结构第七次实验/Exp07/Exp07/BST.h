#pragma once
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

typedef int keytype;

typedef struct Bnode {
	keytype data;//�ؼ���
	int height;//�ýڵ�ĸ߶ȣ�����AVL����
	struct Bnode* lc, * rc; //���ӣ��Һ���
}node;


//�����������Ĳ����㷨
void insert(node*& T, node* s) {
	if (T == NULL) { //����ǰ���Ϊ�գ����ڴ˲���
		T = s;
	}
	else if (s->data < T->data) { //������ֵ�ȵ�ǰ���С�������������ݹ�
		insert(T->lc, s);
	}
	else {//������ֵ�ȵ�ǰ���������������ݹ�
		insert(T->rc, s);
	}
}

//��������������
void createBst(node*& T) {
	T = NULL;
	keytype x;
	cout << "�������ݣ���1008611��������";
	while (cin >> x && x != 1008611) {
		node* s = new node;
		s->data = x;
		s->lc = NULL;
		s->rc = NULL;
		insert(T, s);
	}
}


//��������������ĳ��Ԫ��ֵ
node*& BstSearch(node*& T, keytype x) {
	//TΪ��ǰ������ַ
	if (!T || x == T->data) { //��TΪ�ջ�T��ָ��ֵΪҪ��ѯ��xʱ������T
		return T;
	}
	//��x�ȵ�ǰ���ֵСʱ���������������ݹ���ң��������������ݹ����
	if (x < T->data) return BstSearch(T->lc, x);
	else return BstSearch(T->rc, x);
}

//��p��������������ʱ��ֱ��ǰ����ֱ��ǰ���ĸ���㣨par��
node* pre(node* p, node*& par) {
	par = p;
	p = p->lc;
	while (p->rc) {
		par = p;
		p = p->rc;
	}
	return p;//ֱ��ǰ����p�������е����ֵ
}

//������������ɾ���㷨
void remove(node*& T, keytype x) {
	node*& p = BstSearch(T, x);//��λ��ɾ���Ľ��
	if (p->lc == NULL && p->rc == NULL) {//����Ҷ�ӽ��
		delete p;
		p = NULL;
	}
	else if (p->lc == NULL && p->rc != NULL) { //��������Ϊ�գ�����������
		node* u = p;
		p = p->rc;
		delete u;
	}
	else if (p->rc == NULL && p->lc != NULL) {//��������Ϊ�գ����������գ�������������Գƴ���
		node* u = p;
		p = p->lc;
		delete u;
	}
	else if (p->lc != NULL && p->rc != NULL) {//��������������Ϊ�գ������ֱ��ǰ�����䶥��
		node* parOfPre;
		node* Pre = pre(p, parOfPre);//PreΪp��ֱ��ǰ����parOfPreΪֱ��ǰ���ĸ���
		//�������p��ֱ��ǰ��������������������������
		//��ֱ��ǰ���ĸ���㲻Ϊx�����ֱ�ӽ����������ӵ��������Һ�����
		if (parOfPre->data != x) {
			p->data = Pre->data;//��ֱ��ǰ����ֵ����p
			parOfPre->rc = Pre->lc;
		}
		else { //��ֱ��ǰ���ĸ����պ�Ϊx�������������ӵ�����㣨x��������
			p->data = Pre->data;//��ֱ��ǰ����ֵ����p
			parOfPre->lc = Pre->lc;
		}
		delete Pre;
	}
}

//�������ĸ߶ȣ�����AVL��
int updateHeight(node* p) {
	if (p == NULL) return 0;
	return (p->height = max(updateHeight(p->lc), updateHeight(p->rc)) + 1);
}


node* LLrotate(node* A) { //"LL"��ʧ��ĵ�����AΪ��Ͳ�ƽ����
	node* B = A->lc;
	A->lc = B->rc; //��B����������ΪA��������
	B->rc = A; //��A��ΪB���Һ���

	//���¸߶�
	updateHeight(A);
	updateHeight(B);
	return B;//���ص�������¸��ڵ�
}

node* RRrotate(node* A) {//"RR"��ʧ��ĵ�����AΪ��Ͳ�ƽ����
	node* B = A->rc;
	A->rc = B->lc; //��B����������ΪA��������
	B->lc = A; //��A��ΪB������

	//���¸߶�
	updateHeight(A);
	updateHeight(B);
	return B;//���ص�������¸��ڵ�
}

node* LRrotate(node* A) {//"LR"��ʧ��ĵ�����AΪ��Ͳ�ƽ����
	node* B = A->lc;
	node* C = B->rc;
	A->lc = C->rc;
	B->rc = C->lc;
	C->lc = B;
	C->rc = A;

	updateHeight(A);
	updateHeight(B);
	updateHeight(C);
	return C;
}

node* RLrotate(node* A) {//"RL"��ʧ��ĵ�����AΪ��Ͳ�ƽ����
	node* B = A->rc;
	node* C = B->lc;
	A->rc = C->lc;
	B->lc = C->rc;
	C->lc = A;
	C->rc = B;

	updateHeight(A);
	updateHeight(B);
	updateHeight(C);
	return C;
}

//�ж�ƽ��
bool isBalenced(node* root) {
	int a, b;
	if (root->lc) a = root->lc->height;
	else a = 0;
	if (root->rc) b = root->rc->height;
	else b = 0;
	return fabs(a - b) <= 1;
}

//AVL�Ĳ����㷨
node* AVLinsert(node*& root, keytype x) {
	if (root == NULL) {
		root = new node;
		root->data = x;
		root->lc = NULL;
		root->rc = NULL;
		root->height = 1;
		return root;
	}
	if (x > root->data) {//x�ȵ�ǰ�����󣬲�������������
		root->rc = AVLinsert(root->rc, x); //�������õ������ĸ���㸳ֵ���Һ���
		if (!isBalenced(root)) {
			if (x > root->rc->data) //"RR"��ʧ��
				root = RRrotate(root);
			else root = RLrotate(root);//"RL"��ʧ��
		}
	}
	else {//x�ȵ�ǰ�����С����������������
		root->lc = AVLinsert(root->lc, x);////�������õ������ĸ���㸳ֵ������
		if (!isBalenced(root)) {
			if (x < root->lc->data)//��LL����ʧ��
				root = LLrotate(root);
			else root = LRrotate(root);//��LR����ʧ��
		}
	}
	updateHeight(root);
	return root; //���ص�����ĸ��ڵ�
}

//�����ӡ
void PrePrint(node* root) {
	if (root) {
		cout << root->data << " ";
		PrePrint(root->lc);
		PrePrint(root->rc);
	}
}

//�����ӡ
void InPrint(node* root) {
	if (root) {
		InPrint(root->lc);
		cout << root->data << " ";
		InPrint(root->rc);
	}
}

//��ӡ������������
void printBST(node* root) {
	cout << "�������У�";
	PrePrint(root);
	cout << endl;
	cout << "�������У�";
	InPrint(root);
	cout << endl;
	cin.get();
}
