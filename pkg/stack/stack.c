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

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubblesort()
{
    for (int i = s.top; i >= 0; i--)
    {
        for (int j = s.top - 1; j > 0; j--)
            if (b[j].itemName > b[j + 1].itemName)
            {
                Swap(&b[j].itemName, &b[j + 1].itemName);
            }
    }
}

int partition(int b[], int low, int high)
{
    int pivot = b[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (b[j] <= pivot)
        {
            i++;
            swap(&b[i].date, &b[j].date);
        }
    }
    swap(&b[i + 1].date, &b[high].date);
    return (i + 1);
}

void Quicksort(int b[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(b, low, high);
        Quicksort(b, low, pi - 1);
        Quicksort(b, pi + 1, high);
    }
}
