extern char *filename;
extern int line_num;

#define NT_UNSIGNED 0b1000
#define NT_INT 0b0000
#define NT_LONG 0b0001
#define NT_LONG_LONG 0b0010
#define NT_FLOAT 0b0100
#define NT_DOUBLE 0b0101
#define NT_LONG_DOUBLE 0b0110

typedef union
{
    char *string;
    size_t strlen;
    size_t strsize;

    unsigned long long integer;
    long double real;

    union
    {
        char nt_full;
        struct
        {
            char type : 2;
            char is_real : 1;
            char is_unsigned : 1;
        };
    };
} YYSTYPE;

extern YYSTYPE yylval; // token literal value

extern char *yytext; // provided by flex
extern int yyleng;   // provided by flex


extern int yylex(void);
