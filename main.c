#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pkg/stack/stack.h"
#include "pkg/auth/login.h"
#include "pkg/mode/adminMode.h"
#include "pkg/mode/userMode.h"
#include "adt/adt.h"

//START OF MAIN FUNCTION
int main()
{
    int menu, loginAdmin, loginUser;
    char acc;
    do
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
            if (loginAdmin == 1)
            {
                //Login success and go to admin menu
                adminMode();
            }
            else
            {
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
                if (loginUser == 1)
                {
                    //Login success and go to user menu
                    userMode();
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
        else if (menu == 3)
        {
            exit(0);
        }
        else
        {
            printf("|+| Input tidak ada dalam menu!\n");
        }
        printf("\n|+| Press enter to continue...");
    } while (getchar());
    return 0;
}
//END MAIN FUNCTION
