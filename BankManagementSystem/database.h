#ifndef k
#define k
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define size 200000
struct customer
{
    char name[50];
    double cash;
    char type[7];
    int id;
};
extern struct customer arr[size];
extern int counter;
extern bool freq[200000];
void create_new_customer();
void print_customer();
void edit_customer();
#endif
