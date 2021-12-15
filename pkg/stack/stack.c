#include "../../adt/adt.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 50

void initiate()
{
    s.top = -1;
}

int isEmpty()
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (s.top == MAX - 1)
        return 1;
    else
        return 0;
}

void push(char *itemName, int date, int month, int year)
{
    if (isFull())
        printf("Stack sudah penuh!\n");
    else
    {
        s.top++;
        strcpy(b[s.top].itemName, itemName);
        b[s.top].exp.date = date;
        b[s.top].exp.month = month;
        b[s.top].exp.year = year;
        printf("Barang %s sudah dimasukkan", itemName);
    }
}

void pop()
{
    if (isEmpty())
        printf("Stack masih kosong!\n");
    else
    {
        printf("Data %s sudah dihapus!\n", b[s.top].itemName);
        s.top--;
    }
}

void display()
{
    if (isEmpty())
        printf("Stack masih kosong!\n");
    else
    {
        for (int i = s.top; i >= 0; i--)
        {
            printf("Item Name : %s\n", b[i].itemName);
            printf("Expired : %d/%d/%d\n", b[i].exp.date, b[i].exp.month, b[i].exp.year);
        }
    }
