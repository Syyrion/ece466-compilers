// for assignment 4
int (*y(int n))(int n)
{
    n;

    if (4)
    {
        int i;
        for (i = 0; i < 10; i++)
        h: // wacky
        {
            break;
            for (;;)
            {
                break;
                continue;
            }
            continue;
        }
    }
    else
        goto h;

    while (0)
    {
        break;
        continue;
    }

    do
    {
        break;
        continue;
    } while (0);

    while (0)
    {
        switch (n + 8)
        {
        case 1:

            break;
        case 5 - 8:
            break;

        case 100:
        case 101: // shouldn't resolve
        case 102: // shouldn't resolve
        default:
            break;
        }
    }

    return 90 + 2;

    // this seems to cause a syntax error according to the spec but gcc says it's fine?
    // end_label:
}