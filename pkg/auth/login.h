#ifndef LOGIN_DOT_H
#define LOGIN_DOT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "login.c"

int hashValue(char *pass, int size);

//ADMIN
int loginAdminAcc();

//USER
int createUserAcc();
int loginUserAcc();

#endif
