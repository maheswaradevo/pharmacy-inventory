#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//Abstract Data Type
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

//Stack Function
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


void push(char itemName[255], int date, int month, int year)
{
    if (isFull())
        printf("Stack sudah penuh!\n");
    else
    {
        s.top++;
        strcpy(b[s.top].itemName, itemName);
        b[s.top].exp.date = date;
        b[s.top].exp.month = month;
        b[s.top].exp.year = year;
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
            printf("Expired : %d/%d/%d\n", b[i].exp.date, b[i].exp.month, b[i].exp.year);
        }
    }

//PROTOTYPE FUNCTION OF ADMIN
int adminMode();
int loginAdminAcc();

//PROTOTYPE FUNCTION OF USER
int userMode();
int createUserAcc();
int loginUserAcc();

//START OF MAIN FUNCTION
int main(){
    int menu, loginAdmin, loginUser;
    char acc;
	
    do{
	system("cls");
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
            loginAdmin = loginAdminAcc();
	    if (loginAdmin == 1){
	        //Login success and go to admin menu
		adminMode();
	    }
	    else{
                //Login failed and go to login again
		goto loginAdmin;
	    }
	else if(menu == 2){
	    Acc:
	    printf("|+| Apakah anda sudah memiliki akun? (Y/N) : ");
	    scanf("%c", &acc);
	    if(acc == 'Y' && acc == 'y'){ //if user already have account
	        loginUser:
                loginUser = loginUserAcc();
	        if (loginUser == 1){
	            //Login success and go to user menu
		    userMode():
	        }
	        else{
                    //Login failed and go to login again
		    goto loginUser;
	        }
	    }
	    else{ //if user don't have account
                createUserAcc();
		goto Acc;
	    }
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
//END MAIN FUNCTION
  
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
int adminMode(){
    system("cls");
    int menu;
    while (1){
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

        switch (pilih) {
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
//END OF ADMIN'S FUNCTION

//START OF USER'S FUNCTION
int userMode(){
    system("cls");
    int menu;
    while (1){
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


        switch (pilih) {
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
    printf("|*| Create User ID Sukses!\n");
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
//END OF USER'S FUNCTION
