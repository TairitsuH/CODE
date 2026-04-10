#include "../../PROJECT/BinaryTree/BinaryTreeNode.h"
#include "../../PROJECT/BinaryTree/Queue.h"
#include "../../PROJECT/BinaryTree/Queue.c"

//二叉树销毁
void TreeDestroy(BTNode* root) 
{
    if(!root)
    return;

    if(root->left) TreeDestroy(root->left);
    if(root->right) TreeDestroy(root->right);
    free(root);
}

//二叉树层序遍历（非递归！）
void TreeLevelOrder(BTNode* root)
{
    Queue q;
    QueueInit(&q);

    if(root)
    {
        QueuePush(&q, root);
    }

    while(!QueueEmpty(&q))
    {
        BTNode* top = QueueFront(&q);
        QueuePop(&q);

        printf("%d ", top->val);

        if(top->left) QueuePush(&q, top->left);
        if(top->right) QueuePush(&q, top->right);
    }

    printf("\n");
    QueueDestroy(&q);
}

//判断是否为完全二叉树
bool isComBinaryTree(BTNode* root)
{
    Queue q;
    QueueInit(&q);

    QueuePush(&q, root);

    //进出队列直至遇到空
    while(!QueueEmpty(&q))
    {
        BTNode* top = QueueFront(&q);
        QueuePop(&q);
        if(top == NULL)
        {
            break;
        }

        QueuePush(&q, top->left);
        QueuePush(&q, top->right);
    }

    //判断是否全空（是） / 还有元素（非）
    while(!QueueEmpty(&q))
    {
        BTNode* top = QueueFront(&q);
        QueuePop(&q);

        if(top)
        {
            QueueDestroy(&q);
            return false;
        }
    }

    QueueDestroy(&q);
    return true;
}