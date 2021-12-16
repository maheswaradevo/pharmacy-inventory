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

// void Swap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

void Bubblesort(int size)
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
    printf("Setelah sorting\n");
    for (int i = 1; i <= s.counter; i++)
    {
        printf("|*| Item Name : %s\n", b[i].itemName);
        printf("|*| Expired : %d/%d/%d\n\n", b[i].exp.date, b[i].exp.month, b[i].exp.year);
    }
}

// int partition(dateExp arr[], int low, int high)
// {
//     int pivot = arr[high];
//     int i = (low - 1);
//     for (int j = low; j <= high - 1; j++)
//     {
//         if (arr[j] <= pivot)
//         {
//             i++;
//             Swap(&arr[i].exp.date, &arr[j].date);
//         }
//     }
//     Swap(&arr[i + 1].exp.date, &arr[high].exp.date);
//     return (i + 1);
// }

// void Quicksort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int pi = partition(arr, low, high);
//         Quicksort(arr, low, pi - 1);
//         Quicksort(arr, pi + 1, high);
//     }
// }