/*
    Program to create employee structure with sorting and deletion
    @JIYO P V   08 OCTOBER 2025   Roll no:33
*/

#include <stdio.h>
#include <string.h>

#define SIZE 50

// Define employee structure
struct Employee {
    int eno;        // Employee number
    char ename[50]; // Employee name
    float esal;     // Employee salary
    int dno;        // Department number
};

struct Employee emp[SIZE]; // Array of employees
int n = 0;                // Number of employees currently stored

// Function to read employee details
void readEmployees() {
    int i;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i+1);
        printf("Employee number: ");
        scanf("%d", &emp[i].eno);
        printf("Employee name: ");
        scanf(" %[^\n]", emp[i].ename); // Read string with spaces
        printf("Employee salary: ");
        scanf("%f", &emp[i].esal);
        printf("Department number: ");
        scanf("%d", &emp[i].dno);
    }
}

// Function to display all employees
void displayEmployees() {
    int i;
    if(n == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\nEmployee Details:\n");
    printf("No\tName\t\tSalary\tDept\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", emp[i].eno, emp[i].ename, emp[i].esal, emp[i].dno);
    }
}

// a. Search employee by number
void searchByNumber(int eno) {
    int i, found = 0;
    for(i = 0; i < n; i++) {
        if(emp[i].eno == eno) {
            printf("Employee Found:\n");
            printf("%d\t%s\t%.2f\t%d\n", emp[i].eno, emp[i].ename, emp[i].esal, emp[i].dno);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Employee with number %d not found.\n", eno);
    }
}

// b.i Sort employees by name
void sortByName() {
    int i, j;
    struct Employee temp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(strcmp(emp[i].ename, emp[j].ename) > 0) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
    printf("Employees sorted by name.\n");
}

// b.ii Sort employees by salary
void sortBySalary() {
    int i, j;
    struct Employee temp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(emp[i].esal > emp[j].esal) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
    printf("Employees sorted by salary.\n");
}

// c. Delete employee by number
void deleteEmployee(int eno) {
    int i, found = 0;
    for(i = 0; i < n; i++) {
        if(emp[i].eno == eno) {
            found = 1;
            break;
        }
    }

    if(found) {
        for(; i < n-1; i++) {
            emp[i] = emp[i+1];
        }
        n--;
        printf("Employee with number %d deleted.\n", eno);
    } else {
        printf("Employee with number %d not found.\n", eno);
    }
}

// Menu
int menu() {
    int choice;
    printf("\nEmployee Menu:\n");
    printf("1. Display all employees\n");
    printf("2. Search employee by number\n");
    printf("3. Sort employees by name\n");
    printf("4. Sort employees by salary\n");
    printf("5. Delete employee by number\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Process menu
void processEmployees() {
    int choice, eno;
    for(choice = menu(); choice != 6; choice = menu()) {
        switch(choice) {
            case 1:
                displayEmployees();
                break;
            case 2:
                printf("Enter employee number to search: ");
                scanf("%d", &eno);
                searchByNumber(eno);
                break;
            case 3:
                sortByName();
                displayEmployees();
                break;
            case 4:
                sortBySalary();
                displayEmployees();
                break;
            case 5:
                printf("Enter employee number to delete: ");
                scanf("%d", &eno);
                deleteEmployee(eno);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Main function
int main() {
    readEmployees();
    processEmployees();
    return 0;
}



