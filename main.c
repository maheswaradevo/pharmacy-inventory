#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pkg/stack/stack.h"
#include "pkg/auth/login.h"
#include "adt/adt.h"

//START OF MAIN FUNCTION

int main()
{
    initiate();
    s.counter = 0;
    int menu, loginAdmin, loginUser;
    char acc, quit;

    char itemName;
    int pilih, pilih2, ch, tgl, bln, thn;

    while (1)
    {
    mainmenu:
        system("cls");
        printf("|+|----------------------------------|+|\n");
        printf("|+|     |   PHARMACY INVENTORY  |    |+|\n");
        printf("|+|----------------------------------|+|\n");
        printf("|+|     |       MAIN MENU       |    |+|\n");
        printf("|+|----------------------------------|+|\n");
        printf("|+|     |    1. ADMIN           |    |+|\n");
        printf("|+|----------------------------------|+|\n");
        printf("|+|     |    2. USER            |    |+|\n");
        printf("|+|----------------------------------|+|\n");
        printf("|+|     |    3. EXIT PROGRAM    |    |+|\n");
        printf("|+|----------------------------------|+|\n");
        printf("|+| Pilih Menu : ");
        scanf("%d", &menu);

        //Admin
        switch (menu)
        {
        case 1:
        loginAdmin:
            loginAdmin = loginAdminAcc();
            if (loginAdmin == 1)
            {
                //Login success and go to admin menu
                while (1)
                {
                    system("cls");
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
                        s.counter++;
                        printf("|*| Sukses input data obat!\n");
                        printf("|*| ");
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        //menu 2
                        pop();
                        s.counter--;
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
                        goto mainmenu;
                    default:
                        printf("|*| Input tidak ada dalam menu!\n");
                        printf("|*| ");
                        system("pause");
                    }
                }
            }
            else
            {
                //Login failed and go to login again
                goto loginAdmin;
            }
            break;
        case 2:
            printf("|+| Hello!\n");
            printf("|+| Apakah anda sudah memiliki akun? (Y/N) : ");
            fflush(stdin);
            scanf("%c", &acc);
            if (acc == 'Y' || acc == 'y')
            { //if user already have account
            loginUser:
                loginUser = loginUserAcc();
                if (loginUser == 1)
                {
                    //Login success and go to user menu
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
                        scanf("%d", &pilih2);

                        switch (pilih2)
                        {
                        case 1:
                            system("cls");
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
                                bubbleSortDate(s.counter);
                                displaySortedDate(s.counter);
                                printf("|*| ");
                                system("pause");
                                break;
                            case 2:
                                //menu 2
                                bubbleSortName(s.counter);
                                displaySortedName(s.counter);
                                printf("|*| ");
                                system("pause");
                                break;
                            }
                            break;
                        case 2:
                            goto mainmenu;
                        default:
                            printf("|*| Input tidak ada dalam menu!\n");
                            printf("|*| ");
                            system("pause");
                        }
                    }
                }
                else
                {
                    //Login failed and go to login again
                    goto loginUser;
                }
            }
            else
            { //if user don't have account
                createUserAcc();
            }
            break;
        case 3:
            printf("|+| Apakah anda yakin untuk keluar dari program? (Y/N) : ");
            fflush(stdin);
            scanf("%c", &quit);
            if (quit == 'Y' || quit == 'y')
            {
                printf("|+| Terima kasih sudah menggunakan program ini!\n\n");
                exit(0);
            }
            else if (quit == 'N' || quit == 'n')
            {
                continue;
            }
            else
            {
                printf("|+| Input yang anda masukkan tidak valid!\n");
                printf("|+| ");
                system("pause");
            }
            break;
        default:
            printf("|+| Input tidak ada dalam menu!\n");
            printf("|+| ");
            system("pause");
        }
    }

    return 0;
}
//END MAIN FUNCTION
