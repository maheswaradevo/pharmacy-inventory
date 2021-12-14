#ifndef LOGIN_DOT_H
#define LOGIN_DOT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int hashValue(char *pass, int size);

//ADMIN
int adminMode();
int loginAdminAcc();

//USER
int userMode();
int createUserAcc();
int loginUserAcc();

#endif
