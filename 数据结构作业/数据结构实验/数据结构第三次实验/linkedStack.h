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
    LinkStack();//��ʼ��ջ
    void iclear();//��ʼ��������
    bool iempty(); //�ж�ջ��
    template<class T>  bool getTop(T &x); //ȡջ��Ԫ��
    template<class T>  bool push(T x); //��ջ
    int pop(); //��ջ
    void convert(int x, int y);//ʵ��10������Χ���Ƶ�ת��
    bool imatch(char s[]);//�ж������Ƿ���ȷƥ��
    void AllList(elementTypeTwo input[], elementTypeTwo ioutput[], int len, int i, int j);//��123..n��ջ��˳�����ջ��������
    void iright(elementTypeTwo input[], elementTypeTwo ioutput[], int n);//��ջ�����Ƿ�Ϸ�

private:
    node *head;
    int icount;

};

//��ʼ��ջ
LinkStack::LinkStack()
{
    this->head = NULL;
}

void LinkStack::iclear()
{
    this->icount = 0;
}

//�ж�ջ�Ƿ�Ϊ��
bool LinkStack::iempty()
{
    return (this->head == NULL) ? true : false;
}

//ջ��Ԫ�ػ�ȡ
template<class T>
bool LinkStack::getTop(T &x)
{
    if (this->iempty()) return false;
    (typeid(T) == typeid(elementTypeTwo)) ? x = this->head->datatwo : x = this->head->data;
    return true;
}

//ѹջ
template<class T>
bool LinkStack::push(T x)
{
    node *p = new node;
    (typeid(T) == typeid(elementTypeTwo)) ? p->datatwo = x : p->data = x;
    p->Next = this->head;
    this->head = p;
}

//��ջ
int LinkStack::pop()
{
    if (this->iempty()) return -1008611;
    node *p = this->head;
    this->head = this->head->Next;
    delete p;
    return 0;
}

//����10����ת��Ϊ�������Ƶ����ֵ�ջ��
void LinkStack::convert(int x, int y)
{
    if (y < 2 || y > 36){
        cout << "��������ĿҪ��" << endl;
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

//�жϱ��ʽ�������Ƿ�ƥ��
bool LinkStack::imatch(char *s)
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
void LinkStack::AllList(elementTypeTwo input[], elementTypeTwo ioutput[], int len, int i, int j)
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

//��ջ�����Ƿ�Ϸ�
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
        cout << "���Ķ�����" << endl;
        return;
    }
    else{
        cout << "���ǲ��Ϸ��ĳ�ջ����" << endl;
    }
}


