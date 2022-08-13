#pragma once
typedef int keytype;

#include<cstdio>
#include<iostream>
using namespace std;



typedef struct searchList {
	keytype key;
} elementType;

int bin_search(elementType A[], int n, keytype x) {
	int cnt = 0; //��¼�Ƚϴ���
	int mid, low = 0, high = n - 1; //�������˳�ʼ��
	while (low <= high) {//���ֲ���
		mid = (low + high) / 2;
		printf("��%d�αȽϵ�Ԫ�أ��±꣩��%d��%d��\n", ++cnt, A[mid].key, mid);
		if (x == A[mid].key) return mid;
		else if (x < A[mid].key) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}
