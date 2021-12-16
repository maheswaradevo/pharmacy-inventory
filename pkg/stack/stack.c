#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "../../adt/adt.h"
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
        printf("|*| Data sudah penuh!\n");
    else
    {
        s.top++;
        strcpy(b[s.top].itemName, itemName);
        b[s.top].exp.date = date;
        b[s.top].exp.month = month;
        b[s.top].exp.year = year;
    }
}

void pop()
{
    if (isEmpty())
        printf("|*| Data masih kosong!\n");
    else
    {
        printf("|*| Data %s sudah dihapus!\n", b[s.top].itemName);
        s.top--;
    }
}

void displayStack()
{
    if (isEmpty())
        printf("|*| Data masih kosong!\n");
    else
    {
        for (int i = s.top; i >= 0; i--)
        {
            printf("|*| Item Name : %s\n", b[i].itemName);
            printf("|*| Expired : %d/%d/%d\n\n", b[i].exp.date, b[i].exp.month, b[i].exp.year);
        }
    }
}

void bubbleSortName(int size)
{
    char temp[255];
    int temp1, temp2, temp3;
    for (int i = 0; i <= size - 1; i++)
    {
        for (int j = 0; j <= size - i - 1; j++)
        {
            if (strcmp(b[j].itemName, b[j + 1].itemName) > 0)
            {
                strcpy(temp, b[j].itemName);
                temp1 = b[j].exp.date;
                temp2 = b[j].exp.month;
                temp3 = b[j].exp.year;

                strcpy(b[j].itemName, b[j + 1].itemName);
                b[j].exp.date = b[j + 1].exp.date;
                b[j].exp.month = b[j + 1].exp.month;
                b[j].exp.year = b[j + 1].exp.year;

                strcpy(b[j + 1].itemName, temp);
                b[j + 1].exp.date = temp1;
                b[j + 1].exp.month = temp2;
                b[j + 1].exp.year = temp3;
            }
        }
    }
}

void displaySortedName(int size)
{
    for (int i = 1; i <= size; i++)
    {
        printf("|*| Item Name : %s\n", b[i].itemName);
        printf("|*| Expired : %d/%d/%d\n\n", b[i].exp.date, b[i].exp.month, b[i].exp.year);
    }
}

void bubbleSortDate(int size)
{
    int temp;
    char temp2[255];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (b[j].exp.year > b[i].exp.year)
            {
                temp = b[j].exp.year;
                strcpy(temp2, b[j].itemName);
                b[j].exp.year = b[i].exp.year;
                strcpy(b[j].itemName, b[i].itemName);
                b[i].exp.year = temp;
                strcpy(b[i].itemName, temp2);

                temp = b[j].exp.month;
                strcpy(temp2, b[j].itemName);
                b[j].exp.month = b[i].exp.month;
                strcpy(b[j].itemName, b[i].itemName);
                b[i].exp.month = temp;
                strcpy(b[i].itemName, temp2);

                temp = b[j].exp.date;
                strcpy(temp2, b[j].itemName);
                b[j].exp.date = b[i].exp.date;
                strcpy(b[j].itemName, b[i].itemName);
                b[i].exp.date = temp;
                strcpy(b[i].itemName, temp2);
            }
            else
            {
                if (b[j].exp.year == b[i].exp.year)
                {
                    if (b[j].exp.month > b[i].exp.month)
                    {
                        temp = b[j].exp.year;
                        strcpy(temp2, b[j].itemName);
                        b[j].exp.year = b[i].exp.year;
                        strcpy(b[j].itemName, b[i].itemName);
                        b[i].exp.year = temp;
                        strcpy(b[i].itemName, temp2);

                        temp = b[j].exp.month;
                        strcpy(temp2, b[j].itemName);
                        b[j].exp.month = b[i].exp.month;
                        strcpy(b[j].itemName, b[i].itemName);
                        b[i].exp.month = temp;
                        strcpy(b[i].itemName, temp2);

                        temp = b[j].exp.date;
                        strcpy(temp2, b[j].itemName);
                        b[j].exp.date = b[i].exp.date;
                        strcpy(b[j].itemName, b[i].itemName);
                        b[i].exp.date = temp;
                        strcpy(b[i].itemName, temp2);
                    }
                    else
                    {
                        if (b[j].exp.month == b[i].exp.month)
                        {
                            if (b[j].exp.date > b[i].exp.date)
                            {
                                temp = b[j].exp.year;
                                strcpy(temp2, b[j].itemName);
                                b[j].exp.year = b[i].exp.year;
                                strcpy(b[j].itemName, b[i].itemName);
                                b[i].exp.year = temp;
                                strcpy(b[i].itemName, temp2);

                                temp = b[j].exp.month;
                                strcpy(temp2, b[j].itemName);
                                b[j].exp.month = b[i].exp.month;
                                strcpy(b[j].itemName, b[i].itemName);
                                b[i].exp.month = temp;
                                strcpy(b[i].itemName, temp2);

                                temp = b[j].exp.date;
                                strcpy(temp2, b[j].itemName);
                                b[j].exp.date = b[i].exp.date;
                                strcpy(b[j].itemName, b[i].itemName);
                                b[i].exp.date = temp;
                                strcpy(b[i].itemName, temp2);
                            }
                        }
                    }
                }
            }
        }
    }
}

void displaySortedDate(int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("|*| Item Name : %s\n", b[i].itemName);
        printf("|*| Expired : %d/%d/%d\n\n", b[i].exp.date, b[i].exp.month, b[i].exp.year);
    }
}