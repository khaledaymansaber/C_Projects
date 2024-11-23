
#include "database.h"


void create_new_customer()
{
    if (counter >= size) {
        printf("Customer array is full.\n");
        return;
    }

 printf("please enter  name of customer %i\n",counter+1);
 scanf("%s",&arr[counter].name);

 //check if id is exist already before insert it
 while(1){
    printf("please enter id of customer %i (must be number from 0 to 200000) \n",counter+1);
    int number;
    scanf("%d",&number);
    if(freq[number]==1)
     printf("id already exists. Please enter a different id.\n");
     else
     {
     arr[counter].id =number;
     freq[number]=1;
     break;
     }

 }

 printf("please enter type of customer %i(credit or debit)\n",counter+1);
 scanf("%s",&arr[counter].type);
 printf("please enter cash of customer %i%\n",counter+1);
 scanf("%lf",&arr[counter].cash);
 counter++;
 }
 void print_customer()
 {
   printf("please enter id of customer you need to print\n");
  //check if id is exist already or not to output
    int id;
        do {
        scanf("%d", &id);
        if (freq[id]==0) {
            printf(" id not exists. Please enter id is exist.\n");
        }
    } while (freq[id]==0);

   for(int i=0;i<counter;i++)
   {
       if(id==arr[i].id)
       {
        printf("name of customer %i :%s \n",i+1,arr[i].name);
        printf("id of customer %i :%d \n",i+1,arr[i].id);
        printf("cash of customer %i :%lf \n",i+1,arr[i].cash);
        printf("type of customer %i :%s \n",i+1,arr[i].type);
        break;
       }
   }

 }

void edit_customer()
{
   printf("please enter id of customer you need to edit\n");
  //check if id is exist already or not to edit
    int id;
        do {
        scanf("%d", &id);
        if (freq[id]==0) {
            printf(" id not exists. Please enter id is exist to edit.\n");
        }
    } while (freq[id]==0);

   for(int i=0;i<counter;i++)
   {
      if(id==arr[i].id)
       { int choice;
         printf("if you want to want to edit name write 1 otherwise 0\n");
          scanf("%d", &choice);
        if(choice)
         scanf("%s",&arr[i].name);

         printf("if you want to want to edit cash write 1 otherwise 0\n");
          scanf("%d", &choice);
        if(choice)
         scanf("%lf",&arr[i].cash);

          printf("if you want to want to edit type write 1 otherwise 0\n");
          scanf("%d", &choice);
        if(choice)
         scanf("%s",&arr[i].type);

          printf("if you want to want to edit id write 1 otherwise 0\n");
          scanf("%d", &choice);
        if(choice)
        {
         freq[arr[i].id]=0;
           scanf("%d",&arr[i].id);
             freq[arr[i].id]=1;
        }
        break;
       }
   }
}

void transfer_cash()
{
 int id_transfer,id_recive;
 double cash_transfer;


  //check if ids are exist already or not
        do {
        printf("please enter id of customer you need to transfer from it\n");
        scanf("%d", &id_transfer);
        printf("please enter id of customer which will  receive cash \n");
          scanf("%d", &id_recive);
        if (freq[id_transfer]==0||freq[id_recive]==0) {
            printf(" ids not exists. Please enter ids are exist.\n");
        }
    } while(freq[id_transfer]==0||freq[id_recive]==0);

double cash;
  do {
      printf("please enter money which will be transfer from his cash\n");
      scanf("%lf",&cash_transfer);

        for(int i=0;i<counter;i++)
        {
          if(id_transfer==arr[i].id)
           {
            cash=arr[i].cash;
             break;
           }
        }
        if (cash<cash_transfer)
       printf("cash must be transfered is greater than balance ,please enter cash less than or equal %lf .\n",cash);

    } while(cash<cash_transfer);
  bool check1=0,check2=0;
   for(int i=0;i<counter;i++)
   {
       if(id_transfer==arr[i].id)
       {
        arr[i].cash-=cash_transfer;
        check1=1;
       }
        if(id_recive==arr[i].id)
       {
        arr[i].cash+=cash_transfer;
        check2=1;
       }
       if(check2==1&&check1==1)
        break;
   }
}

void delete_customer()
{
    int id_deleted;
   do {
        printf("please enter id of customer you need to delete\n");
        scanf("%d", &id_deleted);
        if (freq[id_deleted]==0) {
            printf(" ids not exists. Please enter ids are exist.\n");
        }
    } while(freq[id_deleted]==0);

    int location=-1;
        for(int i=0;i<counter;i++)
        {
          if(id_deleted==arr[i].id)
           {
            location=i;
             break;
           }
        }
        if(location==counter-1)
       counter--;
         else
         {
        for(int i=location;i<counter-1;i++)
          arr[i]=arr[i+1];
          counter--;
          }
       printf(" ids are %d\n",counter);
     freq[id_deleted]=0;
        }


