#include<stdio.h>
#include<assert.h>
#include<string.h>
#include "Contact.h"
#include "SeqList.h"

void ContactInit(Contact* con) //初始化
{
    SLInit(con);
}

void ContactDestroy(Contact* con) //销毁联系人列表
{
    SLDestroy(con);
}

void ContactAdd(Contact* con) //添加联系人
{
    PeoInfo p1;
    printf("请输入你要添加的联系人姓名：\n");
    scanf("%s", p1.name);
    printf("请输入你要添加的联系人性别：\n");
    scanf("%s", p1.gender);
    printf("请输入你要添加的联系人年龄：\n");
    scanf("%d", &p1.age);
    printf("请输入你要添加的联系人电话：\n");
    scanf("%s", p1.tel);
    printf("请输入你要添加的联系人地址：\n");
    scanf("%s", p1.addr);

    SLPushBack(con, p1); //在总表中尾插联系人
}

int ContactFindByName(Contact* con, char name[])
{
    for(int i=0; i<con->size; i++)
    {
        if(strcmp(con->arr[i].name, name) == 0) //比较两个字符串
        {
            return i;
        }
    }
    return -1; //没有找到
}

void ContactDel(Contact* con) //删除联系人
{
    char name[NAME_MAX];
    printf("请输入你要删除的联系人姓名：\n");
    scanf("%s", name);

    int x = ContactFindByName(con, name);

    if(x >= 0)
    {
        SLErase(con, x); //指定删除对应下标的联系人
        printf("删除成功！\n");
    }
    else
    {
        printf("您要删除的联系人不存在！\n");
    }
}

void ContactShow(Contact* con) //打印数据
{
    printf("姓名  性别  年龄  电话  地址\n");
    for(int i=0; i<con->size; i++)
    {
        printf("%s    %s    %d    %s    %s\n", 
            con->arr[i].name,
            con->arr[i].gender,
            con->arr[i].age,
            con->arr[i].tel,
            con->arr[i].addr);
    }
}

void ContactModify(Contact* con) //修改数据
{
    char name[NAME_MAX];
    printf("请输入你要修改的联系人姓名：\n");
    scanf("%s", name);

    int x = ContactFindByName(con, name);

    if(x<0)
    {
        printf("您要修改的联系人数据不存在！\n");
        return;
    }

    printf("请输入新的姓名：\n");
    scanf("%s", con->arr[x].name);
    printf("请输入新的性别：\n");
    scanf("%s", con->arr[x].gender);
    printf("请输入新的年龄：\n");
    scanf("%d", &con->arr[x].age); //特别留意！！
    printf("请输入新的电话：\n");
    scanf("%s", con->arr[x].tel);
    printf("请输入新的住址：\n");
    scanf("%s", con->arr[x].addr);
    
}

void ContactFind(Contact* con) //查找数据
{
    printf("请输入你要查找的联系人姓名：\n");
    char name[NAME_MAX];
    scanf("%s", name);

    int x = ContactFindByName(con, name);

    if(x < 0)
    {
        printf("查无此人！\n");
        return;
    }
    printf("姓名  性别  年龄  电话  地址\n");
    printf("%s    %s    %d    %s    %s\n", 
            con->arr[x].name,
            con->arr[x].gender,
            con->arr[x].age,
            con->arr[x].tel,
            con->arr[x].addr);
}