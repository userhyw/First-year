#pragma once
#include <iostream>
//ȫ�ֱ�����¼�Ƚϴ��������ݽ�������
int shell_compare, shell_swap;
//ϣ������----shell_sort
void shell_sort(int arr[], int n)
{
	int i, j, inc, key;
	for (inc = n / 2; inc > 0; inc /= 2)//ÿ����---ֱ�����Ϊ1
	{
		shell_compare++;
		//ÿһ�˶���������
		for (i = inc; i < n; i++)//����һ�����һ�飬���Ǹ��ݼ������
		{
			shell_compare++;
			key = arr[i];
			for (j = i; j >= inc && key < arr[j - inc]; j -= inc)
			{
				arr[j] = arr[j - inc];//�ҳ���λ
				shell_compare += 2;
				shell_swap++;
			}
			arr[j] = key;//д��ֵ
			shell_swap++;
		}
	}
}
