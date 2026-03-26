#include<stdio.h>
#include "SeqList.h"
#include "SeqList.c"
#include "Contact.h"
#include "Contact.c"

void menu()
{
    printf("**************通讯录******************\n");
    printf("******1.增加联系人  2.删除联系人******\n");
    printf("******3.修改联系人  4.查找联系人******\n");
    printf("******5.展示联系人  0.退出通讯录******\n");
    printf("**************************************\n");
}

int main()
{
    Contact con;
    ContactInit(&con);

    int op = -1;
    do
    {
        menu();
        printf("请选择您的操作：\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
            {
                ContactAdd(&con);
                break;
            }
            case 2:
            {
                ContactDel(&con);
                break;
            }
            case 3:
            {
                ContactModify(&con); 
                break;
            }
            case 4:
            {
                ContactFind(&con);
                break;
            }
            case 5:
            {
                ContactShow(&con);
                break;
            }
            case 0:
            {
                printf("推出通讯录......\n");
                break;
            }
            default:
            {
                printf("输入错误，请重新选择！\n");
                break;
            }
        }
    }while(op != 0);
    

    return 0;
}