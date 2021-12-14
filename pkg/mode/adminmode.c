#include "adminmode.h"

int adminMode()
{
    system("cls");
    int menu, pilih;
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
            //menu 1
            break;
        case 2:
            //menu 2
            break;
        case 3:
            //menu 3
            break;
        case 4:
            exit(0);
        default:
            printf("|*| Input tidak ada dalam menu!\n");
			printf("|*| "); system("pause");
		}
    }
    return 0;
}
