#pragma once
#include <iostream>
//全局变量记录比较次数，数据交换次数
int shell_compare, shell_swap;
//希尔排序----shell_sort
void shell_sort(int arr[], int n)
{
	int i, j, inc, key;
	for (inc = n / 2; inc > 0; inc /= 2)//每组间距---直到间距为1
	{
		shell_compare++;
		//每一趟都插入排序
		for (i = inc; i < n; i++)//不是一次完成一组，而是根据间隔来。
		{
			shell_compare++;
			key = arr[i];
			for (j = i; j >= inc && key < arr[j - inc]; j -= inc)
			{
				arr[j] = arr[j - inc];//找出空位
				shell_compare += 2;
				shell_swap++;
			}
			arr[j] = key;//写入值
			shell_swap++;
		}
	}
}
