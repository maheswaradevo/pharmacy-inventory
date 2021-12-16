#include "usermode.h"
#include "pkg/stack/stack.h"
#include "adt/adt.h"

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubblesort(dataItem arr[], int n)
{
    
    for (int i = s.top; i >= 0; i--)
    {
         for (int j = s.top ; i >= 0; i--)
        {
            if (arr[j].itemName > arr[j + 1].itemName)
            {
                Swap(&arr[j].itemName, &arr[j + 1].itemName);
            }
        }
    }
}

int partition(dateExp arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            Swap(&arr[i].exp.date, &arr[j].date);
        }
    }
    Swap(&arr[i + 1].exp.date, &arr[high].exp.date);
    return (i + 1);
}

void Quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        Quicksort(arr, low, pi - 1);
        Quicksort(arr, pi + 1, high);
    }
}

int userMode()
{
    system("cls");
    int menu, pilih, ch;
    while (1)
    {
        system("cls");
        printf("|*|-------------------------------|*|\n");
        printf("|*|       PHARMACY INVENTORY      |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|--------------USER-------------|*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|       1. LIHAT DATA OBAT      |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|       2. EXIT TO MAIN MENU    |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*| Pilih Menu :");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            //menu 1
            printf("|*|-------------------------------|*|\n");
            printf("|*|       PHARMACY INVENTORY      |*|\n");
            printf("|*|-------------------------------|*|\n");
            printf("|*|--------------USER-------------|*|\n");
            printf("|*|-------------------------------|*|\n");
            printf("|*|        1. SORT (DATE)         |*|\n");
            printf("|*|-------------------------------|*|\n");
            printf("|*|        2. SORT (NAME)         |*|\n");
            printf("|*|-------------------------------|*|\n");
            printf("|*|        3. EXIT                |*|\n");
            printf("|*|-------------------------------|*|\n");
            printf("|*| Pilih Menu :");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                //menu 1
                break;
            case 2:
                //menu 2
                break;
            }
            break;
        case 2:
            return 0;
        default:
            printf("|*| Input tidak ada dalam menu!\n");
            printf("|*| ");
            system("pause");
        }
    }
    return 0;
}
