#include<stdio.h>
int main()
{
    int a,b,c,mid;
    char ch;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
    {
        mid = a;
        a = b;
        b = mid;
    }
    if(b>c)
    {
        mid = c;
        c = b;
        b = mid;
    }
    if(a>b)
    {
        mid = a;
        a = b;
        b = mid;
    }

    int first = 1;
    while((ch = getchar()) != '\n' && ch != EOF);
    
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if(ch != 'A' && ch != 'B' && ch != 'C')
        {
            continue;
        }
        
        if(!first)
        {
            printf(" ");
        }
        
        switch(ch)
        {
            case 'A':
            {
                printf("%d",a);
                break;
            }
            case 'B':
            {
                printf("%d",b);
                break;
            }
            case 'C':
            {
                printf("%d",c);
                break;
            }
        }
        first = 0;
    }
    return 0;
}