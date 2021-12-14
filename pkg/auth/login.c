#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int hashValue(char *pass, int size)
{
    int value = 0;
    for (int i = 0; i < sizeof(pass) / sizeof(pass[0]); i++)
    {
        value += pass[i];
    }
    return value & size;
}
//START OF ADMIN'S FUNCTION
int adminMode()
{
    system("cls");
    int menu, pilih;
    while (1)
    {
        printf("|*|-------------------------------|*|\n");
        printf("|*|       PHARMACY INVENTORY      |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|--------------USER-------------|*|\n");
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
int loginAdminAcc()
{
    system("cls");
    char ID[255];
    char password[255];
    char *token;

    printf("|*|---------------------------------|*|\n");
    printf("|*|        PHARMACY INVENTORY       |*|\n");
    printf("|*|---------------------------------|*|\n");
    printf("|*|--------------ADMIN--------------|*|\n");
    printf("|*|---------------------------------|*|\n");
    printf("|*|            LOGIN AKUN           |*|\n");
    printf("|*|---------------------------------|*|\n");

    printf("|*| Masukkan ID : ");
    fgets(ID, sizeof(ID), stdin);
    fflush(stdin);
    printf("|*| Masukkan password : ");
    fgets(password, sizeof(password), stdin);

    if (ID == "admin" && password == "admin")
    {
        printf("|*| Login Sukses!\n");
        return 1;
    }
    else
    {
        printf("|+| Username atau Password salah!\n");
        return 0;
    }
}
//END OF ADMIN'S FUNCTION

//START OF USER'S FUNCTION
int userMode()
{
    system("cls");
    int menu, pilih;
    while (1)
    {
        printf("|*|-------------------------------|*|\n");
        printf("|*|       PHARMACY INVENTORY      |*|\n");
        printf("|*|-------------------------------|*|\n");
        printf("|*|--------------USER-------------|*|\n");
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

int createUserAcc()
{
    system("cls");
    int ID, yakin;
    char password[255], passRepeat[255];

    printf("|*|--------------------------------|*|\n");
    printf("|*|       PHARMACY INVENTORY       |*|\n");
    printf("|*|--------------------------------|*|\n");
    printf("|*|--------------USER--------------|*|\n");
    printf("|*|--------------------------------|*|\n");
    printf("|*|          CREATE AKUN           |*|\n");
    printf("|*|--------------------------------|*|\n");

    srand(time(0));
    ID = (10 * 200000) + (rand() % 100000);
    printf("|*| Create User ID Sukses!\n");
    printf("|*| ID: %d (harap ingat ID ini baik-baik!)\n", ID);
    printf("|*| Masukan password : ");
    fflush(stdin);
    fgets(password, sizeof(password), stdin);
    while (1)
    {
        printf("|*| Masukan kembali password : ");
        fgets(passRepeat, sizeof(passRepeat), stdin);
        if (strcmp(passRepeat, password) == 0)
        {
            printf("|*| Akun berhasil dibuat!\n");
            break;
        }
        else
        {
            printf("|*|Password tidak sesuai dengan sebelumnya, masukan kembali! \n");
        }
    }

    //Write to CSV File BEGIN
    FILE *fptr;
    fptr = fopen("accountForUser.csv", "a");
    fprintf(fptr, "%d,0,%s", ID, password);
    fclose(fptr);

    return 0;
}

int loginUserAcc()
{
    system("cls");
    int ID;
    char password[255];
    char *token;

    printf("|*|--------------------------------|*|\n");
    printf("|*|       PHARMACY INVENTORY       |*|\n");
    printf("|*|--------------------------------|*|\n");
    printf("|*|--------------USER--------------|*|\n");
    printf("|*|--------------------------------|*|\n");
    printf("|*|           LOGIN AKUN           |*|\n");
    printf("|*|--------------------------------|*|\n");

    printf("|*| Masukkan ID : ");
    scanf("%d", &ID);
    fflush(stdin);
    printf("|*| Masukkan password : ");
    fgets(password, sizeof(password), stdin);

    FILE *fptr;
    fptr = fopen("accountForUser.csv", "r");

    char akun[100];
    while (fgets(akun, sizeof(akun), fptr))
    {
        token = strtok(akun, ",");
        while (token != NULL)
        {
            if ((ID == atoi(token)) && (ID / 100000 == 20))
            {
                token = strtok(NULL, ",");
                token = strtok(NULL, ",");
                if (strcmp(token, password) == 0)
                {
                    fclose(fptr);
                    printf("|*| Login Sukses!\n");
                    return 1;
                }
            }
            token = strtok(NULL, ",");
        }
    }
    if (token == NULL)
    {
        printf("|+| Username atau Password salah!\n");
        return 0;
    }
}