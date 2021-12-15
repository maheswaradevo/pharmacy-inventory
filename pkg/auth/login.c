#include "login.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../adt/adt.h"
#include <malloc.h>

int hashValue(char *pass, int size)
{
    int value = 0;
    for (int i = 0; i < sizeof(pass) / sizeof(pass[0]); i++)
    {
        value += pass[i];
    }
    return value & size;
}

void insertToHashTable(char *username, char *pass, int token)
{
    struct Person *p = (struct Person *)malloc(sizeof(struct Person));
    strcpy(p->username, username);
    strcpy(p->password, pass);
    p->token = token;
    int hashIndex = hashValue(pass, SIZE);
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->password != NULL)
    {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = p;
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashArray[i] != NULL)
        {
            printf("Tabel ke-%d\n", i + 1);
            printf("Token    :  %d\n", hashArray[i]->token);
            printf("Password :  %s\n", hashArray[i]->password);
        }
        else
        {
            printf("Token :    [-----]\n");
            printf("Password : [-----]\n");
        }
    }
}

//START OF ADMIN'S FUNCTION
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
    fflush(stdin);
    gets(ID);
    printf("|*| Masukkan password : ");
    fflush(stdin);
    gets(password);
    if (strcmp(ID, "admin") == 0 && strcmp(password, "admin") == 0)
    {
        printf("|*| Login Sukses!\n");
        return 1;
    }
    else
    {
        printf("|+| Username atau Password salah!\n");
        printf("|*| ");
        system("pause");
        return 0;
    }
}
//END OF ADMIN'S FUNCTION

//START OF USER'S FUNCTION
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
            printf("|*| Password tidak sesuai dengan sebelumnya, masukan kembali! \n");
        }
    }

    //Write to CSV File BEGIN
    FILE *fptr;
    fptr = fopen("accountForUser.csv", "a");
    fprintf(fptr, "%d,%s", ID, password);
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
        printf("|*| ");
        system("pause");
        return 0;
    }
}
//END OF USER'S FUNCTION
