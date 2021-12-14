#include <stdio.h>
#include <stdlib.h>

struct Person
{
    char username[255];
    char password[255];
};

struct dateExp
{
    int date;
    int month;
    int year;
};

struct Item
{
    char itemName[255];
    struct dateExp exp;
};
struct Item b[50];

struct stack
{
    int top;
};
struct stack s;