#include<stdio.h>
#define MAX 100
void addTransaction();
void viewTransaction();
/*
Scs3/149903/2025
Scs3/2477/2025
*/
int main()
{
    int choice;
    do
    {
        printf("\n===Customer Transaction Menu===\n");
        printf("1. Add Transaction\n");
        printf("2. View Transaction\n");
        printf("3. Exit\n");
        printf(" Enter your choice: \n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            addTransaction();
            break;

        case 2:
            viewTransaction();
            break;

        case 3:
            printf("Exiting program...\n");
            break;

        default :
            printf("Invalid choice. Try again\n");
            break;

      }
    } while (choice != 3);
    return 0;
}
void addTransaction()
{
    FILE *file;
    char customerName[50];
    float amount;

    printf("Enter customer name: ");
    scanf("%s",& customerName);

    file=fopen(customerName,"a");
    if (file==NULL)
    {
        printf("Error opening file\n");
    }

    printf("Enter transaction amount: ");
    scanf("%f",&amount);


    fprintf(file, "Customer: %s | Amount: ksh %f\n", customerName, amount );
    fclose(file);
    printf("Transaction saved successfully\n");

}
void viewTransaction()
{
    FILE *file;
    char ch,customerName[50],line[MAX];
    printf("\n--- View Invoice ---\n");
    printf("Enter Customer Name: ");
    scanf("%s",&customerName);

    file= fopen(customerName, "r");
        if (file == NULL)
        {
            printf("No record found for that customer.\n");
        }
        else
        {
            printf("\nTransactions for %s:\n", customerName);
            while (fgets(line, MAX , file))
            {
                printf("%s", line);
            }

        }
   fclose(file);
}
