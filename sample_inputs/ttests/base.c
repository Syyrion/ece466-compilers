int i1;
unsigned int ui1;
unsigned ui2;
long unsigned ul1;
const i2;
signed i3;
volatile unsigned ui3;
char c1;
unsigned char c2;
signed char c3;
long long ll1;
unsigned long long ull1;
short s1;
unsigned short us1;
volatile signed short s3;
double d;
long double ld;
float f;
const float f2;

int *volatile const restrict cc1;
int **cc2;
int **volatile const *const cc3;
int *cc4[];
int (*const *(*cc5)[3+5])[10];

// declare x as function returning pointer to array 5 of pointer to function returning char
// char (*(**x())[5])();

/*

x is a
function
    void
    pointer
        array of 5
            pointer
                function
                    void
                    char

*/
