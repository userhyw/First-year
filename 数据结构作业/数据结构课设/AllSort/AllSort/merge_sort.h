#pragma once
#include <iostream>
//归并排序---merge_sort

//全局变量记录比较次数，数据交换次数
int merge_compare, merge_swap;
//合并表
void merge(int arr[], int tempArr[], int left, int mid, int right)
{
	int L_m = left, R_m = mid + 1, temp = left;//两表的第一个元素的下标， temp记录写入新表的元素的下标

	//合并递增有序的两个表，写入新的数组tempArr中
	while (L_m <= mid && R_m <= right)
	{
		if (arr[L_m] < arr[R_m])tempArr[temp++] = arr[L_m++];
		else 
			tempArr[temp++] = arr[R_m++];
		merge_compare += 3;
		merge_swap++;
	}

	//左表未完
	while (L_m <= mid)
	{
		tempArr[temp++] = arr[L_m++];
		merge_swap++;
		merge_compare++;
	}
	//右表未完
	while (R_m <= right)
	{
		tempArr[temp++] = arr[R_m++];
		merge_swap++;
		merge_compare++;
	}

	//把数据移动到数组中
	while (left <= right)
	{
		merge_swap++;
		merge_compare++;
		arr[left] = tempArr[left];
		left++;
	}
}

//递归划分子表
void msort(int arr[], int tempArr[], int left, int right)
{
	if (left < right)//表的长度大于1
	{
		merge_compare++;
		int mid = (left + right) / 2;//二分划分
		msort(arr, tempArr, left, mid);//左半区
		msort(arr, tempArr, mid + 1, right);//右半区划分
		merge(arr, tempArr, left, mid, right);//合并子表
	}
}


//归并入口
void merge_sort(int arr[], int n)
{
	//分配等长数组
	int* tempArr = new int[n];
	if (tempArr)
	{
		msort(arr, tempArr, 0, n - 1);
		delete []tempArr;
	}
	else return;
}
