#include "adminmode.h"

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
        printf("|*|        1. MENU 1              |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|        2. MENU 2              |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|        3. MENU 3              |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|        4. MENU 4              |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|        5. MENU 5	          |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|        6. EXIT                |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*| Pilih Menu :");
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
            break;
        case 5:
            //menu 5
            break;
        case 6:
            exit(0);
        default:
            printf("|*| Input tidak ada dalam menu!\n");
        }
    }
    return 0;
}
