//https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BinaryTreeNode
{
    char val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;


void InOrder(BTNode* root)
{
    if(!root)
    return;

    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

BTNode* CreateBTree(char* a, int n, int* pi)
{
    if(*pi >= n) return NULL;

    if(a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }

    //先判断非空再开空间
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));

    root->val = a[(*pi)++];

    root->left = CreateBTree(a, n, pi);
    root->right = CreateBTree(a, n, pi);

    return root;
}

int main()
{
    char a[100];
    while(scanf("%s", a) != EOF)
    {
        int n = strlen(a);
        int i = 0;
        BTNode* root = CreateBTree(a, n, &i);
        InOrder(root);
        printf("\n");
    }
    return 0;
}

//二刷：有返回类型的函数记得设置返回类型！
//一刷：疯狂打错字...看来还是用Tab保险一点TvT
// #include<stdio.h>
// #include<stdlib.h>

// typedef struct BinaryTreeNode
// {
//     char val;
//     struct BinaryTreeNode* left;
//     struct BinaryTreeNode* right;
// }BTNode;

// BTNode* CreateTree(char* a, int* pi)
// {
//     if(a[*pi] == '#')
//     {
//         (*pi)++; //记得加括号！不要写在if里面！因为只要判断就会＋1
//         return NULL;
//     }

//     BTNode* root = (BTNode*)malloc(sizeof(BTNode));

//     //初始化
//     root->val = a[(*pi)++];

//     root->left = CreateTree(a, pi);
//     root->right = CreateTree(a, pi);

//     return root;
// }

// //中序遍历
// void InOrder(BTNode* root)
// {
//     if(!root) return;

//     InOrder(root->left);
//     printf("%c ", root->val);
//     InOrder(root->right);
// }

// int main()
// {
//     char a[100];
//     scanf("%s", a);

//     int i = 0;
//     BTNode* root = CreateTree(a, &i);

//     InOrder(root);

//     return 0;
// }
