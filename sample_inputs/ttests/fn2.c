int g;

// for assignment 4
int y(int a, int b, int c, int n, int *p)
{
    1 + 2;
    2 + (n = 1 + 3);
    1 + (*p = 1 + (n = 1));
    1 + 2 * 3 / 4 % 5;
    *p = 1 + 2 * 3 / 4 % 5;
    n = ~1 + !3;
    g = +(+1) + -(-3);

    if (a == 8)
    {
        n = 2;
        if (c < 9)
        {
            b = 0;
        }
        else
        {
            b = 3;
        }
    }

    while (b >= ++n)
    {
        n = n + 1;
    }

    do
    {
        a = a + 2;

        if (a > 200)
        {
            break;
        }
        else
        {
            continue;
        }

    } while (--a != b);

    for (n = 0; n < 30; n += 3)
    {
        if (a > 200)
        {
            return a;
        }
        else
        {
            continue;
        }
        c ^= *p |= b += a *= 7;
    }

    a = f(a, b + 9);

    a = *p + 4;

    int l[10];
    sizeof(a);
    sizeof(p);
    sizeof(int[10]);
    sizeof(int[10][10]);
    sizeof(1);
    sizeof(l);
    sizeof(l + 1);
    sizeof(unsigned int *);

    p = l;
    l[3] = 9;
    *l;
    *(l + 8 - 3);

    int *u;
    int *v;

    u + 4;

    u - v;
    b = a++;
    b = *p++;
    (*p)++;

    &a;

    // return n + a;
}