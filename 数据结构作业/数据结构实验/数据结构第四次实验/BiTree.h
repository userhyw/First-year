#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define elementType char
#define NEWLINE cout << endl

typedef struct blNode
{
    blNode()
    {
        this->lChild = NULL;
        this->rChild = NULL;
    }
    elementType data; //���Ԫ������
    //���Һ��ӽ�㣨��������ָ�롣
    struct blNode *lChild, *rChild;
} btNode, BiNode;

class New
{
public:
    New()
    {
        remeber = NULL;
    }
    BiNode *remeber;
};


class BiTree
{
public:
    BiTree(){};
    ~BiTree(){};
    void PreOrder(btNode *T); //�������������
    void InOrder(btNode *T, int &high); //�������������
    void PostOrder(btNode *T); //�������������
    bool Empty(btNode *T); //�ж��Ƿ�ն�����
    bool ReadFileToArray(char filename[], char strLine[100][3], int &Len);//���ļ����ݶ�����������
    bool CreateBiTreeFromFile(BiNode* & pBT, char strLine[100][3],int nLen, int & nRow);//����������
    void DestroyBiTree(BiNode* pBT);//������
    void LeavesOne(BiNode* pBT, int &Lea, int &One);//��Ҷ�ӽ���һ�Ƚ��ĸ���
    void Fimaly(BiNode* pBT, elementType &x, bool &flage);//����ֹ�ϵ
    void High(BiNode* pBT, elementType &x, int &high, bool &flage);//��x���ڽ��Ĳ��
    void Turn(BiNode* &pBT, elementType s[], int i); //˳��ʽ�洢�������еĶ�����ת��Ϊ����������ʽ
    void Track(BiNode* pBT, New s[], int &Len);//�����������ÿ��Ҷ�ӽ�㵽������·���������Ľ�㣩
    void LeToRi(BiNode* pBT, New s[], int &head, int &tail);//����δ����Ҵ�ӡ���ֵ
    btNode *root; //�����ָ�룬Ψһȷ��һ�ö�����
};

//���ļ����ݵ�������
bool BiTree::ReadFileToArray(char filename[], char strLine[100][3], int & nArrLen)
{
	FILE* pFile;  //������������ļ�ָ��
	char str[1000];  //��Ŷ���һ���ı����ַ���
	cout << "�����ļ���ַ��" << endl;
	cin >> filename;
	pFile=fopen(filename,"r");
	if(!pFile)
	{
		printf("�����������ļ���ʧ�ܣ�\n");
		return false;
	}
	    //��ȡ�ļ���1�У��ж϶�������ʶBinaryTree�Ƿ���ȷ
	if(fgets(str,1000,pFile)!=NULL)
	{
		if(strcmp(str,"BinaryTree\n")!=0)
		{
			printf("�򿪵��ļ���ʽ����\n");
			fclose(pFile);     //�ر��ļ�
			return false;
		}
	}
	nArrLen=0;
	while(fscanf(pFile,"%c  %c  %c\n",
&strLine[nArrLen][0],&strLine[nArrLen][1],&strLine[nArrLen][2])!=EOF)
	{             //ѭ����ȡ��������ݣ��������飬���������1
		nArrLen++;
	}
	fclose(pFile); //�ر��ļ�
	return true;
}

//�������ݴ���������
bool BiTree::CreateBiTreeFromFile(BiNode* & pBT,  char strLine[100][3], int nLen, int & nRow)
{
	    //strLine[100][3]--���������ݵĶ�ά����
	    //nLen--������
	    //nRow--���鵱ǰ�к�
	if((nRow>=nLen) || (nLen==0))
		return false;   //�����Ѿ�������ϣ�����û�����ݣ��˳�
	    //�����������ݵݹ鴴��������
	pBT=new BiNode;  //���������
	pBT->data=strLine[nRow][0];
	pBT->lChild=NULL;
	pBT->rChild=NULL;
	int nRowNext=nRow;         //�������εݹ���к�
	if(strLine[nRowNext][1]=='1')
	{               //��ǰ�����������������һ�����ݣ��ݹ���ô�����������
		nRow++;     //�кż�1
		CreateBiTreeFromFile(pBT->lChild, strLine,nLen,nRow);
	}
	if(strLine[nRowNext][2]=='1')
	{               //��ǰ�����������������һ���������ݹ���ô�����������
		nRow++;    //�кż�1
		CreateBiTreeFromFile(pBT->rChild, strLine,nLen,nRow);
	}
	return true;
}

//�ݹ����ٶ�����
void BiTree::DestroyBiTree(BiNode* pBT)
{
	if(pBT)
	{
		DestroyBiTree(pBT->lChild);   //�ݹ�����������
		DestroyBiTree(pBT->rChild);   //�ݹ�����������
		delete pBT;                  //�ͷŵ�ǰ�����
	}
}

