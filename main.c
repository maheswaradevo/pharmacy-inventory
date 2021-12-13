#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char username[255];
    char password[255];
} Person;

int hashValue(char *pass, int size)
{
    int value = 0;
    for (int i = 0; i < sizeof(pass) / sizeof(pass[0]); i++)
    {
        value += pass[i];
    }
    return value % size;
}

int login(char username[], char password[])
{
    if ((strcmp(username, "admin") == 0) && (strcmp(password, "admin") == 0))
        return 1;
    else
        return 0;
}

int main()
{
    int res;
    struct Person p;
    printf("Pharmacy Inventory\n");

    //Login menu to user or admin
    printf("=================\n");
    printf("      Login      \n");
    printf("=================\n");
    printf("Username : ");
    fflush(stdin);
    scanf("%[^\n]s", &p.username);
    printf("Password : ");
    fflush(stdin);
    scanf("%[^\n]s", &p.password);
    res = login(p.username, p.password);
    if (res == 1)
    {
        printf("================\n");
        printf("  Menu Program  \n");
        printf("================\n");
        printf("1. Input Barang \n");
        printf("2. Ambil Barang \n");
        printf("3. Sort Barang  \n");
        printf("Masukkan Pilihan : ");
    }
    else
    {
        //User get inventory display (view only)
    }
    return 0;
}