#include "adminmode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adminMode()
{
    system("cls");
    int menu, pilih;
    while (1)
    {
        printf("|*|-------------------------------|*|\n");
        printf("|*|       PHARMACY INVENTORY      |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|-------------ADMIN-------------|*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|      1. MENAMBAH STOK OBAT    |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|      2. MENGAMBIL STOK OBAT   |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|      3. LIHAT DATA OBAT       |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|      4. LIHAT DATA USER       |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|      5. EXIT                  |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*| Pilih Menu : ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            //menu 1
            break;
        case 2:
            //menu 2
            break;
        case 3:
            //menu 3
            break;
        case 4:
            //menu 4
            displayHashTable();
        case 5:
            exit(0);
        default:
            printf("|*| Input tidak ada dalam menu!\n");
            printf("|*| ");
            system("pause");
        }
    }
    return 0;
}
