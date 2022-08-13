#pragma once
#include <iostream>
//ȫ�ֱ�����¼�Ƚϴ��������ݽ�������
long long quick_compare, quick_swap;
//��������----Quick_Sort
void quick_sort(int arr[], int left, int right)//�����������˵��±�
{
	if (left >= right) {
		quick_compare++;
		return;
	}
	//int key = arr[left];
	//int begin = left;
	//int end = right;//���������±꣬��Ϊ��Ҫ����ֵ

	while (left < right) {//�¼ӶԳ����о��е���ʵ�ֿ�������Ĳ���
		int key = arr[left];
		int begin = left;
		int end = right;//���������±꣬��Ϊ��Ҫ����ֵ

		while (begin != end) {
			while (begin < end && arr[end] >= key) {//�����ƶ�Ԫ�أ��±��ƶ�
				quick_compare += 2;
				end--;
			}
			if (end > begin) {
				quick_compare++;
				quick_swap++;
				arr[begin] = arr[end];
			}
			while (begin < end && arr[begin] <= key) {//�����ƶ�Ԫ�أ��±��ƶ�
				quick_compare += 2;
				begin++;
			}
			if (begin < end) {
				quick_compare++;
				quick_swap++;
				arr[end] = arr[begin];
			}
			quick_compare++;
		}
		quick_swap++;
		arr[begin] = key;//�����±�������λ�ã��洢�м����ֵ
		if (begin - left < right - begin)
		{
			quick_sort(arr, left, begin - 1);//�ӱ��������ݹ�
			left = begin + 1;
		}
		else
		{
			quick_sort(arr, begin + 1, right);//�ӱ��������ݹ�
			right = begin - 1;
		}
		
	}
}
