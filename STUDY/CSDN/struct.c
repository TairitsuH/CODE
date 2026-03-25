// struct example
// {
//     int data;
//     struct example* ptr;
// };

// typedef struct example
// {
//     int data;
//     struct EX* ptr;
// }EX;

// struct S1
// {
//     char c1;
//     int i;
//     char c2;
// };

// struct S2
// {
//     char c3;
//     struct S1;
//     double d1;
// };

// struct S
// {
//     int arr[1000];
//     int num;
// };

// struct S s1 = {{1, 2, 3 ,4}, 100};

// void print(struct S* ps)
// {
//     printf("%d\n", ps -> num);
// }

// int main()
// {
//     print(&s1);
//     return 0;
// }

struct A
{
    int _a: 2;
    int _b: 3;
    int _c: 4;
    int _d: 5;
};

int main()
{
    struct A sa = {0};

    int b = 0;
    scanf("%d\n", &b);
    sa._b = b; //合法

    return 0;
}
