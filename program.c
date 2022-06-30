#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structure is the user define data type
struct items{
    char item[20];
    // float price;
    float score;

    int qty;
};

struct orders{
    char costumer[20];
    char date[50];
    int numOfItems;
    struct items itm[50];
}; 


// functions to generate biils
void generateBillHeader(char name[50],char date[30]){             
    printf("\n\n");
       printf("\t       Student Information");
       printf("\n\t       ---------------");
       printf("\nDate:%s",date);
       printf("\nName of the student: %s",name);
       printf("\n");
       printf("---------------------------------------------------------------------------------------------------------------\n");
       printf("Course\t\t\t\t");
       printf("Credit\t\t\t\t");
       printf("Total Score\t\t\t\t");                         
       printf("\n-------------------------------------------------------------------------------------------------------------\n");
       printf("\n\n");
}

void generateBillBody(char item[30],int qty,float score){
    printf("%s\t\t\t\t",item);
    printf("%d\t\t\t\t",qty);
    printf("%.2f\t\t\t\t",score);
    printf("\n");
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
    float total;
    int opt,n;
    struct orders ord;
    struct orders order;
    char saveBill = 'y';
    FILE *fp;
    // dashboard
    printf("\t=====================STUDENT INFORMATION==============");
    printf("\n\nPlease choose your prefer option");
    printf("\n\n1. Generate Student information");
    printf("\n2. Show all Student information");

    printf("\n\nYour choice.\t");
    scanf("%d", &opt);
    fgetc(stdin);
    switch(opt){
        case 1:
        system("clear");
        printf("\nPlease enter the name of the Student:\t");
        fgets(ord.costumer,50,stdin);
        ord.costumer[strlen(ord.costumer)-1]=0; // at the end of the string we are assigning 0 orderwise it'll save the \n also 
        strcpy(ord.date,__DATE__); // copy and store the current date 
        ord.numOfItems = n;
        printf("\nPlease enter the number of Courses student take:\t");
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the Course name %d:\t", i+1);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("Please enter the Credit:\t");
            scanf("%d",&ord.itm[i].qty);
            printf("Please enter the Score student got:\t");
            // scanf("%f",&ord.itm[i].price);
            scanf("%f",&ord.itm[i].score);

            total += ord.itm[i].qty * ord.itm[i].score;
        }
        // Show the result
        generateBillHeader(ord.costumer,ord.date);
        for(int i=0;i<n;i++){
            generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].score);
        }
        // generateBillFooter(total);

        printf("\nDo you want to save the invoice[y/n]:\t");
        scanf("%s",&saveBill);

        if(saveBill == 'y'){
            fp = fopen("StudentInformation.dat", "a+");
            fwrite(&ord, sizeof(struct orders),1,fp);
             //pointer of the structure
            if(fwrite != 0){
                printf("\nSuccessfully Save");
            }
            else{
                printf("\nError Saving"); 
            }
        }
        break;
        case 2:
        system("clear");
        fp = fopen("StudentInformation.dat","r");
        printf("=============================================================================================");
        printf("\n ******Your Previous Student information******\n");
        while(fread(&order,sizeof(struct orders),1,fp)){
            generateBillHeader(order.costumer, order.date);
            for(int i = 0; i < n+1;i++){
                generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].score);
                
                // total += order.itm[i].qty * order.itm[i].score;
            }
            // generateBillFooter(total);
        }
        fclose(fp);
        break;
    }
    printf("\n\n");


    return 0;
}