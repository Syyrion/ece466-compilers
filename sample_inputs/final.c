int printf();

int u;
int *p;
int s;
int h[10];
int g;

int y(int a, int b)
{
    printf("arg %d %d\n", a, b);
    return a / b;
}

int main()
{
    int a;
    int b;
    int c;
    int d;

    // arrays, pointer minus pointer
    h[3] = 9;
    printf("%d, %d\n", h[3], h - (h + 3));

    a = b = c = d = 6;
    printf("%d, %d, %d, %d\n", a, b, c, d);

    a ^= b |= c += d *= 2;

    printf("%d, %d, %d, %d\n", a, b, c, d);

    // weird
    printf("%d\n", a += a += 1);

    int i;
    for (i = 0; i < 4; i++)
    {
        printf("hello world %d, %d\n", i, i * 2);
        if (i % 2)
        {
            printf("odd\n");
        }
        else
        {
            printf("even\n");
        }
    }

    printf("ret %d\n", y(10, 4));

    return 0;
}