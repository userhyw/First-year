#include <iostream>
#include<typeinfo>
using namespace std;

#define elementType int
#define elementTypeTwo char
#define MaxLen 100
#define NEWLINE cout << endl


class Stack
{
public:
    Stack(); //初始化
    void iclear();//初始化计数器
    bool iempty(); //判断栈空
    bool full(); //判断栈满
    template <class T> bool getTop(T &x);//取栈顶元素
    template <class T> bool  push(T x); //入栈
    void pop();//出栈
    void convert(int x, int y);//实现10进制向范围进制的转化
    bool imatch(char s[]);//判断括号是否正确匹配
    void AllList(elementTypeTwo input[], elementTypeTwo ioutput[], int len, int i, int j);//按123..n入栈的顺序求出栈可能序列

private:
    elementType data[MaxLen]; //存放栈元素
    elementTypeTwo dataTwo[MaxLen];//存放字符型型栈元素
    int top; //栈顶指针（数组下标）
    int icount;//计数次数
};

//初始化空栈
Stack::Stack()
{
    this->top = -1;
}

//初始化计数器
void Stack::iclear()
{
    this->icount = 0;
}

//检查栈是否为空
bool Stack::iempty()
{
    return (this->top == -1);
}

//检查栈是否满
bool Stack::full()
{
    return (this->top == MaxLen - 1);
}

//获得栈顶元素
template <class T>
bool Stack::getTop(T &x)
{
    if (this->iempty()){
        cout << "栈空！" <<endl;
        return false;
    }
    else{
        typeid (T) ==  typeid (elementTypeTwo) ? x =  this->dataTwo[top] : x = this->data[top];
        return true;
    }
}

//压栈，存入元素
template <class T>
bool Stack::push(T x)
{
    if (this->full()){
        cout << "栈满！" <<endl;
        return false;
    }
    else{
        this->top++;//存入元素、压栈
        typeid(T) == typeid(elementType) ? this->data[this->top] = x : this->dataTwo[this->top] = x;
        return true;
    }
}

void Stack::pop()
{
    if (this->iempty()){
        cout << "栈空！" << endl;
        return;
    }
    this->top--;
    return;
}

//存入10进制转换为其他进制的数字到栈中
void Stack::convert(int x, int y)
{
    if (y < 2 || y > 36){
        cout << "不符合题目要求！" << endl;
        return;
    }

    if (x < 0){
        x = -x;
    }

    while (x )
    {
        this->push(x % y);
        x /= y;
    }
}

//判断表达式中括号是否匹配
bool Stack::imatch(char *s)
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
void Stack::AllList(elementTypeTwo input[], elementTypeTwo ioutput[], int len, int i, int j)
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


















