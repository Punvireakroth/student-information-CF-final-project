#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// functions to generate biils
void generateBillHeader(char name[50],char date[30]){             
    printf("\n\n");
       printf("\t       ADV.Restaurant");
       printf("\n\t       ---------------");
       printf("\nDate:%s",date);
       printf("\nInvoice To: %s",name);
       printf("\n");
       printf("-------------------------------------\n");
       printf("Items\t\t");
       printf("Qty\t\t");
       printf("Total\t\t");                         
       printf("\n-----------------------------------\n");
       printf("\n\n");
}

void generateBillFooter(float total){
   printf("\n");
    float dis=0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal+2*cgst;
    printf("----------------------------------------\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n--------------------------------------");
    printf("\nGrand Total\t\t\t%.2f",grandTotal);
    printf("\n-------------------------------------------\n");
}    

int main()
{
    // dashboard
    printf("\t=====================STUDENT INFORMATION==============");
    printf("\n1. Generate Invoice");
    printf("\n2. Show all Invoices");
    printf("\n3. Search Invoice");
    printf("\n4. Exit from the program");

    return 0;
}