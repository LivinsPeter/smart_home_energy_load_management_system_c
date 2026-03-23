#ifndef BACKEND_H
#define BACKEND_H

union PowerValue {
    int watts;
    float kilowatts;
};

struct Appliance {
    int id;
    char name[50];
    union PowerValue power;
    int unitType; 
    float hoursUsed;
};

// Function prototypes to be shared
float getPowerInWatts(struct Appliance *a);
float calculateTotalLoad(struct Appliance *list, int count);
struct Appliance* addAppliance(struct Appliance *list, int *count);
void displayAppliances(struct Appliance *list, int count);

#endif