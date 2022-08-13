#pragma once
#include <iostream>
//�鲢����---merge_sort

//ȫ�ֱ�����¼�Ƚϴ��������ݽ�������
int merge_compare, merge_swap;
//�ϲ���
void merge(int arr[], int tempArr[], int left, int mid, int right)
{
	int L_m = left, R_m = mid + 1, temp = left;//����ĵ�һ��Ԫ�ص��±꣬ temp��¼д���±��Ԫ�ص��±�

	//�ϲ����������������д���µ�����tempArr��
	while (L_m <= mid && R_m <= right)
	{
		if (arr[L_m] < arr[R_m])tempArr[temp++] = arr[L_m++];
		else 
			tempArr[temp++] = arr[R_m++];
		merge_compare += 3;
		merge_swap++;
	}

	//���δ��
	while (L_m <= mid)
	{
		tempArr[temp++] = arr[L_m++];
		merge_swap++;
		merge_compare++;
	}
	//�ұ�δ��
	while (R_m <= right)
	{
		tempArr[temp++] = arr[R_m++];
		merge_swap++;
		merge_compare++;
	}

	//�������ƶ���������
	while (left <= right)
	{
		merge_swap++;
		merge_compare++;
		arr[left] = tempArr[left];
		left++;
	}
}

//�ݹ黮���ӱ�
void msort(int arr[], int tempArr[], int left, int right)
{
	if (left < right)//��ĳ��ȴ���1
	{
		merge_compare++;
		int mid = (left + right) / 2;//���ֻ���
		msort(arr, tempArr, left, mid);//�����
		msort(arr, tempArr, mid + 1, right);//�Ұ�������
		merge(arr, tempArr, left, mid, right);//�ϲ��ӱ�
	}
}


//�鲢���
void merge_sort(int arr[], int n)
{
	//����ȳ�����
	int* tempArr = new int[n];
	if (tempArr)
	{
		msort(arr, tempArr, 0, n - 1);
		delete []tempArr;
	}
	else return;
}
