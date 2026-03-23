//SMART HOME ENERGY MANAGEMENT SYSTEM
#include <stdio.h>
#include <stdlib.h>
#include "backend.h"

// File Handling: Saving to disk
void saveToFile(struct Appliance *list, int count) {
    FILE *file = fopen("energy_data.bin", "wb");
    if (file == NULL) return;
    fwrite(&count, sizeof(int), 1, file);
    fwrite(list, sizeof(struct Appliance), count, file);
    fclose(file);
    printf("\nData saved successfully!!!\n");
}

// File Handling: Loading from disk
struct Appliance* loadFromFile(int *count) {
    FILE *file = fopen("energy_data.bin", "rb");
    if (file == NULL) {
        *count = 0;
        return NULL;
    }
    fread(count, sizeof(int), 1, file);
    struct Appliance *list = malloc((*count) * sizeof(struct Appliance));
    fread(list, sizeof(struct Appliance), *count, file);
    fclose(file);
    return list;
}

int main() {
    int count = 0;
    int choice;
    // Load existing records on startup
    struct Appliance *list = loadFromFile(&count);

    while (1) {
        printf("\n******Smart Home Energy Manager*******");
        printf("\n1. Add New Appliance");
        printf("\n2. View All Appliances");
        printf("\n3. Calculate Total Energy Load (Recursive)");
        printf("\n4. Save and Exit");
        printf("\nEnter your choice: ");
        
        // Input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                list = addAppliance(list, &count);
                break;
            case 2:
                if (count == 0) printf("No appliances found.\n");
                else displayAppliances(list, count);
                break;
            case 3:
                if (count == 0) printf("No data to calculate.\n");
                else {
                    float total = calculateTotalLoad(list, count);
                    printf("\nTotal Daily Energy Consumption: %.2f kWh\n", total);
                }
                break;
            case 4:
                saveToFile(list, count);
                free(list); // Clean memory before exit
                printf("Program TERMINATED...\n");
                return 0;
            default:
                printf("Invalid selection.\n");
        }
    }
}