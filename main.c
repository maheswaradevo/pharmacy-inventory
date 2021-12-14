#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

//Prototype Function of User
int createUserAcc();
int loginUserAcc();

//Prototype Function of Admin
int loginAdminAcc();

int main(){
    int menu;
	
    do{
    	printf("|+|----------------------------------|+|\n");
    	printf("|+|     |   PHARMACY INVENTORY  |    |+|\n");
    	printf("|+|----------------------------------|+|\n");
    	printf("|+|     |    1. ADMIN           |    |+|\n");
    	printf("|+|----------------------------------|+|\n");
    	printf("|+|     |    2. USER            |    |+|\n");
    	printf("|+|----------------------------------|+|\n");
    	printf("|+|     |    3. EXIT            |    |+|\n");
    	printf("|+|----------------------------------|+|\n");
        printf("|+| Pilih Menu : ");
        scanf("%d", &menu);
	
	//Admin
    	if(menu == 1){
	    loginAdmin:
	    int loginAdmin = 0;
            loginAdmin = loginAdminAcc();
	    if (loginAdmin == 1){
	        //Login success and go to user menu
	    }
	    else{
                //Login failed and go to login again
		goto loginAdmin;
	    }
	else if(menu == 2){
	    loginUser:
	    int loginUser = 0;
            loginUser = loginUserAcc();
	    if (loginUser == 1){
	        //Login success and go to user menu
	    }
	    else{
                //Login failed and go to login again
		goto loginUser;
	    }
	else if(menu == 3){
	    exit(0);
	}
	else{
	    printf("|+| Input tidak ada dalam menu!\n");
	}
    printf("\n|+| Press enter to continue...");
    }while(getchar());
    
    return 0;
}

int createUserAcc(){
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
    ID = (10*200000)+(rand()%100000);
    printf("|*| ID: %d (harap ingat ID ini baik-baik!)\n", ID);
    printf("|*| Masukan password : ");
    fflush(stdin);
    fgets(password, sizeof(password), stdin);
    while(1){
         printf("|*| Masukan kembali password : ");
	 fgets(passRepeat, sizeof(passRepeat), stdin);
	 if (strcmp(passRepeat, password) == 0){
	      printf("|*| Akun berhasil dibuat!\n");
	      break;
	 }else{
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

int loginUserAcc(){
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
    while (fgets(akun, sizeof(akun), fptr)){
    	token = strtok(akun, ",");
        while (token != NULL){
             if ((ID == atoi(token)) && (ID / 100000 == 20)){
                 token = strtok(NULL, ",");
		 token = strtok(NULL, ",");
	         if(strcmp(token, password) == 0){
	              fclose(fptr);
	              printf("|*| Login Sukses!\n");
	              return 1;
	         }
	     }
             token = strtok(NULL, ",");
        }
    }
    if (token == NULL){
        printf("|+| Username atau Password salah!\n");
        return 0;
    }
}

int loginAdminAcc(){
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
    
    if(ID == "admin" && password == "admin"){
        printf("|*| Login Sukses!\n");
        return 1;
    }
    else{
    	printf("|+| Username atau Password salah!\n");
	return 0;
    }
}
