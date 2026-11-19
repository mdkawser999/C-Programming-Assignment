#include <stdio.h>

typedef struct Book {
    int id;
    char title[50];
    char author[50];
    float price;
    int quantity;
} Book;

int main() {
    Book books[10];
    int searchID, buyID, buyQty, found = 0;

    for (int i = 0; i < 10; i++) {
        printf("\nBook %d ID: ", i + 1);
        scanf("%d", &books[i].id);

        printf("Title: ");
        scanf(" %[^\n]", books[i].title);

        printf("Author: ");
        scanf(" %[^\n]", books[i].author);

        printf("Price (BDT): ");
        scanf("%f", &books[i].price);

        printf("Quantity: ");
        scanf("%d", &books[i].quantity);
    }

    printf("\n--- Books Costing More Than 500 BDT ---\n");
    for (int i = 0; i < 10; i++) {
        if (books[i].price > 500) {
            printf("ID: %d | Title: %s | Price: %.2f BDT | Stock: %d\n",
                   books[i].id, books[i].title, books[i].price, books[i].quantity);
        }
    }

    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchID);
    for (int i = 0; i < 10; i++) {
        if (books[i].id == searchID) {
            printf("Found: %s by %s (%.2f BDT, Available: %d)\n",
                   books[i].title, books[i].author, books[i].price, books[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) printf("Book not found.\n");

    printf("\nEnter Book ID to purchase: ");
    scanf("%d", &buyID);

    found = 0;
    for (int i = 0; i < 10; i++) {
        if (books[i].id == buyID) {
            found = 1;
            printf("Enter quantity to purchase: ");
            scanf("%d", &buyQty);

            if (buyQty <= books[i].quantity) {
                books[i].quantity -= buyQty;
                printf("Purchase successful! Remaining stock for '%s': %d\n",
                       books[i].title, books[i].quantity);
            } else {
                printf("Insufficient stock! Only %d available.\n", books[i].quantity);
            }
            break;
        }
    }
    if (!found) printf("Invalid Book ID.\n");

    return 0;
}