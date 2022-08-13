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
    Stack(); //��ʼ��
    void iclear();//��ʼ��������
    bool iempty(); //�ж�ջ��
    bool full(); //�ж�ջ��
    template <class T> bool getTop(T &x);//ȡջ��Ԫ��
    template <class T> bool  push(T x); //��ջ
    void pop();//��ջ
    void convert(int x, int y);//ʵ��10������Χ���Ƶ�ת��
    bool imatch(char s[]);//�ж������Ƿ���ȷƥ��
    void AllList(elementTypeTwo input[], elementTypeTwo ioutput[], int len, int i, int j);//��123..n��ջ��˳�����ջ��������

private:
    elementType data[MaxLen]; //���ջԪ��
    elementTypeTwo dataTwo[MaxLen];//����ַ�����ջԪ��
    int top; //ջ��ָ�루�����±꣩
    int icount;//��������
};

//��ʼ����ջ
Stack::Stack()
{
    this->top = -1;
}

//��ʼ��������
void Stack::iclear()
{
    this->icount = 0;
}

//���ջ�Ƿ�Ϊ��
bool Stack::iempty()
{
    return (this->top == -1);
}

//���ջ�Ƿ���
bool Stack::full()
{
    return (this->top == MaxLen - 1);
}

//���ջ��Ԫ��
template <class T>
bool Stack::getTop(T &x)
{
    if (this->iempty()){
        cout << "ջ�գ�" <<endl;
        return false;
    }
    else{
        typeid (T) ==  typeid (elementTypeTwo) ? x =  this->dataTwo[top] : x = this->data[top];
        return true;
    }
}

//ѹջ������Ԫ��
template <class T>
bool Stack::push(T x)
{
    if (this->full()){
        cout << "ջ����" <<endl;
        return false;
    }
    else{
        this->top++;//����Ԫ�ء�ѹջ
        typeid(T) == typeid(elementType) ? this->data[this->top] = x : this->dataTwo[this->top] = x;
        return true;
    }
}

void Stack::pop()
{
    if (this->iempty()){
        cout << "ջ�գ�" << endl;
        return;
    }
    this->top--;
    return;
}

//����10����ת��Ϊ�������Ƶ����ֵ�ջ��
void Stack::convert(int x, int y)
{
    if (y < 2 || y > 36){
        cout << "��������ĿҪ��" << endl;
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

//�жϱ��ʽ�������Ƿ�ƥ��
bool Stack::imatch(char *s)
{
    //dataTwo
    bool flage = true;
    while (*s)
    {
        char c = *s;
        if (c == '[' || c == '{' || c == '(')//������ȫ��ջ
            {
                this->push(c);
            }
        else if (c == ']' || c == '}' || c == ')')//�������������ϳ�ջ
            {
                char x;
                this->getTop(x);
                if (c == x + 1 || c == x + 2)//����ascii��ƥ������
                {// () 28��29      [] 91��93    {} 123��125
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

    //��ջ����
    while (!this->iempty())
    {
        this->pop();
    }
    return false;
}

//��123..n��ջ��˳�����ջ��������, ��Ϊ��������Ҫע������Ĳ���
void Stack::AllList(elementTypeTwo input[], elementTypeTwo ioutput[], int len, int i, int j)
{
    //i, j-----��Ӧ��ջ���кͳ�ջ���е������±�
    elementTypeTwo x;

    //ջ�գ��ҵõ�һ����ջ����
    if (this->iempty() && j >= len)
    {
        //����ͬʱ��Ϊ�ݹ�ĳ���
        this->icount++;

        cout << "��  "  << this->icount << "     ����Ϊ��";
        int m_a = 0;
       while (m_a < j)
       {
           cout << ioutput[m_a];
           m_a++;
       }
       NEWLINE;
       return;
    }
    else if (!this->iempty() && i < len)//ջ���գ�����ջ���л���Ԫ��
    {
        //��ʱ��ÿһ����ջ�ڵ�Ԫ�ض��ԣ�Ҫô��ջҪô��ջ
        this->getTop(x);
        this->pop();
        ioutput[j] = x;
        j++;
        AllList(input, ioutput, len, i, j);

        j--;//����֮ǰ��״̬
        this->push(x);

        this->push(input[i]);//��ջ
        i++;
        AllList(input, ioutput, len, i, j);

        i--;//�ָ�����ջ֮ǰ��״̬
        this->pop();
    }
    else if (!this->iempty() && i >= len)//��ջ��Ϊ�գ� ��ջ�����Ѿ����ˣ���ʱֻ�ܳ�ջ
    {
        this->getTop(x);
        this->pop();
        ioutput[j] = x;
        j++;
        AllList(input, ioutput, len, i, j);

        j--;
        this->push(x);//�ָ���֮ǰ��״̬
    }
    else if (this->iempty() && i < len)//ջ�գ�������ջ���л�û���꣬��ʱֻ����ջ
    {
        this->push(input[i]);
        i++;
        AllList(input, ioutput, len, i, j);

        i--;
        this->pop();
    }

}


















