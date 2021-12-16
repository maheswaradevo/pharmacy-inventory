#include "usermode.h"
#include "../stack/stack.h"
#include "../../adt/adt.h"

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
                Bubblesort(s.counter);
                displayStack();
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
