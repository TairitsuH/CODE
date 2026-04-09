#include "BinaryTreeNode.h"
#include "BinaryTreeNode.c"
#include "queue.h"
#include "queue.c"

int main()
{
    char a[16] = "1237####45##6##";
    int i = 0;
    BTNode* root = PrevCreateBinaryTree(a, &i);

    PreOrder(root);
    printf("\n");
    MidOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");

    // int size = TreeSize(root);
    // printf("树的节点个数为%d个。\n", size);

    // int leaf = LeafSize(root);
    // printf("树的叶子节点个数为%d个。\n", leaf);

    // int height = TreeHeight(root);
    // printf("树的高度为%d。\n", height);

    // int k = 0;
    // printf("树的高度为%d，请输入你要查询的层数：\n", height);
    // scanf("%d", &k);
    // int LevelKNode = LeafLevelKSize(root, k);
    // printf("第%d层的节点数为%d。\n", k, LevelKNode);

    // int FindVal = 0;
    // printf("请输入你要查找的值：\n");
    // scanf("%d", &FindVal);
    // BTNode* FindOut = TreeFind(root, FindVal);
    // if(!FindOut)
    // {
    //     printf("没有找到。\n");
    // }
    // else
    // {
    //     printf("找到了。\n");
    // }

    TreeLevelOrder(root);

    if(isBinaryTree(root))
    {
        printf("是完全二叉树。\n");
    }
    else
    {
        printf("不是完全二叉树。\n");
    }

    TreeDestroy(root);

    return 0;
}