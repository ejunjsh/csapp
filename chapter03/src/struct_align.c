#include <stdio.h>
#include <string.h>

#define PRINT_D(intValue)     printf(#intValue" is %d\n", (intValue));
#define OFFSET(struct,member)  ((char *)&((struct *)0)->member - (char *)0)


typedef struct
{
    char *a;
    short b;
    double c;
    char d;
    float e;
    char f;
    long g;
    int h;
}test;

typedef struct
{
    int a;
    char b;
    short c;
    char d;
}test1;

typedef struct
{
    int a;
    short b;
    char c;
    char d;
}test2;

int main()
{
    PRINT_D(sizeof(test))
    PRINT_D(OFFSET(test,a))
    PRINT_D(OFFSET(test,b))
    PRINT_D(OFFSET(test,c))
    PRINT_D(OFFSET(test,d))
    PRINT_D(OFFSET(test,e))
    PRINT_D(OFFSET(test,f))
    PRINT_D(OFFSET(test,g))
    PRINT_D(OFFSET(test,h))

    PRINT_D(sizeof(test1))
    PRINT_D(OFFSET(test1,a))
    PRINT_D(OFFSET(test1,b))
    PRINT_D(OFFSET(test1,c))
    PRINT_D(OFFSET(test1,d))

    PRINT_D(sizeof(test2))
    PRINT_D(OFFSET(test2,a))
    PRINT_D(OFFSET(test2,b))
    PRINT_D(OFFSET(test2,c))
    PRINT_D(OFFSET(test2,d))
    return 0;
}