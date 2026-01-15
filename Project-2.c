/*
SCS3/2605/2025   : MAINA EMMANUEL IRUNGU
SCS3/2606/2025   : ADAMS MUGAMBI
SCS3/150466/2025 : ALLEN MUGOH
SCS3/2481/2025   : CHOGE VICTOR KIBET
SCS3/2484/2025   : WANJIRU MWANGI

Link: https://github.com/choge872/Hotel-order-system
*/

#include<stdio.h>
#include<string.h>

#define MAX 50
int placeOrder();
int viewOrder();

typedef struct{
    char food[10];
    float price;
    int qty;
    float total;
}CUSTOMER;

int main(){
    int choice;

    do{
        printf("********RESTAURANT ORDERING SYSTEM********\n");
        printf("Select a choice(1-4)\n");
        printf("1.Place order\n");
        printf("2.View order\n");
        printf("3.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                placeOrder();
                break;
            case 2:
                viewOrder();
                break;
            case 3:
                printf("Thank you for choosing our service.Have a nice time\n");
                printf("Exiting...\n");
                choice = 3;
                break;
            default:
                printf("Invalid choice!Try again!\n");

        }
    }while(choice != 3);

    return 0;
}

int placeOrder(){
    int choice, count = 0, i;
    float bill;
    char name[30], filename[30];
    char c;
    CUSTOMER cst[MAX];

    printf("Enter your name: ");
    scanf(" %[^\n]", name);
    do{
        printf("***************MENU***************\n");
        printf("-----------------------------------\n");
        printf("  %-10s %-6s\n","FOOD", "COST(KSH)");
        printf("1.%-10s %-6s\n","Burger", "300.00");
        printf("2.%-10s %-6s\n","Pizza", "1000.00");
        printf("3.%-10s %-6s\n","Rice", "100.00");
        printf("4.%-10s %-6s\n","Ugali", "50.00");
        printf("5.%-10s %-6s\n","Smocha", "60.00");
        printf("------------------------------------\n");

        do{
            printf("From the menu displayed, select the food you would like to order: ");
            scanf("%d", &choice);

            switch(choice){
                case 1:
                    strcpy(cst[count].food, "Burger");
                    cst[count].price = 300.00;
                    break;
                case 2:
                    strcpy(cst[count].food, "Pizza");
                    cst[count].price = 1000.00;
                    break;
                case 3:
                    strcpy(cst[count].food, "Rice");
                    cst[count].price = 100.00;
                    break;
                case 4:
                    strcpy(cst[count].food, "Ugali");
                    cst[count].price = 50.00;
                    break;
                case 5:
                    strcpy(cst[count].food, "Smocha");
                    cst[count].price = 60.00;
                    break;
                default:
                    printf("Invalid choice!Try again!\n");
            }
        }while(choice < 1 || choice > 5);

        printf("How many of the selected food item would you like to order: ");
        scanf("%d", &cst[count].qty);
        cst[count].total = cst[count].price * cst[count].qty;

        printf("Would you like to order another food item(y/n): ");
        scanf(" %c", &c);
        count++;
    }while(c == 'y');

    for(i = 0; i < count; i++){
        bill += cst[i].total;
    }

    FILE *pFile;
    sprintf(filename, "%s.txt", name);
    pFile = fopen(filename, "w");

    if(pFile == NULL){
        printf("COULD NOT OPEN FILE!\n");
    }else{
        fprintf(pFile, "Name: %s\n", name);
        fprintf(pFile, "***************ORDER***************\n");
        fprintf(pFile, "%-10s %-9s %-3s %s\n","FOOD", "COST(KSH)", "QTY", "TOTAL");

        fprintf(pFile, "-----------------------------------\n");
        for(i = 0; i < count; i++){
            fprintf(pFile, "%-10s %-9.2f %-3d %.2f\n", cst[i].food, cst[i].price, cst[i].qty, cst[i].total);
        }
        fprintf(pFile, "-----------------------------------\n");
        fprintf(pFile, "Total Bill: %.2f\n", bill);
    }

    fclose(pFile);
}
int viewOrder(){
    char name[30];
    char filename[40];
    char lines[1000];

    FILE *pFile;

    printf("Enter the name of the customer to generate order: ");
    scanf(" %[^\n]", name);

    sprintf(filename, "%s.txt", name);
    pFile=fopen(filename,"r");

    if(pFile == NULL){
        printf("\nCOULD NOT OPEN FILE!\n");
        return 1;
    }
    else{

        while(fgets(lines, sizeof(lines), pFile)){
            printf("%s", lines);
        }
    }
    fclose(pFile);
}
//https://github.com/choge872/Hotel-order-system/tree/190fe12251ec5c8c28333e6d7e5d1122eb406451
