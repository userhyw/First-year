#include<iostream>
using namespace std;
#define elementType int
#define NEWLINE cout << endl

//��װ��Ҫ�Ľṹ��
 struct node
{
    elementType data;
    node* Next;
};

//��װ������
class LinkedList
{
public:
    LinkedList(); //��ʼ��������
    void ReLinkedList();//��պ��ٴ�ʹ�õĳ�ʼ��
    int length(); //�������ȣ��������
    node* Rehead(bool);//��õ�һ��Ԫ�صĵ�ַ//��������Ϊ�˰�ȫ
    node* ReheadReall(bool);//����ͷָ�������޸�
    bool getElement(int i, elementType &x); //�����ȡԪ��
    node* locate(elementType x); //����Ԫ�أ�����Ŀ��ָ��
    bool listInsert(int i, elementType x);//�ڵ�i�����λ�ò���ֵΪx�Ľ��
    void listInsert(bool, elementType x);//��������С����x
    bool listDelete(int i);//ɾ����i��Ԫ��
    int listDeleteSame(bool);//ɾ�������ظ�Ԫ��
    void createListR(); //β�巨����������
    void createListH(); //ͷ�巨����������
    void print(); //��ӡ������Ԫ��
    void destroy(); //��������node��㣬�����ڴ�й©, �˺�������Ҳ���Է�������������ɡ�
    void apart(LinkedList &L1, LinkedList &L2);//��������ż���ֿ��ŵ������±�
    void allpart(LinkedList &L1, LinkedList &L2);//��õ�������Ĺ���Ԫ��
    void disApart( LinkedList &L2);//������������ǹ���Ԫ��֮��

private:
    node * head; //������ͷָ�롣node�������ṹ�嶨��
};


//��ʼ��������
LinkedList::LinkedList()
{
    head = new node;//����ͷ���
    head->Next = NULL;
}

//��պ��ٴ�ʹ�õĳ�ʼ��
void LinkedList::ReLinkedList()
{
    if (this->head == NULL){
        head = new node;//����ͷ���
        head->Next = NULL;
    }
}

//���ص�һ��Ԫ�صĵ�ַ
node* LinkedList::Rehead(bool)
{
    return this->head->Next;
}

//����ͷָ��ĵ�ַ�������޸�ͷָ��
node* LinkedList::ReheadReall(bool)
{
    return (this->head);
}

//����������
int LinkedList::length()
{
    node *p = this->head->Next;
    int len = 0;
    while (p != NULL){//�������ؼ���
        p = p->Next;
        len++;
    }
    return len;
}

//����Ż��Ԫ��
bool LinkedList::getElement(int i, elementType& x)
{
    if(i < 0){
        return false;
    }

    node *p = this->head->Next;
    int j = 1;

    while (p != NULL){
            if (j == i){//�ҵ�Ԫ�ؼ��˳�ѭ��
                break;
            }
            p = p->Next;
            j++;
    }

    if (j == i){//�ж��Ƿ��ҵ���Ԫ��
        x = p->data;
        return true;
    }
    else{
        return false;
    }

}

//����Ԫ�أ��ҵ����ؽ��ָ��
node* LinkedList::locate(elementType x)
{
    bool flage = false;//�ж��Ƿ��ҵ���Ԫ��
    node *p = this->head->Next;
    while (p != NULL){
        if (p->data == x){
            flage = true;
            break;
        }
        p = p->Next;
    }

    if (flage){
        return p;
    }
    else{
        return NULL;
    }

}

//�ڵ�i�����λ�ò���ֵΪx�Ľ��
bool LinkedList::listInsert(int i, elementType x)
{
    if (i < 0){
        return false;
    }
    this->ReLinkedList();//�ٴ�ʹ�ó�ʼ��

    bool flage = false;//�ж��Ƿ����
    int j = 0;//��¼�±�
    node *p = this->head;//���ǲ�����ǰ��

    while(p != NULL){
        if (j == i){//�ҵ�ǰ��һ��Ԫ���ٲ���
            node *q = new node;
            q->data = x;//�½�㣬д������

            q->Next = p->Next;
            p->Next = q;//��ɲ���

            flage = true;
            break;
        }
        j++;
        p = p->Next;
    }
    return flage;
}

//ɾ����i��Ԫ��
bool LinkedList::listDelete(int i)
{
    if (i <= 0){
        return false;
    }
    node *p = this->head;//��Ϊ��Ҫ֪��ǰһ������λ�ã����Դ�ͷ���Ϳ�ʼ
    bool flage = false;//�ж��Ƿ�ɾ����־
    int j = 1;
    while (p->Next != NULL){
        if (j == i){
            node *q = p->Next;//��¼ɾ��Ԫ�ص�λ��
            node *r = p->Next->Next;//������

            delete q;
            q = NULL;//ɾ��Ԫ��

            p->Next = r;//���з��

            flage = true;
            break;
        }
        j++;
        p = p->Next;
    }
    return flage;

}

