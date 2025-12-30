#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char type[30];
    int rarity;
    float power;
} Item;

Item *invent = NULL;
int itemCount = 0;
int capacity = 0;

void initinvent(int initialSize);
void addItem();
void showinvent();
void f_mem();
void pri_header();

int main() {
    int choice;

    initinvent(2);

    while(1) {
        pri_header();
        printf("\n=== SYSTEM MENU ===\n");
        printf("1. Add\n");
        printf("2. View\n");
        printf("3. Exit\n");
        printf("Select Operation: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem();
                break;
            case 2:
                showinvent();
                break;
            case 3:
                printf("\n Optimization complete\n");
                f_mem();
                return 0;
            default:
                printf("\n Invalid Input\n");
        }

        printf("\nPress Enter to continue");
        getchar(); getchar();
    }
    return 0;
}

void pri_header() {
    printf("\n\n");
    printf("#####################################\n");
    printf("#      Z E N   V A U L T      #\n");
    printf("#####################################\n");
}

void initinvent(int initialSize) {
    invent = (Item*)malloc(initialSize * sizeof(Item));
    if (invent == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    capacity = initialSize;
    printf("Memory initialized. capacity: %d slots.\n", capacity);
}

void addItem() {
    if (itemCount == capacity) {
        capacity *= 2;
        invent = (Item*)realloc(invent, capacity * sizeof(Item));
        if (invent == NULL) {
            printf("Memory re-allocation failed\n");
            exit(1);
        }
        printf("Capacity auto expanded to %d slots.\n", capacity);
    }

    printf("\n--- ADDING NEW RESOURCE ---\n");
    invent[itemCount].id = itemCount + 1;

    printf("Enter Name (No spaces): ");
    scanf("%s", invent[itemCount].name);

    printf("Enter Type (Weapon/Artifact): ");
    scanf("%s", invent[itemCount].type);

    printf("Enter Rarity (1-5): ");
    scanf("%d", &invent[itemCount].rarity);

    printf("Enter Power Level: ");
    scanf("%f", &invent[itemCount].power);

    itemCount++;
    printf("Item '%s' added to database.\n", invent[itemCount-1].name);
}

void showinvent() {
    printf("\n--- CURRENT invent (%d Items) ---\n", itemCount);
    printf("ID | %-15s | %-10s | Stars | Power \n", "Name", "Type");
    printf("----------------------------------------------------\n");

    for(int i = 0; i < itemCount; i++) {
        printf("%02d | %-15s | %-10s | %d     | %.2f \n",
            invent[i].id,
            invent[i].name,
            invent[i].type,
            invent[i].rarity,
            invent[i].power
        );
    }

}

void f_mem() {
    if (invent != NULL) {
        free(invent);
        invent = NULL;
        printf(" Memory free successfully .\n");
    }
}