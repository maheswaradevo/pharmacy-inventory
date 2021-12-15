#ifndef STACK_DOT_H
#define STACK_DOT_H

#include <stdio.h>
#include <string.h>
#include "stack.c"
#define MAX 50

void initiate();
int isEmpty();
int isFull();
void push(char itemName[255], int date, int month, int year);
void pop();
void display();

#endif
