#include <iostream> //二叉链表操作（建立/遍历）
typedef char DataType;
#define maxsize 100
const char RefValue = '#';
using namespace std;

struct BinTreeNode
{
    DataType data;                       //数据域
    BinTreeNode *leftChild, *rightChild; //左指针域，右指针域
};

class BinaryTree
{
private:
    BinTreeNode *root;

public:
    BinaryTree();
    void CreateBinTree(BinTreeNode *&subTree);
    void CreateBinTree(); //创建二叉树
    bool IsEmpty()        //判树空否
    {
        return root == NULL ? 1 : 0;
    }
    BinTreeNode *Find(DataType &item); //搜索
    void InOrder();                    //中序遍历
    void InOrder(BinTreeNode *subTree);
    void PreOrder(); //前序遍历
    void PreOrder(BinTreeNode *subTree);
    void PostOrder(); //后序遍历
    void PostOrder(BinTreeNode *subTree);
    int Count(BinTreeNode *root); //统计结点个数
    int Count();
    int Height(BinTreeNode *root); //统计二叉树的高度
    int Height();
    void Copy(); //复制二叉树
    BinTreeNode *Copy(BinTreeNode *&Tree);
};

BinaryTree ::BinaryTree()
{
    root = NULL;
}

void BinaryTree::CreateBinTree()
{
    CreateBinTree(root);
}

void BinaryTree::CreateBinTree(BinTreeNode *&subTree)
{
    DataType item;
    cin >> item; //读入根结点的值
    if (item != RefValue)
    {
        subTree = new BinTreeNode; //建立根结点
        if (subTree == NULL)
        {
            cout << "存储分配错!" << endl;
            exit(1);
        }
        subTree->data = item;
        CreateBinTree(subTree->leftChild);
        CreateBinTree(subTree->rightChild);
    }
    else
        subTree = NULL; //封闭叶结点
}

void BinaryTree::PreOrder()
{
    PreOrder(root);
}

void BinaryTree::PreOrder(BinTreeNode *subTree)
{
    if (subTree != NULL)
    {
        cout << subTree->data;
        PreOrder(subTree->leftChild);
        PreOrder(subTree->rightChild);
    }
}

void BinaryTree ::InOrder()
{
    InOrder(root);
}

void BinaryTree ::InOrder(BinTreeNode *subTree)
{
    if (subTree != NULL)
    {
        InOrder(subTree->leftChild);
        cout << subTree->data;
        InOrder(subTree->rightChild);
    }
}

void BinaryTree ::PostOrder()
{
    PostOrder(root);
}

void BinaryTree ::PostOrder(BinTreeNode *subTree)
{
    if (subTree != NULL)
    {
        PostOrder(subTree->leftChild);
        PostOrder(subTree->rightChild);
        cout << subTree->data;
    }
}

int BinaryTree ::Count()
{
    return Count(root);
}

int BinaryTree ::Count(BinTreeNode *subTree)
{
    if (subTree == NULL)
        return 0;
    else
        return 1 + Count(subTree->leftChild) + Count(subTree->rightChild);
}

int main()
{
    BinaryTree bt;
    cout<<"创建二叉树:";
    bt.CreateBinTree();
    cout << endl<<"前序遍历";
    bt.PreOrder();
    cout << endl<<"中序遍历";
    bt.InOrder();
    cout << endl<<"后序遍历";
    bt.PostOrder();
    cout << endl;
    cout <<"二叉树节点数:"<< bt.Count() << endl;
    return 0;
}
