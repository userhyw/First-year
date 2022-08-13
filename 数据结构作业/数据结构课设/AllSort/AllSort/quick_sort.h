#pragma once
#include <iostream>
//全局变量记录比较次数，数据交换次数
long long quick_compare, quick_swap;
//快速排序----Quick_Sort
void quick_sort(int arr[], int left, int right)//参数传入两端的下标
{
	if (left >= right) {
		quick_compare++;
		return;
	}
	//int key = arr[left];
	//int begin = left;
	//int end = right;//代替左右下标，因为需要保留值

	while (left < right) {//新加对长子列经行迭代实现快速排序的部分
		int key = arr[left];
		int begin = left;
		int end = right;//代替左右下标，因为需要保留值

		while (begin != end) {
			while (begin < end && arr[end] >= key) {//不用移动元素，下标移动
				quick_compare += 2;
				end--;
			}
			if (end > begin) {
				quick_compare++;
				quick_swap++;
				arr[begin] = arr[end];
			}
			while (begin < end && arr[begin] <= key) {//不用移动元素，下标移动
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
		arr[begin] = key;//左右下标相遇的位置，存储中间轴的值
		if (begin - left < right - begin)
		{
			quick_sort(arr, left, begin - 1);//子表快速排序递归
			left = begin + 1;
		}
		else
		{
			quick_sort(arr, begin + 1, right);//子表快速排序递归
			right = begin - 1;
		}
		
	}
}
