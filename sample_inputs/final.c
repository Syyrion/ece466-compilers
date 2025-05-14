int printf();

int u;

int *p;
int s;
int h[10];

int g;

int y(int a, int b)
{
    printf("arg %d %d\n", a, b);
    return 0;
}

int main()
{
    int a;
    int b;
    int c;
    int *d;

    // a = sizeof(1 + 2);
    // b = sizeof(h[0]);
    // c = sizeof(int [10]);

    int i;
    for (i = 0; i < 3; i++)
        printf("hello world %d, %d\n", i, i * 2);

    printf("ret %d\n", y(10, 4));
    // if (i == 2)
    // {
    //     printf("A %d\n", u);
    // }
    // else
    // {
    //     printf("B %d\n", a + 9);
    // }
}