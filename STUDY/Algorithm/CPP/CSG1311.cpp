#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char str[200];
    while(fgets(str, sizeof(str), stdin) != NULL)
    {
        
        char cpy[200] = {0};
        strcpy(cpy, str);

        const char* sep = " \t";
        char* ret = NULL;

        int flag = 0;
        for(ret=strtok(cpy, sep); ret!=NULL; ret=strtok(NULL, sep))
        {
            if(flag == 0)
            {
                cout << ret;
                flag = 1;
            }
            else
            {
                cout << ' ' << ret;
            }
        }
    }
    return 0;
}