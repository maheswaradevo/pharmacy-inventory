#include "adminmode.h"
#include "../stack/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adminMode()
{
    char itemName;
    int menu, pilih, tgl, bln, thn;
    while (1)
    {
        printf("|*|-------------------------------|*|\n");
        printf("|*|       PHARMACY INVENTORY      |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|-------------ADMIN-------------|*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|      1. MENAMBAH DATA OBAT    |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|      2. MENGAMBIL DATA OBAT   |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|      3. LIHAT DATA OBAT       |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|      4. LIHAT DATA USER       |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|      5. EXIT TO MAIN MENU     |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*| Pilih Menu : ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            printf("|*| Input nama obat : ");
            fflush(stdin);
            scanf("%[^\n]s", &itemName);
            fflush(stdin);
            printf("|*| Input tanggal kadaluwarsa obat (format : dd, contoh : 01) : ");
            scanf("%d", &tgl);
            printf("|*| Input bulan kadaluwarsa obat (format : mm, contoh : 09) : ");
            scanf("%d", &bln);
            printf("|*| Input tahun kadaluwarsa obat (format : yyyy, contoh : 2023) : ");
            scanf("%d", &thn);
            push(&itemName, tgl, bln, thn);
            printf("|*| Sukses input data obat!\n");
            printf("|*| ");
            system("pause");
            system("cls");
            break;
        case 2:
            //menu 2
            pop();
            printf("|*| ");
            system("pause");
            system("cls");
            break;
        case 3:
            //menu 3
            displayStack();
            printf("|*| ");
            system("pause");
            break;
        case 4:
            //menu 4
            readFileForHashTable();
            displayHashTable();
            printf("|*| ");
            system("pause");
            break;
        case 5:
            return 0;
        default:
            printf("|*| Input tidak ada dalam menu!\n");
            printf("|*| ");
            system("pause");
        }
    }
    return 0;
}
