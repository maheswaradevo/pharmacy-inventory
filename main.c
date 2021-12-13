#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct Person
{
    char username[255];
    char password[255];
};

struct dateExp
{
    int date;
    int month;
    int year;
};

struct Item
{
    char itemName[255];
    struct dateExp exp;
};
struct Item b[50];

struct stack
{
    int top;
};
struct stack s;

void initiate()
{
    s.top = -1;
}

int isEmpty()
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (s.top == MAX - 1)
        return 1;
    else
        return 0;
}

void push(char itemName[255], char date[255], char month[255], char year[255])
{
    if (isFull())
        printf("Stack sudah penuh!\n");
    else
    {
        s.top++;
        strcpy(b[s.top].itemName, itemName);
        strcpy(b[s.top].exp.date, date);
        strcpy(b[s.top].exp.month, month);
        strcpy(b[s.top].exp.year, year);
        printf("Barang %s sudah dimasukkan", itemName);
    }
}

void pop()
{
    if (isEmpty())
        printf("Stack masih kosong!\n");
    else
    {
        printf("Data %s sudah dihapus!\n", b[s.top].itemName);
        s.top--;
    }
}

void display()
{
    if (isEmpty())
        printf("Stack masih kosong!\n");
    else
    {
        for (int i = s.top; i >= 0; i--)
        {
            printf("Item Name : %s\n", b[i].itemName);
            printf("Expired : %s/%s/%s\n", b[i].exp.date, b[i].exp.month, b[i].exp.year);
        }
    }
}

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
struct dateExp
{
    int date;
    int month;
    int year;
} dateExp;

struct Item
{
    char itemName[255];
    struct dateExp;
} Item;

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
void createacc()
{
    char user[255];
    char pwd[255];
    FILE *fptr, *fptr2;

    fptr = fopen("username.txt", "w");
    printf("Masukkan username : ");
    fgets(user, sizeof(user), stdin);
    fputs(user, fptr);
    fclose(fptr);

    fptr2 = fopen("password.txt", "w");
    printf("Masukkan password : ");
    fgets(pwd, sizeof(pwd), stdin);
    fputs(pwd, fptr2);
    fclose(fptr2);

    if ((fptr = fopen("username.txt", "r")) && (fptr2 = fopen("password.txt", "r")) != NULL)
    {
        printf("Berhasil membuat akun!");
        fclose(fptr);
        fclose(fptr2);
    }
    else
    {
        printf("Error: File gagal dibuat!");
    }
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
    if (res == 1)
    {
        printf("================\n");
        printf("  Menu Program  \n");
        printf("================\n");
        printf("1. Input Barang \n");
        printf("2. Ambil Barang \n");
        printf("4. Display Barang\n");
        printf("3. Sort Barang  \n");
        printf("Masukkan Pilihan : ");
    }
    else
    {
        //User get inventory display (view only)
    }
    return 0;
}
