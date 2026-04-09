#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTreeNode
{
    char val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

BTNode* CreateTree(char* a, int* pi)
{
    if(a[*pi] == '#')
    {
        (*pi)++; //记得加括号！不要写在if里面！因为只要判断就会＋1
        return NULL;
    }

    BTNode* root = (BTNode*)malloc(sizeof(BTNode));

    //初始化
    root->val = a[(*pi)++];

    root->left = CreateTree(a, pi);
    root->right = CreateTree(a, pi);

    return root;
}

//中序遍历
void InOrder(BTNode* root)
{
    if(!root) return;

    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

int main()
{
    char a[100];
    scanf("%s", a);

    int i = 0;
    BTNode* root = CreateTree(a, &i);

    InOrder(root);

    return 0;
}

//一刷：疯狂打错字...看来还是用Tab保险一点；