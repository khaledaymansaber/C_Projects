
#include "database.h"
struct customer arr[size];
int counter;
bool freq[200000]={0};
int main()
{
    while(1)
   {
    printf("welcome in bank management system\n");
    printf("=======================================\n");
    printf("please select one of the following options :\n");
    printf("\n");
    printf("1-create a new customer\n");
    printf("2-edit customer\n");
    printf("3-delete customer\n");
    printf("4-print customer data\n");
    printf("5-cash transfer from customer to another\n");
    printf("6-exit\n\n");
    printf("please enter your choice:");
    int choice;
    scanf("%i",&choice);
    switch(choice)
    {
     case 1:
       create_new_customer();
      break;
     case 2:
     edit_customer();
      break;
     case 3:
      delete_customer();
      break;
     case 4:
      print_customer();
      break;
     case 5:
     transfer_cash();
      break;
     case 6:
      return 0;
      break;
      default:
      //
      break;
    }
   }


    return 0;
}
