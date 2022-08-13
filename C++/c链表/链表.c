#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define SORRY 2
#define NEWLINE printf("\n")
#define TRY printf("-------------------------\n")

typedef struct Student
{
    char Num[20];
    struct student* Next;

}Stu;

void PrintfFunction(void);
int CreatLinkList(Stu** Head);
int DeleteLinkList(Stu** Head);
int TravelLinkLIist(Stu** Head);
int AddLinkList(Stu** Head);
int LinkListLenth(Stu** Head);
void BackLinkList(Stu** Head);

int main(void)
{
    int Select;
    Stu* SpHead = NULL;

    while (1) {

        system("cls");//放在最前面！！！

        PrintfFunction();
        //NEWLINE;

        scanf_s("%d", &Select);

        switch (Select) {
        case 1://选择1建立链表！
             { 
                if (SpHead != NULL) {
                    DeleteLinkList(&SpHead);//防止重复建立链表而增加链长度！
                }

                    int c = CreatLinkList(&SpHead);//指针是接收地址的
                if (c == ERROR) {
                     printf("链表已经建立过了！");
                }
                else if (c == SORRY) {
                    printf("链表建立失败，请再次尝试！");
                }
                else if (c == OK){
                    printf("链表建立成功！");
                 }
            break;
          }

        case 2://选择2遍历显示链表数据
        {
            if (SpHead == NULL) {
                printf("请您先建立链表！");
            }
            else {
                TravelLinkLIist(&SpHead);
            }
            break;
        }

        case 3://在尾部追加结点！！！
        {
            if (SpHead == NULL) {
                printf("请先建立链表！");
                NEWLINE;
                break;
            }

            int m_A = AddLinkList(&SpHead);
            if (m_A == ERROR) {
                printf("分配空间出现错误！");
                NEWLINE;
            }

            break;

        }
        case 4://安全退出程序，并且删除所有结点
        {
            if (SpHead != NULL) {
             DeleteLinkList(&SpHead);
            }
             printf("欢迎下次使用！");
             NEWLINE;

             return 0;
        }

        case 5://使用头插法使得链表逆序！
        {
            if (SpHead == NULL) {
                printf("此链表为空。不需要倒序！");
                NEWLINE;
                break;
            }
            else {
                BackLinkList(&SpHead);
            }
            break;

        }

        case 6://使用递归法使得链表逆序！
        {


        }

        case 7://查看链表的结点个数（除头结点外！）
        {
            if (SpHead == NULL) {
                printf("当前的结点个数为0");
                break;
            }
            else {
                int j = LinkListLenth(&SpHead);
                printf("当前的结点个数为：%d", j);
            }
            break;
        }
            
            default:
                break;
        }

        system("pause");
    }


    system("pause");
    return 0;
}

//输入提示函数
void PrintfFunction(void)
{
    printf("输入1建立链表！");
    NEWLINE;
    printf("输入2遍历显示链表数据！");
    NEWLINE;
    printf("输入3在尾部追加结点！");
    NEWLINE;
    printf("输入4安全退出程序！");
    NEWLINE;
    printf("输入5使用头插法对链表进行逆序！");
    NEWLINE;

    printf("输入7获取当前链表的长度！");
    NEWLINE;

}

//创建链表的实现函数
int CreatLinkList(Stu** Head)//用指向指针的指针来接收这个地址！
{
    Stu* Cur = NULL;
    
    *Head = (Stu*)malloc(sizeof(Stu));//头指针指向头结点！！！
    if (*Head == NULL) {
        return SORRY;
    }
    (*Head)->Next = NULL;             //带头结点的单链表成功创建了！

    Cur = (Stu*)malloc(sizeof(Stu));//输入第一个节点的数据！！！
    if (Cur == NULL) {
        return SORRY;
    }

    printf("请输入学生的学号：\n");
    scanf_s("%s", &Cur->Num, 20);

    (*Head)->Next = Cur;
    Cur->Next = NULL;

    return OK;
}

//删除链表的操作！
int DeleteLinkList(Stu** Head)
{

    Stu* Pre, *Cur = (*Head)->Next;

    while (Cur) {
        Pre = Cur->Next;
        free(Cur);
        Cur = Pre;
    }

    free(*Head);
    
    return OK;
}

//遍历链表显示内容函数实现
int TravelLinkLIist(Stu** Head)
{
    //if ((*Head)->Next == NULL) {//在使用函数之前已经进行判断
    //    return ERROR;
    //}

    Stu* Cur = (*Head)->Next;
    while (Cur) {
        printf("学生的学号是：%s", Cur->Num);
        NEWLINE;
        Cur = Cur->Next;
    }

    return OK;
}

//在尾部追加数据结点
int AddLinkList(Stu** Head)
{
    //这是错误操作！！！！，这样头指针会移动到最后一个结点！！！
    //while ((*Head)->Next) {//遍历找到最后一个结点！
    //    (*Head) = (*Head)->Next;
    //}

    Stu* Now = (*Head)->Next;
    while (Now->Next) {
        Now = Now->Next;
    }

    Stu* Cur = (Stu*)malloc(sizeof(Stu));
    if (Cur == NULL) {
        return ERROR;
    }

    printf("请输入学号：");
    scanf_s("%s", Cur->Num, sizeof(Cur->Num));

    //(*Head)->Next = Cur;
    Now->Next = Cur;
    Cur->Next = NULL;

    printf("输入成功！");
    system("pause");

    return OK;
}

//链表长度获取函数
int LinkListLenth(Stu** Head)
{
    Stu* Cur = (*Head)->Next;

    int j = 0;

    while (Cur) {
        Cur = Cur->Next;
        j++;
    }

    return j;
}

//头插法实现链表的逆序
void BackLinkList(Stu** Head)
{
    Stu* Cur, *Pre;

    Cur = (*Head)->Next;//一个实际的数据用一维的指针来接收就好了！！！
    (*Head)->Next = NULL;
   

    while (Cur) {
        Pre = Cur;
        TRY;
        Cur = Cur->Next;
        Pre->Next = (*Head)->Next;
        (*Head)->Next = Pre;
    }

}

Stu LinkBcak(Stu)