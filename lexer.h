extern char *filename;
extern int line_num;

typedef union
{
    char *string_literal;
    unsigned long long integer;
    long double real;
} YYSTYPE;

extern YYSTYPE yylval; // token literal value

extern char *yytext; // provided by flex
extern int yyleng;   // provided by flex

typedef enum
{
    LV_NONE,
    LV_STRING,
    LV_NUMBER,
} yylval_t;

extern yylval_t yylval_type; // type of the token contained in yylval

extern int yylval_strlen; // if yylval is a string, this contains the length of the string
extern int yylval_strsize; // if yylval is a string, this contains the buffer size

#define NT_UNSIGNED 0b1000
#define NT_INT 0b0000
#define NT_LONG 0b0001
#define NT_LONG_LONG 0b0010
#define NT_FLOAT 0b0100
#define NT_DOUBLE 0b0101
#define NT_LONG_DOUBLE 0b0110

typedef union
{
    char all;
    struct
    {
        char type : 2;
        char is_real : 1;
        char is_unsigned : 1;
    };
} yylval_num_t;

extern yylval_num_t yylval_num_type; // if yylval is a number, this contains type information about the number

extern int yylex(void);