//β�巨����������
void LinkedList::createListR()
{
    this->ReLinkedList();
    //��ֹ�ظ��������������
    if (this->head->Next != NULL){
            return;
    }

    node *p = this->head;
    node *q = NULL;
    elementType x = 0;
    cout << "����10086�˳���" << endl;
    cin >> x;
    while (x != 10086){
            q = new node;
            q->data = x;//�����½�㣬д������
            q->Next = NULL;

            p->Next = q;
            p = q;//�ƶ�ָ�뵽β��
            cin >> x;
    }
    return;
}

//��ʱ��д
void LinkedList::createListH()
{

}

//��ӡ����Ԫ��
void LinkedList::print()
{
    this->ReLinkedList();
    node *p = this->head->Next;

    while (p != NULL){
        cout << p->data << " ";
        p = p->Next;
    }

}

//�������
void LinkedList::destroy()
{
    node *p = this->head->Next;
    node *q  = NULL;
    this->head->Next = NULL;

    while (p != NULL){
        q = p->Next;
        delete p;
        p = q;
    }
    delete (this->head);
    this->head = NULL;
    return;
}

//��������˳�����Ԫ��
void LinkedList::listInsert(bool, int x)
{
    node *p = this->head;
    bool flage = false;//���������һ��λ�������⴦��
    while (p->Next != NULL){
        if (x < p->Next->data){
            node *q = new node;
            q->data = x;//�½��д����

            q->Next = p->Next;
            p->Next = q;
            flage = true;
            break;
        }
        p = p->Next;
    }
    if (!flage){
        node *q = new node;
        q->data = x;//��������ý��
        q->Next = NULL;

        p->Next = q;
    }
    return;
}

//�������ż���������±�
void LinkedList::apart(LinkedList &L1, LinkedList &L2)
{
    node *p = this->head;//ͷ��㿪ʼ
    node *p1 = NULL;//��¼λ��
    node *q = L1.ReheadReall(true);
    node *r = L2.ReheadReall(true);

    while (p->Next != NULL){
            if (p->Next->data % 2 == 0){
                    p1 = p->Next;
                    p->Next = p->Next->Next;//��Խ����

                    p1->Next = q->Next;
                    q->Next = p1;//����
            }
            else{
                    p1 = p->Next;
                    p->Next = p->Next->Next;//��Խ����

                    p1->Next = r->Next;
                    r->Next = p1;//����
            }
    }
    return;
}

//��õ�������Ĺ�������
void LinkedList::allpart(LinkedList &L1, LinkedList &L2)
{
    node *p = L1.Rehead(true);
    node *q = L2.Rehead(true);//���������ĵ�һ�����ݵĵ�ַ

    while (p != NULL && q != NULL){
        if (p->data == q->data){
            this->listInsert(0, q->data);//��Ԫ�ز��뵽�±���
            q = q->Next;
            p = p->Next;
        }
        else if (p->data > q->data){
            q = q->Next;
        }
        else{
            p = p->Next;
        }
    }
    return;
}

//ɾ���������е��ظ�Ԫ��
int LinkedList::listDeleteSame(bool)
{
    int j = 0;
    node *p = this->head->Next;
    node *q = NULL, *r = NULL;//����ɾ�����

    while (p->Next != NULL){
      if (p->data == p->Next->data){
        q = p->Next;
        r = p->Next->Next;
        p->Next = r;;//Խ��Ԫ������

        j++;

        delete q;
        q = NULL;//ɾ�����
      }
      else{
        p = p->Next;
      }
    }
    return j;
}

//���������ǹ���Ԫ��֮��
void LinkedList::disApart(LinkedList &L2)
{
    //Ŀ��ֻ��Ҫһ������
    node *p = this->head;
    node *q = p;
    node *r = L2.ReheadReall(true);//ͷ���
    node *t = NULL;

    while (q->Next != NULL && r->Next != NULL)
    {
        if (q->Next->data > r->Next->data){
            t = r->Next;
            r->Next = r->Next->Next;//��Խ����

            t->Next = p->Next;
            p->Next = t;//����ͷ��
        }
        else if (q->Next->data < r->Next->data){
            q = q->Next;
        }
        else{
            q = q->Next;
            r = r->Next;
        }

    }

    if (r->Next != NULL){
        t = r;
        q->Next = r->Next;//������β����
        t->Next = NULL;//�Ͽ�
    }

    L2.destroy();

    return;
}








