#include "usermode.h"

int userMode()
{
    system("cls");
    int menu, pilih;
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
            printf("|*| ");
            system("pause");
            break;
        case 2:
            return 0;
        default:
            printf("|*| Input tidak ada dalam menu!\n");
			printf("|*| "); system("pause");
        }
    }
    return 0;
}
