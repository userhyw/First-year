#pragma once
#include <iostream>
//堆排序-----Heap_Sort
//全局变量记录比较次数，数据交换次数
int heap_compare, heap_swap;
//交换值的函数
void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//调整堆的操作
void heapify(int tree[], int n, int i)//n为结点数目，亦为数组元素数目。i为从这个顶点开始调整堆
{
	if (i >= n)
	{
		heap_compare++;
		return;//递归出口
	}
		
	int c1 = 2 * i + 1;//第一个单元仍然存储元素
	int c2 = 2 * i + 2;
	int imax = i;//最大值的下标记录

	if (c1 < n && tree[c1] > tree[imax])
	{
		imax = c1;
		heap_compare += 2;
		heap_swap++;
	}
	if (c2 < n && tree[c2] > tree[imax])
	{
		imax = c2;//找出最大值的下标
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

//创建堆
void build_heap(int tree[], int n)
{
	int last_node = n - 1;
	int parent = (last_node - 1) / 2;
	for (int i = parent; i >= 0; i--)
	{
		heap_compare++;
		heapify(tree, n, i);//从i开始倒着往上减着去做堆调整
	}
}

//排序堆
void heap_sort(int tree[], int n)
{
	build_heap(tree, n);//首先创建堆
	for (int i = n - 1; i >= 0; i--)
	{
		heap_compare++;
		swap(tree, i, 0);//交换堆顶值到末尾
		heapify(tree, i, 0);//调整堆顶
	}
}

