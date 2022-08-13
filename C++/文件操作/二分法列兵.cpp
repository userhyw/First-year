
//*********************************************************
//File name	 : GF211427.cpp
//Author  	 : 郭禹颉
//Date   	 :  2021.12.10
//Student ID   : 2021218130
//*********************************************************

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void Sort(int* p, int n)
{
	int iTemp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[i] < p[j])
			{
				iTemp = p[i];
				p[i] = p[j];
				p[j] = iTemp;
			}
		}
	}
}

bool Seek(int* q, int n, int iSel, int &iMid)
{
	int iTop, iBot;
	iTop = 0;
	iBot = n - 1;
	while (iTop <= iBot)
	{
		
		iMid = (iTop + iBot) / 2;               //二分
		if (iSel == q[iMid])
		{
			
			return true;                       //
		}
		else if (iSel > q[iMid])
		{
			iBot = iMid - 1;
		}                                      //调整底
		else
		{
			iTop = iMid + 1;
		}                                      //调整顶
	}
	return false;
}


int main()
{
	int a[20] = { 0 };
	srand(int(time(0)));
	for (int i = 0; i < 20; i++)
	{
		a[i] = rand();
	}

	cout << " The randomly generated array is : " << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << " ";
	}

	Sort(a, 20);

	cout << endl << endl << "The descending array is : " << endl;

	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << " ";
	}

	int iSel, iMid;
	iMid = 0;
	cout << endl << endl << "Tnput one numble : ";
	cin >> iSel;

	bool iFlag = Seek(a, 20, iSel, iMid);
	if (iFlag == true)
	{
		cout << "After sorted , " << iSel << " in the " << iMid << endl;
	}
	else
	{
		cout << iSel << " is not in the array ! " << endl;
	}

	return 0;
}
