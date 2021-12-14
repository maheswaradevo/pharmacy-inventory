#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pkg/stack/stack.h"
#include "pkg/auth/login.h"
#include "pkg/mode/adminmode.h"
#include "pkg/mode/usermode.h"
#include "adt/adt.h"

//START OF MAIN FUNCTION
int main()
{
    int menu, loginAdmin, loginUser;
    char acc;
    //PROTOTYPE FUNCTION OF ADMIN
    int adminMode();
    int loginAdminAcc();

    //PROTOTYPE FUNCTION OF USER
    int userMode();
    int createUserAcc();
    int loginUserAcc();
    do
    {
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
        if (menu == 1)
        {
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
        }
        else if (menu == 2)
        {
        Acc:
            printf("|+| Apakah anda sudah memiliki akun? (Y/N) : ");
            scanf("%c", &acc);
            if (acc == 'Y' && acc == 'y')
            { //if user already have account
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
    return 0;
}
//END MAIN FUNCTION
