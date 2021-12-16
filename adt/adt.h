#ifndef ADT_DOT_H
#define ADT_DOT_H

#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

struct dateExp
{
    int date;
    int month;
    int year;
};

struct dataItem
{
    char itemName[255];
    char key;
    struct dateExp exp;
};
struct dataItem b[50];

struct stack
{
    int top;
    int counter;
};
struct stack s;

#endif
