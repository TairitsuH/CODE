#include<stdio.h>
#pragma once //避免头文件被重复包含

#define NAME_MAX 20 //姓名
#define GENDER_MAX 10 //性别
#define TEL_MAX 20 //电话
#define ADDR_MAX 100 //住址

struct SeqList; //前置声明

typedef struct SeqList Contact; //前置声明+重命名


typedef struct PersonInfo
{
    char name[NAME_MAX];
    char gender[GENDER_MAX];
    int age;
    char tel[TEL_MAX];
    char addr[ADDR_MAX];

}PeoInfo;

void ContactInit(Contact* con); //初始化
void ContactDestroy(Contact* con); //销毁

void ContactAdd(Contact* con); //添加联系人
void ContactDel(Contact* con); //删除联系人

void ContactModify(Contact* con); //修改数据
void ContactFind(Contact* con); //查找数据

void ContactShow(Contact* con); //打印数据

//菜单
void menu();


