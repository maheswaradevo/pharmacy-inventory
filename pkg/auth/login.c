#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <malloc.h>
#include "login.h"
#include "../../adt/adt.h"

int hashValue(char *pass, int size)
{
    int value = 0;
    for (int i = 0; i < sizeof(pass) / sizeof(pass[0]); i++)
    {
        value += pass[i];
    }
    return value & size;
}

void insertToHashTable(char *pass, int token)
{
    struct Person *p = (struct Person *)malloc(sizeof(struct Person));
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

void displayHashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashArray[i] != NULL)
        {
            printf("|*| Tabel ke-%d\n", i + 1);
            printf("|*| ID       :  %d\n", hashArray[i]->token);
            printf("|*| Password :  %s\n\n", hashArray[i]->password);
        }
        else
        {
            printf("|*| ID       : [-----]\n");
            printf("|*| Password : [-----]\n\n");
        }
    }
}

int readFileForHashTable()
{
    int counter = 0, token;
    char *ptr;
    char tmp[50], password[50];
    FILE *fp = fopen("accountForUser.txt", "r");
    if (fp == NULL)
    {
        printf("File tidak bisa dibuka\n");
        exit(1);
    }
    while (fgets(tmp, sizeof(tmp), fp) != NULL)
    {
        if (strcmp(tmp, "###\n") == 0)
        {
            fgets(tmp, sizeof(tmp), fp);
            sscanf(tmp, "%50[^\n]\n", &tmp);
            fflush(stdin);
            token = (int)strtol(tmp, &ptr, 10);
            fgets(tmp, sizeof(tmp), fp);
            sscanf(tmp, "%50[^\n]\n", &password);
            fflush(stdin);
            perArray[counter].token = token;
            strcpy(perArray[counter].password, password);
            insertToHashTable(password, token);
            counter++;
        }
    }
    fclose(fp);
    return 0;
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
    char password[255], passRepeat[255], username[255];

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
    printf("|*| Username         : ");
    fflush(stdin);
    fgets(username, sizeof(username), stdin);
    printf("|*| Masukan password : ");
    fflush(stdin);
    fgets(password, sizeof(password), stdin);
    insertToHashTable(password, ID);
    while (1)
    {
        printf("|*| Masukan kembali password : ");
        fgets(passRepeat, sizeof(passRepeat), stdin);
        if (strcmp(passRepeat, password) == 0)
        {
            printf("|*| Akun berhasil dibuat!\n");
            printf("|*| ");
            system("pause");
            break;
        }
        else
        {
            printf("|*| Password tidak sesuai dengan sebelumnya, masukan kembali! \n");
        }
    }

    //Write to CSV File BEGIN
    FILE *fptr, *fp;
    fptr = fopen("accountForUser.csv", "a");
    fprintf(fptr, "%d,%s", ID, password);
    fp = fopen("accountForUser.txt", "a");
    fprintf(fp, "###\n%d\n", ID);
    fprintf(fp, "%s", password);
    fclose(fptr);
    fclose(fp);
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
