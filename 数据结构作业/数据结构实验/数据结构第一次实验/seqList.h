#pragma once
#include <iostream>
using namespace std;

#define elementType int
#define Maxlen 1000
#define NEWLINE cout << endl

class SeqList
{
public:
	SeqList();//初始化空表
	int length(); //求表长度（元素个数）
	bool getElement(int i, elementType& x); //取元素
	int locate(elementType x); //定位元素
	int listInsert(int i, elementType x); //插入
	int listDelete(int i); //删除
	int Printf();//遍历输出当前表内容
	int listInsert(elementType x);//在尾部插入元素;
	void listInsert(bool, elementType x);//插入元素，若是递增表不改变递增性质
    void Separation(SeqList &L1, SeqList &L2);//传入两个表接奇偶数
    void add(SeqList &L1, SeqList &L2);//递增表公共元素加到新表
    int listDelete(bool); //删除递增有序表的重复元素
    void DeleteAll(void);//清空表

private:
elementType data[Maxlen];
 int listLen;
};

//清空表
void SeqList::DeleteAll(void)
{
    this->listLen = 0;
}

//初始化空表
SeqList ::SeqList()
{
    this->listLen = 0;
}

//求表长度
 int SeqList::length()
{
	return this->listLen;
}

//取元素
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

//返回下标
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

//插入元素
 int SeqList::listInsert(int i, elementType x)
{
	int j = -1;
	if (i >= 0 && i <= this->listLen)
    {
        //元素后移
        for (int k = this->listLen - 1; k >= i; k--){
            this->data[k + 1] = this->data[k];
        }
        //插入元素
        this->data[i] = x;

        //改变长度
        this->listLen++;

        j = 1;
    }
    return j;
}

//删除第i的元素
 int SeqList::listDelete(int i)
{
    int j = -1;
    //直接前移动覆盖即可
    if (i > 0 && i <= this->listLen)
    {
        for (int j = i - 1; j < this->listLen; j++){
            this->data[j] = this->data[j + 1];
        }
        //长度-1;
        this->listLen--;

        j = 1;
    }

    return j;
}

//打印表中元素
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

//在尾部插入元素
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

//递增插入，bool为占位参数
void SeqList::listInsert(bool, elementType x)
{
    int k = -1;//记录查找的下标
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

//拆奇数偶数到两个表中
void SeqList::Separation(SeqList &L1, SeqList &L2)
{
    //遍历拆分即可
    for (int i = 0; i < this->listLen; i++){
        if (this->data[i] % 2 == 0){
            L1.listInsert(this->data[i]);
        }
        else{
            L2.listInsert(this->data[i]);
        }
    }
}

//递增表的相同元素
void SeqList::add(SeqList &L1, SeqList &L2)
{
    int m = L1.listLen;
    int n = L2.listLen;
    int  i = 0, j = 0;
    this->listLen = 0;//强制变为新表
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

//删除递增表的重复元素
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
    //循环结束后改变长度
    this->listLen = ++j;
    return j;
}

