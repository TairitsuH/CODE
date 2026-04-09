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

    MidOrder(root->left); //左
    printf("%d ", root->val); //根
    MidOrder(root->right); //右
}

//后序遍历
void PostOrder(BTNode* root)
{
    if(!root)
    return;

    PostOrder(root->left); //左
    PostOrder(root->right); //右
    printf("%d ", root->val); //根
}

//计算节点个数
int TreeSize(BTNode* root)
{
    if(!root)
    return 0;

    //左子树节点数 + 右子树节点数 + 当前节点
    return TreeSize(root->left) + TreeSize(root->right) + 1;
}

//计算叶子节点数
int LeafSize(BTNode* root)
{
    //要考虑root为空的情况！否则会报错
    if(!root)
    return 0;

    //左右都为空，即为叶子节点
    if(!root->left && !root->right)
    return 1;

    return LeafSize(root->left) + LeafSize(root->right);
}

//计算树的高度
int TreeHeight(BTNode* root)
{
    if(!root)
    return 0;

    //取左右子树中较深的一棵，算入当前层数
    return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;    
}

//或者：（计算高度
// int TreeHeight(BTNode* root)
// {
//     if(!root)
//     return 0;

//     int ret1 = TreeHeight(root->left);
//     int ret2 = TreeHeight(root->right);

//     return ret1 > ret2 ? ret1+1 : ret2+1;
// }
//不能直接返回函数！否则递归次数会大大增加（没有记录，每一次都要重算）

//计算第K层节点个数
int LeafLevelKSize(BTNode* root, int k)
{
    if(!root)
    return 0;

    //到达K层则将当前节点计入总数
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
        return ret1; //找到就return，不必遍历右子树
    }
    BTNode* ret2 = TreeFind(root->right, x);
    if(ret2 != NULL)
    {
        return ret2;
    }

    return NULL; //注意不要漏掉if条件之外的return！
}

//销毁二叉树
void TreeDestroy(BTNode* root)
{
    if(!root) return;

    TreeDestroy(root->left);
    TreeDestroy(root->right);
    free(root);
    //根据后续遍历的方式销毁，避免找不到后续节点
}