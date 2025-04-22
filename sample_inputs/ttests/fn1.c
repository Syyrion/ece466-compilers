int f();
int h(int), f();

double n;

// oh shit these are compatible
int (*a())[];
int (*volatile a(int))[10];
int (*const a())[];
int (*a(int))[]
{
    n;
}

int k;
// double k;

int *d;
int *d;

// this is horrifying, why is this a thing?
int (*y(int n))(int n)
{
    n;

    if (4)
    {
        int i;
        // for (i = 0; i < 10; i++)
        //     ;
    }
    else
        goto h;

    while (0)
    {
    }

    do
    {

    } while (0);

h:

    return 90 + 2;

    // this seems to cause a syntax error according to the spec but gcc says it's fine?
    // end_label:
}

// TODO this is unfinished
// int f(i)  /* non-prototype definition should be compat with prev decl */
// double i; /* compiler shouldn't notice this error */
// {
//     int j;
// }

void (*g(double d))(int, char)
{
    int f();
    int g();
    /* gcc complains about this but I think this g should
    hide the name g in global scope */
    // _whatis g;		/* _whatis is my debug extension */
}

int h(int x)
{
    int h; /* gcc does NOT complain about this */
}

// kr(i,j,k)
// double k;
// {
// 	_whatis i;
// 	_whatis k;
// }
