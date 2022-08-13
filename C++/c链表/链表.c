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

        system("cls");//������ǰ�棡����

        PrintfFunction();
        //NEWLINE;

        scanf_s("%d", &Select);

        switch (Select) {
        case 1://ѡ��1��������
             { 
                if (SpHead != NULL) {
                    DeleteLinkList(&SpHead);//��ֹ�ظ�������������������ȣ�
                }

                    int c = CreatLinkList(&SpHead);//ָ���ǽ��յ�ַ��
                if (c == ERROR) {
                     printf("�����Ѿ��������ˣ�");
                }
                else if (c == SORRY) {
                    printf("������ʧ�ܣ����ٴγ��ԣ�");
                }
                else if (c == OK){
                    printf("�������ɹ���");
                 }
            break;
          }

        case 2://ѡ��2������ʾ��������
        {
            if (SpHead == NULL) {
                printf("�����Ƚ�������");
            }
            else {
                TravelLinkLIist(&SpHead);
            }
            break;
        }

        case 3://��β��׷�ӽ�㣡����
        {
            if (SpHead == NULL) {
                printf("���Ƚ�������");
                NEWLINE;
                break;
            }

            int m_A = AddLinkList(&SpHead);
            if (m_A == ERROR) {
                printf("����ռ���ִ���");
                NEWLINE;
            }

            break;

        }
        case 4://��ȫ�˳����򣬲���ɾ�����н��
        {
            if (SpHead != NULL) {
             DeleteLinkList(&SpHead);
            }
             printf("��ӭ�´�ʹ�ã�");
             NEWLINE;

             return 0;
        }

        case 5://ʹ��ͷ�巨ʹ����������
        {
            if (SpHead == NULL) {
                printf("������Ϊ�ա�����Ҫ����");
                NEWLINE;
                break;
            }
            else {
                BackLinkList(&SpHead);
            }
            break;

        }

        case 6://ʹ�õݹ鷨ʹ����������
        {


        }

        case 7://�鿴����Ľ���������ͷ����⣡��
        {
            if (SpHead == NULL) {
                printf("��ǰ�Ľ�����Ϊ0");
                break;
            }
            else {
                int j = LinkListLenth(&SpHead);
                printf("��ǰ�Ľ�����Ϊ��%d", j);
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

//������ʾ����
void PrintfFunction(void)
{
    printf("����1��������");
    NEWLINE;
    printf("����2������ʾ�������ݣ�");
    NEWLINE;
    printf("����3��β��׷�ӽ�㣡");
    NEWLINE;
    printf("����4��ȫ�˳�����");
    NEWLINE;
    printf("����5ʹ��ͷ�巨�������������");
    NEWLINE;

    printf("����7��ȡ��ǰ����ĳ��ȣ�");
    NEWLINE;

}

//���������ʵ�ֺ���
int CreatLinkList(Stu** Head)//��ָ��ָ���ָ�������������ַ��
{
    Stu* Cur = NULL;
    
    *Head = (Stu*)malloc(sizeof(Stu));//ͷָ��ָ��ͷ��㣡����
    if (*Head == NULL) {
        return SORRY;
    }
    (*Head)->Next = NULL;             //��ͷ���ĵ�����ɹ������ˣ�

    Cur = (Stu*)malloc(sizeof(Stu));//�����һ���ڵ�����ݣ�����
    if (Cur == NULL) {
        return SORRY;
    }

    printf("������ѧ����ѧ�ţ�\n");
    scanf_s("%s", &Cur->Num, 20);

    (*Head)->Next = Cur;
    Cur->Next = NULL;

    return OK;
}

//ɾ������Ĳ�����
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

//����������ʾ���ݺ���ʵ��
int TravelLinkLIist(Stu** Head)
{
    //if ((*Head)->Next == NULL) {//��ʹ�ú���֮ǰ�Ѿ������ж�
    //    return ERROR;
    //}

    Stu* Cur = (*Head)->Next;
    while (Cur) {
        printf("ѧ����ѧ���ǣ�%s", Cur->Num);
        NEWLINE;
        Cur = Cur->Next;
    }

    return OK;
}

//��β��׷�����ݽ��
int AddLinkList(Stu** Head)
{
    //���Ǵ��������������������ͷָ����ƶ������һ����㣡����
    //while ((*Head)->Next) {//�����ҵ����һ����㣡
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

    printf("������ѧ�ţ�");
    scanf_s("%s", Cur->Num, sizeof(Cur->Num));

    //(*Head)->Next = Cur;
    Now->Next = Cur;
    Cur->Next = NULL;

    printf("����ɹ���");
    system("pause");

    return OK;
}

//�����Ȼ�ȡ����
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

//ͷ�巨ʵ�����������
void BackLinkList(Stu** Head)
{
    Stu* Cur, *Pre;

    Cur = (*Head)->Next;//һ��ʵ�ʵ�������һά��ָ�������վͺ��ˣ�����
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