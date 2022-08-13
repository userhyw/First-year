#pragma once
#include <iostream>
using namespace std;

#define elementType int
#define Maxlen 1000
#define NEWLINE cout << endl

class SeqList
{
public:
	SeqList();//��ʼ���ձ�
	int length(); //����ȣ�Ԫ�ظ�����
	bool getElement(int i, elementType& x); //ȡԪ��
	int locate(elementType x); //��λԪ��
	int listInsert(int i, elementType x); //����
	int listDelete(int i); //ɾ��
	int Printf();//���������ǰ������
	int listInsert(elementType x);//��β������Ԫ��;
	void listInsert(bool, elementType x);//����Ԫ�أ����ǵ������ı��������
    void Separation(SeqList &L1, SeqList &L2);//�������������ż��
    void add(SeqList &L1, SeqList &L2);//��������Ԫ�ؼӵ��±�
    int listDelete(bool); //ɾ�������������ظ�Ԫ��
    void DeleteAll(void);//��ձ�

private:
elementType data[Maxlen];
 int listLen;
};

//��ձ�
void SeqList::DeleteAll(void)
{
    this->listLen = 0;
}

//��ʼ���ձ�
SeqList ::SeqList()
{
    this->listLen = 0;
}

//�����
 int SeqList::length()
{
	return this->listLen;
}

//ȡԪ��
 bool SeqList::getElement(int i, elementType &x)
{
    if (i > 0 && i <=  this->listLen){
        x = this->data[i - 1];
        return true;
    }
    else{
        return false;
    }

}

//�����±�
 int SeqList::locate(elementType x)
{
    int j = -1;
    for (int i = 0; i < this->listLen; i++){
        if (this->data[i] == x){
            j = i;
            break;
        }
    }
    return j;
}

//����Ԫ��
 int SeqList::listInsert(int i, elementType x)
{
	int j = -1;
	if (i >= 0 && i <= this->listLen)
    {
        //Ԫ�غ���
        for (int k = this->listLen - 1; k >= i; k--){
            this->data[k + 1] = this->data[k];
        }
        //����Ԫ��
        this->data[i] = x;

        //�ı䳤��
        this->listLen++;

        j = 1;
    }
    return j;
}

//ɾ����i��Ԫ��
 int SeqList::listDelete(int i)
{
    int j = -1;
    //ֱ��ǰ�ƶ����Ǽ���
    if (i > 0 && i <= this->listLen)
    {
        for (int j = i - 1; j < this->listLen; j++){
            this->data[j] = this->data[j + 1];
        }
        //����-1;
        this->listLen--;

        j = 1;
    }

    return j;
}

//��ӡ����Ԫ��
int SeqList::Printf()
{
    int j = -1;
    if (this->listLen > 0){
        for (int i = 0; i < this->listLen; i++)
        {
            cout << this->data[i] << " ";
        }
//        NEWLINE;
        j = 1;
    }
    return j;
}

//��β������Ԫ��
int SeqList::listInsert(elementType x)
{
    int j = -1;
    if (this->listLen == Maxlen){
        return j;
    }

    this->data[this->listLen] = x;
    this->listLen++;
    return 1;
}

//�������룬boolΪռλ����
void SeqList::listInsert(bool, elementType x)
{
    int k = -1;//��¼���ҵ��±�
    for (int i = 0; i < this->listLen; i++){
        if (this->data[i] > x){
            k = i;
            break;
        }
    }

    if (k != -1){
        this->listInsert(k, x);
    }
    else{
        this->listInsert(this->listLen, x);
    }
}

//������ż������������
void SeqList::Separation(SeqList &L1, SeqList &L2)
{
    //������ּ���
    for (int i = 0; i < this->listLen; i++){
        if (this->data[i] % 2 == 0){
            L1.listInsert(this->data[i]);
        }
        else{
            L2.listInsert(this->data[i]);
        }
    }
}

//���������ͬԪ��
void SeqList::add(SeqList &L1, SeqList &L2)
{
    int m = L1.listLen;
    int n = L2.listLen;
    int  i = 0, j = 0;
    this->listLen = 0;//ǿ�Ʊ�Ϊ�±�
    while (i < m && j < n){
        if (L1.data[i] == L2.data[j]){
            this->listInsert(L1.data[i]);
            i++;
            j++;
        }
        else if (L1.data[i] > L2.data[j]){
            j++;
        }
        else{
            i++;
        }
    }
}

//ɾ����������ظ�Ԫ��
int SeqList::listDelete(bool)
{
    int j = 0, i = 1;
    while (i < this->listLen){
        if (this->data[j] != this->data[i]){
            j++;
            this->data[j] = this->data[i];
            i++;
        }
        else{
            i++;
        }
    }
    //ѭ��������ı䳤��
    this->listLen = ++j;
    return j;
}

