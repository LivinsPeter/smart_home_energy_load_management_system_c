#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"

float getPowerInWatts(struct Appliance *a) {
    if (a->unitType == 0) {
        return (float)a->power.watts;
    }
    return a->power.kilowatts * 1000.0;
}

float calculateTotalLoad(struct Appliance *list, int count) {
    if (count <= 0) {
        return 0;
    }
    float currentPower = getPowerInWatts(&list[count - 1]) * list[count - 1].hoursUsed;
    return (currentPower / 1000.0) + calculateTotalLoad(list, count - 1);
}

struct Appliance* addAppliance(struct Appliance *list, int *count) {
    struct Appliance *newList = realloc(list, (*count + 1) * sizeof(struct Appliance));
    if (newList == NULL) return list;

    struct Appliance *current = &newList[*count];
    current->id = *count + 1;

    printf("Enter name of appliance: ");
    scanf("%s", current->name);
    
    printf("Enter in which unit type (0 for Watts, 1 for kW): ");
    scanf("%d", &current->unitType);

    if (current->unitType == 0) {
        printf("Energy consumption in Watts: ");
        scanf("%d", &current->power.watts);
    } else {
        printf("Energy consumption in kW: ");
        scanf("%f", &current->power.kilowatts);
    }

    printf("Daily hours used: ");
    scanf("%f", &current->hoursUsed);

    (*count)++;
    return newList;
}

void displayAppliances(struct Appliance *list, int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Usage: %.2f hrs\n", 
                list[i].id, list[i].name, list[i].hoursUsed);
    }
}