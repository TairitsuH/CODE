int* test()
{
    int*p = (int*) malloc(100);
    if(p == NULL)
    {
        return NULL;
    }

    free(p); //释放

    return p;
}

int main()
{
    int* r = test();

    free(r);

    return 0;
}