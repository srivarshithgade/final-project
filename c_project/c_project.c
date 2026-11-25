
#include <stdio.h>
#include <string.h>

#define MAX 5

int main()
{
    int ids[MAX];
    char names[MAX][20];
    float prices[MAX];
    int quantities[MAX];

    int count = 0;
    int choice;
    int i, id, pos, newQty;

    do
    {
        printf("\n=================================\n");
        printf("   PRODUCT INVENTORY SYSTEM\n");
        printf("=================================\n");

        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Display All Products\n");
        printf("4. Update Quantity\n");
        printf("5. Exit\n");

        printf("---------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");

            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice)
        {
            
            case 1:

                if (count == MAX)
                {
                    printf("\nInventory is full!\n");
                    break;
                }

                printf("\nEnter Product ID: ");
                if (scanf("%d", &id) != 1)
                {
                    printf("Invalid ID!\n");
                    while (getchar() != '\n');
                    break;
                }

                
                pos = -1;

                for (i = 0; i < count; i++)
                {
                    if (ids[i] == id)
                    {
                        pos = i;
                        break;
                    }
                }

                if (pos != -1)
                {
                    printf("Product ID already exists!\n");
                    break;
                }

                ids[count] = id;

                printf("Enter Product Name: ");
                scanf(" %19[^\n]", names[count]);

                printf("Enter Product Price: ");
                if (scanf("%f", &prices[count]) != 1 ||
                    prices[count] < 0)
                {
                    printf("Invalid price!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Product Quantity: ");
                if (scanf("%d", &quantities[count]) != 1 ||
                    quantities[count] < 0)
                {
                    printf("Invalid quantity!\n");
                    while (getchar() != '\n');
                    break;
                }

                count++;

                printf("\nProduct added successfully!\n");
                break;


            
            case 2:

                if (count == 0)
                {
                    printf("\nInventory is empty!\n");
                    break;
                }

                printf("\nEnter Product ID to search: ");

                if (scanf("%d", &id) != 1)
                {
                    printf("Invalid ID!\n");
                    while (getchar() != '\n');
                    break;
                }

                pos = -1;

                for (i = 0; i < count; i++)
                {
                    if (ids[i] == id)
                    {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1)
                {
                    printf("\nProduct not found!\n");
                }
                else
                {
                    printf("\nProduct Found!\n");
                    printf("-----------------------------\n");
                    printf("ID       : %d\n", ids[pos]);
                    printf("Name     : %s\n", names[pos]);
                    printf("Price    : %.2f\n", prices[pos]);
                    printf("Quantity : %d\n", quantities[pos]);
                    printf("-----------------------------\n");
                }

                break;


            
            case 3:

                if (count == 0)
                {
                    printf("\nInventory is empty!\n");
                }
                else
                {
                    printf("\n========== PRODUCT LIST ==========\n");

                    printf("%-10s %-20s %-10s %-10s\n",
                           "ID", "NAME", "PRICE", "QUANTITY");

                    printf("--------------------------------------------------\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("%-10d %-20s %-10.2f %-10d\n",
                               ids[i],
                               names[i],
                               prices[i],
                               quantities[i]);
                    }

                    printf("--------------------------------------------------\n");
                    printf("Total Products: %d\n", count);
                }

                break;


            
            case 4:

                if (count == 0)
                {
                    printf("\nInventory is empty!\n");
                    break;
                }

                printf("\nEnter Product ID to update: ");

                if (scanf("%d", &id) != 1)
                {
                    printf("Invalid ID!\n");
                    while (getchar() != '\n');
                    break;
                }

                pos = -1;

                for (i = 0; i < count; i++)
                {
                    if (ids[i] == id)
                    {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1)
                {
                    printf("\nProduct not found!\n");
                }
                else
                {
                    printf("Product Name: %s\n", names[pos]);
                    printf("Current Quantity: %d\n",
                           quantities[pos]);

                    printf("Enter New Quantity: ");

                    if (scanf("%d", &newQty) != 1 ||
                        newQty < 0)
                    {
                        printf("Invalid quantity!\n");
                        while (getchar() != '\n');
                        break;
                    }

                    quantities[pos] = newQty;

                    printf("\nQuantity updated successfully!\n");
                    printf("Updated Quantity: %d\n",
                           quantities[pos]);
                }

                break;


            
            case 5:

                printf("\nExiting Product Inventory System.\n");
                printf("Thank you!\n");
                break;


            
            default:

                printf("\nInvalid choice! Enter 1-5.\n");
        }

    } while (choice != 5);

    return 0;
}