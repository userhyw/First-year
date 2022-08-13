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
    elementType data; //存放元素数据
    //左、右孩子结点（子树根）指针。
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
    void PreOrder(btNode *T); //先序遍历二叉树
    void InOrder(btNode *T, int &high); //中序遍历二叉树
    void PostOrder(btNode *T); //后序遍历二叉树
    bool Empty(btNode *T); //判断是否空二叉树
    bool ReadFileToArray(char filename[], char strLine[100][3], int &Len);//把文件数据读到数组里面
    bool CreateBiTreeFromFile(BiNode* & pBT, char strLine[100][3],int nLen, int & nRow);//创建二叉树
    void DestroyBiTree(BiNode* pBT);//销毁树
    void LeavesOne(BiNode* pBT, int &Lea, int &One);//求叶子结点和一度结点的个数
    void Fimaly(BiNode* pBT, elementType &x, bool &flage);//求各种关系
    void High(BiNode* pBT, elementType &x, int &high, bool &flage);//求x所在结点的层次
    void Turn(BiNode* &pBT, elementType s[], int i); //顺序方式存储在数组中的二叉树转换为二叉链表形式
    void Track(BiNode* pBT, New s[], int &Len);//输出二叉树从每个叶子结点到根结点的路径（经历的结点）
    void LeToRi(BiNode* pBT, New s[], int &head, int &tail);//按层次从左到右打印结点值
    btNode *root; //根结点指针，唯一确定一棵二叉树
};

//读文件数据到数组中
bool BiTree::ReadFileToArray(char filename[], char strLine[100][3], int & nArrLen)
{
	FILE* pFile;  //定义二叉树的文件指针
	char str[1000];  //存放读出一行文本的字符串
	cout << "输入文件地址：" << endl;
	cin >> filename;
	pFile=fopen(filename,"r");
	if(!pFile)
	{
		printf("二叉树数据文件打开失败！\n");
		return false;
	}
	    //读取文件第1行，判断二叉树标识BinaryTree是否正确
	if(fgets(str,1000,pFile)!=NULL)
	{
		if(strcmp(str,"BinaryTree\n")!=0)
		{
			printf("打开的文件格式错误！\n");
			fclose(pFile);     //关闭文件
			return false;
		}
	}
	nArrLen=0;
	while(fscanf(pFile,"%c  %c  %c\n",
&strLine[nArrLen][0],&strLine[nArrLen][1],&strLine[nArrLen][2])!=EOF)
	{             //循环读取结点行数据，存入数组，结点总数加1
		nArrLen++;
	}
	fclose(pFile); //关闭文件
	return true;
}

//数组数据创建二叉树
bool BiTree::CreateBiTreeFromFile(BiNode* & pBT,  char strLine[100][3], int nLen, int & nRow)
{
	    //strLine[100][3]--保存结点数据的二维数组
	    //nLen--结点个数
	    //nRow--数组当前行号
	if((nRow>=nLen) || (nLen==0))
		return false;   //数据已经处理完毕，或者没有数据，退出
	    //根据数组数据递归创建二叉树
	pBT=new BiNode;  //建立根结点
	pBT->data=strLine[nRow][0];
	pBT->lChild=NULL;
	pBT->rChild=NULL;
	int nRowNext=nRow;         //保留本次递归的行号
	if(strLine[nRowNext][1]=='1')
	{               //当前结点有左子树，读下一行数据，递归调用创建左子树。
		nRow++;     //行号加1
		CreateBiTreeFromFile(pBT->lChild, strLine,nLen,nRow);
	}
	if(strLine[nRowNext][2]=='1')
	{               //当前结点有右子树，读下一行数数，递归调用创建右子树。
		nRow++;    //行号加1
		CreateBiTreeFromFile(pBT->rChild, strLine,nLen,nRow);
	}
	return true;
}

//递归销毁二叉树
void BiTree::DestroyBiTree(BiNode* pBT)
{
	if(pBT)
	{
		DestroyBiTree(pBT->lChild);   //递归销毁左子树
		DestroyBiTree(pBT->rChild);   //递归销毁右子树
		delete pBT;                  //释放当前根结点
	}
}

//中序次序输出二叉树中各结点的值及其所对应的层次数
void BiTree::InOrder(btNode *T, int &high)
{
    if (T)
    {
        int High = high + 1;
        InOrder(T->lChild, High);
        cout  << high << "：" << T->data << endl;
        InOrder(T->rChild, High);
    }

}

//求叶子结点和一度结点的个数
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

//家庭关系求解
void BiTree::Fimaly(BiNode* pBT,  elementType &x, bool &flage)
{
    if (pBT)
    {
        if(pBT->lChild != NULL && pBT->lChild->data == x)
        {
            cout << "x的父结点值为：" << pBT->data << endl;
            if (pBT->rChild) cout << "x的右兄弟结点值为：" << pBT->rChild->data << endl;
            else cout << "x没有右兄弟" << endl;

            if (pBT->lChild->lChild) cout << "x的左孩子值为：" << pBT->lChild->lChild->data << endl;
            else cout << "x没有左孩子" << endl;

            if (pBT->lChild->rChild) cout << "x的右孩子值为：" << pBT->lChild->rChild->data << endl;
            else cout << "x没有右孩子" << endl;
            flage = true;
            return;
        }
        else if (pBT->rChild != NULL && pBT->rChild->data == x)
        {
            cout << "x的父结点值为：" << pBT->data << endl;
            if (pBT->lChild) cout << "x的左兄弟结点值为：" << pBT->lChild->data << endl;
            else cout << "x没有左兄弟" << endl;

            if (pBT->rChild->lChild) cout << "x的左孩子值为：" << pBT->rChild->lChild->data << endl;
            else cout << "x没有左孩子" << endl;

            if (pBT->rChild->rChild) cout << "x的右孩子值为：" << pBT->rChild->rChild->data << endl;
            else cout << "x没有右孩子" << endl;
            flage = true;
            return;
        }
        else if (pBT->data == x)
        {
            cout << "x没有父节点，没有兄弟结点" << endl;

            if (pBT->lChild) cout << "x的左孩子值为：" << pBT->lChild->data << endl;
            else cout << "x没有左孩子" << endl;

            if (pBT->rChild) cout << "x的右孩子值为：" << pBT->rChild->data << endl;
            else cout << "x没有右孩子" << endl;
            flage = true;
            return;
        }
    Fimaly(pBT->lChild, x, flage);
    Fimaly(pBT->rChild, x, flage);
    }
}

//求x所在结点的层次
void BiTree::High(BiNode* pBT, elementType &x, int &high, bool &flage)
{
    //先序遍历找
    if (pBT)
    {
        if (pBT->data == x)
        {
            cout << "值为x的结点位于第" << high << "层" <<endl;
            flage = true;
            return;
        }
        int highL = high + 1;
        High(pBT->lChild, x, highL, flage);
        High(pBT->rChild, x, highL, flage);
    }
}

//输出二叉树从每个叶子结点到根结点的路径（经历的结点）
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

//按层次从左到右打印结点值
void BiTree::LeToRi(BiNode* pBT, New s[], int &head, int &Len)
{
    //根结点入队
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

//顺序结构转为链式
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

