#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICLES 10
#define MAX_COMMUTERS 10

typedef struct {
char regNumber[20];
char type[20];
float costPerKm;
int available;
} vehicle;

typedef struct {
char name[50];
char startLocation[50];
char endLocation[50];
float totalCost;
int status;
} commuter;

vehicle vehicles[MAX_VEHICLES];
commuter commuters[MAX_COMMUTERS];
int numVehicles = 0;
int numCommuters = 0;

void addVehicle();
void addCommuter();
void viewRequests();
void approveRequest(int index);
void rejectRequest(int index);
void displayMenu();

int main() {
int choice;
do {
displayMenu();
printf("Enter your choice: ");
scanf("%d", &choice);
getchar();

switch (choice) {
case 1:
addVehicle();
break;
case 2:
addCommuter();
break;
case 3:
viewRequests();
break;
case 4:
printf("Exiting program...\n");
exit(0);
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 4);

return 0;
}

void addVehicle() {
if (numVehicles == MAX_VEHICLES) {
printf("Cannot add more vehicles. Maximum limit reached.\n");
return;
}

printf("Enter vehicle registration number: ");
scanf("%s", vehicles[numVehicles].regNumber);
printf("Enter vehicle type: ");
scanf("%s", vehicles[numVehicles].type);
printf("Enter cost per kilometer: ");
scanf("%f", &vehicles[numVehicles].costPerKm);
vehicles[numVehicles].available = 1;
numVehicles++;
printf("Vehicle added successfully.\n");
}

void addCommuter() {
if (numCommuters == MAX_COMMUTERS) {
printf("Cannot add more commuters. Maximum limit reached.\n");
return;
}

printf("Enter commuter name: ");
scanf("%s", commuters[numCommuters].name);
printf("Enter start location: ");
scanf("%s", commuters[numCommuters].startLocation);
printf("Enter end location: ");
scanf("%s", commuters[numCommuters].endLocation);
commuters[numCommuters].totalCost = 0;
commuters[numCommuters].status = 0;
numCommuters++;
printf("Commuter added successfully.\n");
}

void viewRequests() {
printf("Pending Requests:\n");
for (int i = 0; i < numCommuters; i++) {
if (commuters[i].status == 0) {
printf("Commuter: %s, Start: %s, End: %s\n", commuters[i].name, commuters[i].startLocation, commuters[i].endLocation);
}
}

int index;
printf("Enter index of request to approve (0 for none): ");
scanf("%d", &index);
if (index != 0) {
approveRequest(index - 1);
}

printf("Enter index of request to reject (0 for none): ");
scanf("%d", &index);
if (index != 0) {
rejectRequest(index - 1);
}
}

void approveRequest(int index) {
if (index < 0 || index >= numCommuters) {
printf("Invalid request index.\n");
return;
}

commuters[index].status = 1;
printf("Request approved for commuter: %s\n", commuters[index].name);
}

void rejectRequest(int index) {
if (index < 0 || index >= numCommuters) {
printf("Invalid request index.\n");
return;
}

commuters[index].status = -1;
printf("Request rejected for commuter: %s\n", commuters[index].name);
}

void displayMenu() {
printf("\nMain Menu\n");
printf("1. Add Vehicle\n");
printf("2. Add Commuter\n");
printf("3. View Requests\n");
printf("4. Exit\n");
}