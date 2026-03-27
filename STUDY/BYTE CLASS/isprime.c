#include<stdio.h>

int is_prime(int num)
{
    if(num == 1 || num == 2) return 1;
    int i;
    for(i=2; i<=num/2; i++)
    {
        if(num % i == 0)
        {
            break;
        }
    }
    if(i > num/2) return 1;
    return 0;
}

int main()
{
    for(int i=100; i<=200; i++)
    {
        if(is_prime(i))
        {
            printf("%d ", i);
        }
    }

    return 0;
}