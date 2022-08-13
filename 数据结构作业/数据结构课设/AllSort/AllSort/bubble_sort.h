#pragma once
#include <iostream>
//全局变量记录比较次数，数据交换次数
int bubble_compare, bubble_swap;

//冒泡排序---bubble_sort
void bubble_sort(int arr[], int n)
{
	bool flage = false;
	for (int i = 0; i < n - 1; i++)
	{
		flage = false;
		bubble_compare++;//
		for (int j = i + 1; j < n; j++)
		{
			bubble_compare++;//
			if (arr[i] > arr[j])
			{
				flage = true;
				bubble_compare++;//
				bubble_swap++;//
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		if (flage == false) return;
	}
}