//�����������������и�����ֵ��������Ӧ�Ĳ����
void BiTree::InOrder(btNode *T, int &high)
{
    if (T)
    {
        int High = high + 1;
        InOrder(T->lChild, High);
        cout  << high << "��" << T->data << endl;
        InOrder(T->rChild, High);
    }

}

//��Ҷ�ӽ���һ�Ƚ��ĸ���
void BiTree::LeavesOne(BiNode* pBT, int &Lea, int &One)
{
    if (pBT)
    {
        if (pBT->lChild == NULL && pBT->rChild == NULL) Lea++;
        else if (pBT->lChild == NULL && pBT->rChild != NULL) One++;
        else if (pBT->lChild != NULL && pBT->rChild == NULL) One++;
        LeavesOne(pBT->lChild, Lea, One);
        LeavesOne(pBT->rChild, Lea, One);
    }
}

//��ͥ��ϵ���
void BiTree::Fimaly(BiNode* pBT,  elementType &x, bool &flage)
{
    if (pBT)
    {
        if(pBT->lChild != NULL && pBT->lChild->data == x)
        {
            cout << "x�ĸ����ֵΪ��" << pBT->data << endl;
            if (pBT->rChild) cout << "x�����ֵܽ��ֵΪ��" << pBT->rChild->data << endl;
            else cout << "xû�����ֵ�" << endl;

            if (pBT->lChild->lChild) cout << "x������ֵΪ��" << pBT->lChild->lChild->data << endl;
            else cout << "xû������" << endl;

            if (pBT->lChild->rChild) cout << "x���Һ���ֵΪ��" << pBT->lChild->rChild->data << endl;
            else cout << "xû���Һ���" << endl;
            flage = true;
            return;
        }
        else if (pBT->rChild != NULL && pBT->rChild->data == x)
        {
            cout << "x�ĸ����ֵΪ��" << pBT->data << endl;
            if (pBT->lChild) cout << "x�����ֵܽ��ֵΪ��" << pBT->lChild->data << endl;
            else cout << "xû�����ֵ�" << endl;

            if (pBT->rChild->lChild) cout << "x������ֵΪ��" << pBT->rChild->lChild->data << endl;
            else cout << "xû������" << endl;

            if (pBT->rChild->rChild) cout << "x���Һ���ֵΪ��" << pBT->rChild->rChild->data << endl;
            else cout << "xû���Һ���" << endl;
            flage = true;
            return;
        }
        else if (pBT->data == x)
        {
            cout << "xû�и��ڵ㣬û���ֵܽ��" << endl;

            if (pBT->lChild) cout << "x������ֵΪ��" << pBT->lChild->data << endl;
            else cout << "xû������" << endl;

            if (pBT->rChild) cout << "x���Һ���ֵΪ��" << pBT->rChild->data << endl;
            else cout << "xû���Һ���" << endl;
            flage = true;
            return;
        }
    Fimaly(pBT->lChild, x, flage);
    Fimaly(pBT->rChild, x, flage);
    }
}

//��x���ڽ��Ĳ��
void BiTree::High(BiNode* pBT, elementType &x, int &high, bool &flage)
{
    //���������
    if (pBT)
    {
        if (pBT->data == x)
        {
            cout << "ֵΪx�Ľ��λ�ڵ�" << high << "��" <<endl;
            flage = true;
            return;
        }
        int highL = high + 1;
        High(pBT->lChild, x, highL, flage);
        High(pBT->rChild, x, highL, flage);
    }
}

//�����������ÿ��Ҷ�ӽ�㵽������·���������Ľ�㣩
void BiTree::Track(BiNode* pBT, New s[], int &Len)
{
    bool flage = false;
    if (pBT)
    {
        s[Len].remeber = pBT;
        Len++;
        flage = true;
        if (pBT->lChild == NULL && pBT->rChild == NULL)
        {
            for (int i = Len - 1; i >= 0; i--)
            {
                cout << s[i].remeber->data << "->" ;
            }
            cout << "All";
          NEWLINE;
          Len--;
          flage = false;
        }

        Track(pBT->lChild, s, Len);
        Track(pBT->rChild, s, Len);
        }
       if (flage) Len--;
    }

//����δ����Ҵ�ӡ���ֵ
void BiTree::LeToRi(BiNode* pBT, New s[], int &head, int &Len)
{
    //��������
    s[Len].remeber = pBT;
    Len++;
    while (head != Len)
    {
        cout << s[head].remeber->data << " ";
        if (s[head].remeber->lChild) s[Len++].remeber = s[head].remeber->lChild;
        if (s[head].remeber->rChild) s[Len++].remeber = s[head].remeber->rChild;
        head++;
    }
}

//˳��ṹתΪ��ʽ
void BiTree::Turn(BiNode *&pBT, elementType s[], int i)
{
    if (s[i] != '#')
    {
        if (s[i] != '^')
        {
        pBT = new BiNode;
        pBT->data = s[i];
        Turn(pBT->lChild, s, 2 * i);
        Turn(pBT->rChild, s, 2 * i + 1);
        }
    }
}

