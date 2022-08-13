#include<iostream>
using namespace std;
#define elementType int
#define NEWLINE cout << endl

//封装需要的结构体
 struct node
{
    elementType data;
    node* Next;
};

//封装单链表
class LinkedList
{
public:
    LinkedList(); //初始化空链表
    void ReLinkedList();//清空后再次使用的初始化
    int length(); //求链表长度（结点数）
    node* Rehead(bool);//获得第一个元素的地址//在这里是为了安全
    node* ReheadReall(bool);//返回头指针用于修改
    bool getElement(int i, elementType &x); //按序号取元素
    node* locate(elementType x); //查找元素，返回目标指针
    bool listInsert(int i, elementType x);//在第i个结点位置插入值为x的结点
    void listInsert(bool, elementType x);//递增表按大小插入x
    bool listDelete(int i);//删除第i个元素
    int listDeleteSame(bool);//删除表中重复元素
    void createListR(); //尾插法创建单链表
    void createListH(); //头插法创建单链表
    void print(); //打印单链表元素
    void destroy(); //销毁所有node结点，否则内存泄漏, 此函数功能也可以放在析构函数完成。
    void apart(LinkedList &L1, LinkedList &L2);//把奇数和偶数分开放到两个新表
    void allpart(LinkedList &L1, LinkedList &L2);//获得递增链表的公共元素
    void disApart( LinkedList &L2);//递增有序链表非公共元素之和

private:
    node * head; //单链表头指针。node可用类或结构体定义
};


//初始化空链表
LinkedList::LinkedList()
{
    head = new node;//开辟头结点
    head->Next = NULL;
}

//清空后再次使用的初始化
void LinkedList::ReLinkedList()
{
    if (this->head == NULL){
        head = new node;//开辟头结点
        head->Next = NULL;
    }
}

//返回第一个元素的地址
node* LinkedList::Rehead(bool)
{
    return this->head->Next;
}

//返回头指针的地址，用于修改头指针
node* LinkedList::ReheadReall(bool)
{
    return (this->head);
}

//返回链表长度
int LinkedList::length()
{
    node *p = this->head->Next;
    int len = 0;
    while (p != NULL){//遍历返回即可
        p = p->Next;
        len++;
    }
    return len;
}

//按序号获得元素
bool LinkedList::getElement(int i, elementType& x)
{
    if(i < 0){
        return false;
    }

    node *p = this->head->Next;
    int j = 1;

    while (p != NULL){
            if (j == i){//找到元素即退出循环
                break;
            }
            p = p->Next;
            j++;
    }

    if (j == i){//判断是否找到该元素
        x = p->data;
        return true;
    }
    else{
        return false;
    }

}

//查找元素，找到返回结点指针
node* LinkedList::locate(elementType x)
{
    bool flage = false;//判断是否找到该元素
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

//在第i个结点位置插入值为x的结点
bool LinkedList::listInsert(int i, elementType x)
{
    if (i < 0){
        return false;
    }
    this->ReLinkedList();//再次使用初始化

    bool flage = false;//判断是否插入
    int j = 0;//记录下标
    node *p = this->head;//考虑插在最前面

    while(p != NULL){
        if (j == i){//找到前面一个元素再插入
            node *q = new node;
            q->data = x;//新结点，写入数据

            q->Next = p->Next;
            p->Next = q;//完成插入

            flage = true;
            break;
        }
        j++;
        p = p->Next;
    }
    return flage;
}

//删除第i个元素
bool LinkedList::listDelete(int i)
{
    if (i <= 0){
        return false;
    }
    node *p = this->head;//因为需要知道前一个结点的位置，所以从头结点就开始
    bool flage = false;//判断是否删除标志
    int j = 1;
    while (p->Next != NULL){
        if (j == i){
            node *q = p->Next;//记录删除元素的位置
            node *r = p->Next->Next;//连起来

            delete q;
            q = NULL;//删除元素

            p->Next = r;//进行缝合

            flage = true;
            break;
        }
        j++;
        p = p->Next;
    }
    return flage;

}

//尾插法创建单链表
void LinkedList::createListR()
{
    this->ReLinkedList();
    //防止重复调用这个函数！
    if (this->head->Next != NULL){
            return;
    }

    node *p = this->head;
    node *q = NULL;
    elementType x = 0;
    cout << "输入10086退出！" << endl;
    cin >> x;
    while (x != 10086){
            q = new node;
            q->data = x;//开辟新结点，写入数据
            q->Next = NULL;

            p->Next = q;
            p = q;//移动指针到尾部
            cin >> x;
    }
    return;
}

//暂时不写
void LinkedList::createListH()
{

}

//打印表中元素
void LinkedList::print()
{
    this->ReLinkedList();
    node *p = this->head->Next;

    while (p != NULL){
        cout << p->data << " ";
        p = p->Next;
    }

}

//清空链表
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

//递增链表按顺序插入元素
void LinkedList::listInsert(bool, int x)
{
    node *p = this->head;
    bool flage = false;//插入再最后一个位置做特殊处理
    while (p->Next != NULL){
        if (x < p->Next->data){
            node *q = new node;
            q->data = x;//新结点写数据

            q->Next = p->Next;
            p->Next = q;
            flage = true;
            break;
        }
        p = p->Next;
    }
    if (!flage){
        node *q = new node;
        q->data = x;//在最后插入该结点
        q->Next = NULL;

        p->Next = q;
    }
    return;
}

//拆分奇数偶数到两个新表
void LinkedList::apart(LinkedList &L1, LinkedList &L2)
{
    node *p = this->head;//头结点开始
    node *p1 = NULL;//记录位置
    node *q = L1.ReheadReall(true);
    node *r = L2.ReheadReall(true);

    while (p->Next != NULL){
            if (p->Next->data % 2 == 0){
                    p1 = p->Next;
                    p->Next = p->Next->Next;//跨越连接

                    p1->Next = q->Next;
                    q->Next = p1;//插入
            }
            else{
                    p1 = p->Next;
                    p->Next = p->Next->Next;//跨越连接

                    p1->Next = r->Next;
                    r->Next = p1;//插入
            }
    }
    return;
}

//获得递增链表的公共部分
void LinkedList::allpart(LinkedList &L1, LinkedList &L2)
{
    node *p = L1.Rehead(true);
    node *q = L2.Rehead(true);//获得两个表的第一个数据的地址

    while (p != NULL && q != NULL){
        if (p->data == q->data){
            this->listInsert(0, q->data);//把元素插入到新表中
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

//删除递增表中的重复元素
int LinkedList::listDeleteSame(bool)
{
    int j = 0;
    node *p = this->head->Next;
    node *q = NULL, *r = NULL;//用于删除结点

    while (p->Next != NULL){
      if (p->data == p->Next->data){
        q = p->Next;
        r = p->Next->Next;
        p->Next = r;;//越过元素连接

        j++;

        delete q;
        q = NULL;//删除结点
      }
      else{
        p = p->Next;
      }
    }
    return j;
}

//递增有序表非公共元素之和
void LinkedList::disApart(LinkedList &L2)
{
    //目的只是要一个集合
    node *p = this->head;
    node *q = p;
    node *r = L2.ReheadReall(true);//头结点
    node *t = NULL;

    while (q->Next != NULL && r->Next != NULL)
    {
        if (q->Next->data > r->Next->data){
            t = r->Next;
            r->Next = r->Next->Next;//跨越连接

            t->Next = p->Next;
            p->Next = t;//加在头部
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
        q->Next = r->Next;//连接在尾部；
        t->Next = NULL;//断开
    }

    L2.destroy();

    return;
}








