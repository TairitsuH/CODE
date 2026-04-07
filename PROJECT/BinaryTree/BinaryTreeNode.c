#include "BinaryTreeNode.h"

//新建树节点
BTNode* BuyNode(BTDataType val)
{
    BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
    if(tmp == NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

//创建固定二叉树
BTNode* CreateBinaryTree()
{
    BTNode* node1 = BuyNode(1);
    BTNode* node2 = BuyNode(2);
    BTNode* node3 = BuyNode(3);
    BTNode* node4 = BuyNode(4);
    BTNode* node5 = BuyNode(5);
    BTNode* node6 = BuyNode(6);

    node1->left = node2;
    node1->right = node4;
    node2->left = node3;
    node4->left = node5;
    node4->right = node6;

    return node1;
}

//前序遍历
void PreOrder(BTNode* root)
{
    if(!root)
    return;

    printf("%d ", root->val); //根
    PreOrder(root->left); //左
    PreOrder(root->right); //右
}

//中序遍历
void MidOrder(BTNode* root)
{
    if(!root)
    return;

    PreOrder(root->left); //左
    printf("%d ", root->val); //根
    PreOrder(root->right); //右
}

//后序遍历
void PostOrder(BTNode* root)
{
    if(!root)
    return;

    PreOrder(root->left); //左
    PreOrder(root->right); //右
    printf("%d ", root->val); //根
}

//计算节点个数
int TreeSize(BTNode* root)
{
    if(!root)
    return 0;

    return TreeSize(root->left) + TreeSize(root->right) + 1;
}

//计算叶子节点数
int LeafSize(BTNode* root)
{
    //要考虑root为空的情况！否则会报错
    if(!root)
    return 0;

    if(!root->left && !root->right)
    return 1;

    return LeafSize(root->left) + LeafSize(root->right);
}

//计算树的高度
int TreeHeight(BTNode* root)
{
    if(!root)
    return 0;

    if(!root->left && !root->right)
    return 1;

    return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;    
}

//计算第K层节点个数
int LeafLevelKSize(BTNode* root, int k)
{
    if(!root)
    return 0;

    if(k == 1)
    return 1;

    return LeafLevelKSize(root->left, k-1) + LeafLevelKSize(root->right, k-1);
}

//根据值查找节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
    if(!root)
    return NULL;

    if(root->val == x)
    return root;

    BTNode* ret1 = TreeFind(root->left, x);
    if(ret1 != NULL)
    {
        return ret1;
    }
    BTNode* ret2 = TreeFind(root->right, x);
    if(ret2 != NULL)
    {
        return ret2;
    }
    
    return NULL;
}