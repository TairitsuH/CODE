#pragma once
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
    BTDataType val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

//新建树节点
BTNode* BuyNode(BTDataType val);

//创建固定二叉树，返回根节点
BTNode* CreateBinaryTree();

//前序遍历
void PreOrder(BTNode* root);

//中序遍历
void MidOrder(BTNode* root);

//后序遍历
void PostOrder(BTNode* root);

//计算节点个数
int TreeSize(BTNode* root);

//计算叶子节点数
int LeafSize(BTNode* root);

//计算树的高度
int TreeHeight(BTNode* root);

//计算第K层节点个数
int LeafLevelKSize(BTNode* root, int k);

//根据值查找节点
BTNode* TreeFind(BTNode* root, BTDataType x);