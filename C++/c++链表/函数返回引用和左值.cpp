#include <iostream>

using namespace std;
int &text01()
{
	static int a = 10;
	return a;
}

//���õı��ʾ���һ��ָ�볣����ָ��ķ����޷��޸�;
// �ڲ�������д��һ������ָ��;
//ָ�볣�����ɸ��ģ���Ҳ˵����Ϊʲô���Ǵ�������Ҳ�����Ը���;
// int * const c = &a;
int main(void)
{
	//��̬�����������ǿ���ͨ��������ȫ���ص�
	//�ڳ����õ�һ��������Ҫ�ı�ʱ���ܷ��㡣
	int &c = text01();
	cout << c << endl;
	cout << c << endl;

	//��������ֵ
	text01() = 1000;
	cout << c << endl;
	cout << c << endl;
	system("pause");
	return 0;
}