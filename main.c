#include <stdio.h>
#include <stdlib.h>

struct Person
{
    char username[255];
    char password[255];
} Person;

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

void createacc(){
    char user[255];
    char pwd[255];
    File *fptr, *fptr2;
    
    fptr = fopen("username.txt", "w");
    printf("Masukkan username : ");
    fgets(user, sizeof(user), stdin);
    fputs(user, fptr);
    fclose(fptr);
    
    fptr2 = fopen("password.txt", "w");
    printf("Masukkan password : ");
    fgets(pass, sizeof(pass), stdin);
    fputs(pass, fptr2);
    fclose(fptr2);
    
    if((fptr = fopen("username.txt", "r")) && (fptr2 = fopen("password.txt", "r")) != NULL){
        printf("Berhasil membuat akun!");
        fclose(fptr);
        fclose(fptr2);
    }else{
        printf("Error: File gagal dibuat!");
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
    scanf("%[^\n]s", &p.username);
    printf("Password : ");
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
