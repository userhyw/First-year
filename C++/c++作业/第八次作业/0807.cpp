//*********************************************************
//File name	 : 0807
//Author  	 :he yang
//Date   	 : 01.11
//Student ID   :2021218148
//*********************************************************
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;
#define NEWLINE cout << endl

int main()
{
	double What;

	fstream fs("s.bin", ios::out | ios::binary | ios::trunc);

	srand(time(NULL));
	for (int i = 0; i < 86400; i++) {
		What = rand() + (double)rand() / RAND_MAX;
		cout << fixed << setprecision(4) << setw(12) << What << "      ";

		fs.write((char *)&What, sizeof(What));

		if (i % 7 == 0) {
			NEWLINE;
		}
	}
	fs.close();

	time_t std_now = time(0);
	struct tm* local;
	local = localtime(&std_now);
	long now = local->tm_hour * 3600 + local->tm_min * 60 + local->tm_sec;

	fstream ReadVaule("s.bin", ios::in | ios::binary);
	if(!ReadVaule.is_open()){
		cout << "程序书写文件错误！！！" << endl;
		return 1;
	}

	ReadVaule.seekg((now - 1) * sizeof(What), ios::beg);
	ReadVaule.read((char*)&What, sizeof(What));



	NEWLINE;
    cout << "当前时间为：" << now;
    NEWLINE;
    cout << "对应时间序列表为 ：" << What;
    NEWLINE;


    ReadVaule.close();
    system("pause");
	return 0;
}
