#include "adminmode.h"
#include "../stack/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adminMode()
{
    system("cls");
    char itemName;
    int menu, pilih, tgl, bln, thn;
    while (1)
    {
        system("cls");
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
        printf("|*|      4. EXIT                  |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*| Pilih Menu : ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            printf("|*| Input nama obat : ");
            scanf("%s", &itemName);
            printf("|*| Input tanggal kadaluwarsa obat (format : dd/mm/yyyy) : ");
            scanf("%d %d %d", &tgl, &bln, &thn);
            push(&itemName, tgl, bln, thn);
            printf("|*| Sukses input data obat! : ");
            break;
        case 2:
            //menu 2
            pop();
            break;
        case 3:
            //menu 3
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("|*| Input tidak ada dalam menu!\n");
            printf("|*| ");
            system("pause");
        }
    }
    return 0;
}
