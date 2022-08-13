#pragma once
#include <iostream>
//������-----Heap_Sort
//ȫ�ֱ�����¼�Ƚϴ��������ݽ�������
int heap_compare, heap_swap;
//����ֵ�ĺ���
void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//�����ѵĲ���
void heapify(int tree[], int n, int i)//nΪ�����Ŀ����Ϊ����Ԫ����Ŀ��iΪ��������㿪ʼ������
{
	if (i >= n)
	{
		heap_compare++;
		return;//�ݹ����
	}
		
	int c1 = 2 * i + 1;//��һ����Ԫ��Ȼ�洢Ԫ��
	int c2 = 2 * i + 2;
	int imax = i;//���ֵ���±��¼

	if (c1 < n && tree[c1] > tree[imax])
	{
		imax = c1;
		heap_compare += 2;
		heap_swap++;
	}
	if (c2 < n && tree[c2] > tree[imax])
	{
		imax = c2;//�ҳ����ֵ���±�
		heap_compare += 2;
		heap_swap++;
	}
	
	if (imax != i)
	{
		heap_compare++;
		heap_swap++;
		swap(tree, imax, i);
		heapify(tree, n, imax);
	}
}

//������
void build_heap(int tree[], int n)
{
	int last_node = n - 1;
	int parent = (last_node - 1) / 2;
	for (int i = parent; i >= 0; i--)
	{
		heap_compare++;
		heapify(tree, n, i);//��i��ʼ�������ϼ���ȥ���ѵ���
	}
}

//�����
void heap_sort(int tree[], int n)
{
	build_heap(tree, n);//���ȴ�����
	for (int i = n - 1; i >= 0; i--)
	{
		heap_compare++;
		swap(tree, i, 0);//�����Ѷ�ֵ��ĩβ
		heapify(tree, i, 0);//�����Ѷ�
	}
}

