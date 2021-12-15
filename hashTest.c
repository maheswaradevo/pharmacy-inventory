#include "adt/adt.h"
#include "pkg/auth/login.h"

int main()
{
    char pass, user;
    dummy = (struct dataItem *)malloc(sizeof(struct dataItem));
    dummy->key = NULL;
    dummy->itemName = NULL;
    printf("Masukkan username :");
    scanf("%[^\n]s", &user);
    printf("Masukkan password :");
    scanf("%[^\n]s", &pass);
    insertHashTable(pass, user);
    for (int i = 0; i < SIZE; i++)
    {
        if (hashArray[i] != NULL)
        {
            printf("Key : %s\n", hashArray[i]->key);
            printf("Username : %s\n", hashArray[i]->itemName);
        }
    }
    return 0;
}