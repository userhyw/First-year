#include <iostream>
#include<typeinfo>
using namespace std;

#define NEWLINE cout << endl
#define elementType int
#define elementTypeTwo char

typedef struct inode
{
    elementTypeTwo datatwo;
    elementType data;
    struct inode *Next;

}node;

class LinkStack
{
public:
    LinkStack();//初始化栈
    void iclear();//初始化计数器
    bool iempty(); //判断栈空
    template<class T>  bool getTop(T &x); //取栈顶元素
    template<class T>  bool push(T x); //入栈
    int pop(); //出栈
    void convert(int x, int y);//实现10进制向范围进制的转化
    bool imatch(char s[]);//判断括号是否正确匹配
    void AllList(elementTypeTwo input[], elementTypeTwo ioutput[], int len, int i, int j);//按123..n入栈的顺序求出栈可能序列
    void iright(elementTypeTwo input[], elementTypeTwo ioutput[], int n);//出栈序列是否合法

private:
    node *head;
    int icount;

};

//初始化栈
LinkStack::LinkStack()
{
    this->head = NULL;
}

void LinkStack::iclear()
{
    this->icount = 0;
}

//判断栈是否为空
bool LinkStack::iempty()
{
    return (this->head == NULL) ? true : false;
}

//栈顶元素获取
template<class T>
bool LinkStack::getTop(T &x)
{
    if (this->iempty()) return false;
    (typeid(T) == typeid(elementTypeTwo)) ? x = this->head->datatwo : x = this->head->data;
    return true;
}

//压栈
template<class T>
bool LinkStack::push(T x)
{
    node *p = new node;
    (typeid(T) == typeid(elementTypeTwo)) ? p->datatwo = x : p->data = x;
    p->Next = this->head;
    this->head = p;
}

//出栈
int LinkStack::pop()
{
    if (this->iempty()) return -1008611;
    node *p = this->head;
    this->head = this->head->Next;
    delete p;
    return 0;
}

//存入10进制转换为其他进制的数字到栈中
void LinkStack::convert(int x, int y)
{
    if (y < 2 || y > 36){
        cout << "不符合题目要求！" << endl;
        return;
    }

    if (x < 0){
        x = -x;
    }

    while (x)
    {
        this->push(x % y);
        x /= y;
    }
}

//判断表达式中括号是否匹配
bool LinkStack::imatch(char *s)
{
    //dataTwo
    bool flage = true;
    while (*s)
    {
        char c = *s;
        if (c == '[' || c == '{' || c == '(')//左括号全入栈
            {
                this->push(c);
            }
        else if (c == ']' || c == '}' || c == ')')//遇到右括号马上出栈
            {
                char x;
                this->getTop(x);
                if (c == x + 1 || c == x + 2)//利用ascii来匹配括号
                {// () 28、29      [] 91、93    {} 123、125
                    this->pop();
                }
                else{
                    flage == false;
                    break;
                }
            }
        s++;
    }

    if (flage){
        if (this->iempty()){
            return true;
        }
    }

    //将栈弹空
    while (!this->iempty())
    {
        this->pop();
    }
    return false;
}

//按123..n入栈的顺序求出栈可能序列, 因为是用数组要注意输入的操作
void LinkStack::AllList(elementTypeTwo input[], elementTypeTwo ioutput[], int len, int i, int j)
{
    //i, j-----对应入栈序列和出栈序列的数组下标
    elementTypeTwo x;

    //栈空，且得到一个出栈序列
    if (this->iempty() && j >= len)
    {
        //这里同时作为递归的出口
        this->icount++;

        cout << "第  "  << this->icount << "     序列为：";
        int m_a = 0;
       while (m_a < j)
       {
           cout << ioutput[m_a];
           m_a++;
       }
       NEWLINE;
       return;
    }
    else if (!this->iempty() && i < len)//栈不空，且入栈序列还有元素
    {
        //此时对每一个在栈内的元素而言，要么出栈要么入栈
        this->getTop(x);
        this->pop();
        ioutput[j] = x;
        j++;
        AllList(input, ioutput, len, i, j);

        j--;//返回之前的状态
        this->push(x);

        this->push(input[i]);//入栈
        i++;
        AllList(input, ioutput, len, i, j);

        i--;//恢复到入栈之前的状态
        this->pop();
    }
    else if (!this->iempty() && i >= len)//当栈不为空， 入栈序列已经完了，此时只能出栈
    {
        this->getTop(x);
        this->pop();
        ioutput[j] = x;
        j++;
        AllList(input, ioutput, len, i, j);

        j--;
        this->push(x);//恢复到之前的状态
    }
    else if (this->iempty() && i < len)//栈空，但是入栈序列还没有完，此时只能入栈
    {
        this->push(input[i]);
        i++;
        AllList(input, ioutput, len, i, j);

        i--;
        this->pop();
    }

}

//出栈序列是否合法
void LinkStack::iright(elementTypeTwo input[], elementTypeTwo ioutput[], int n)
{
    int i = 0, j = 0;
    elementTypeTwo x;

    while (i < n){
        this->push(input[i]);
        while (!this->iempty()){
        this->getTop(x);
        if (x == ioutput[j]){
            this->pop();
            j++;
        }
        else{
            break;
        }
        }
        i++;
    }

    if (j == n && i == n && this->iempty()){
        cout << "！的对是你" << endl;
        return;
    }
    else{
        cout << "这是不合法的出栈序列" << endl;
    }
}


