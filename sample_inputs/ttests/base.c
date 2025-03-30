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

// extra stuff
int *volatile const restrict cc1;
int **cc2;
int **volatile const *const cc3;
int *cc4[];
int (*const *(*cc5)[3+5])[10];

// so that's allowed I guess
int;


int j(int, int i, int , int);
int k(int, unsigned register o, volatile const float f(int, int **(*[10 + 7 * 6])(float, double)));