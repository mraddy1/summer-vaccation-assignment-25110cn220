#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LEN 50
#define DEPT_LEN 30
#define DESIGN_LEN 30

// Structure to store employee details
typedef struct {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    char designation[DESIGN_LEN];
    double salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int empCount = 0;

// Function prototypes
void addEmployee();
void displayEmployees();
void updateSalary();
void searchEmployee();
int findEmployeeById(int id);
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n===== Salary Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Update Employee Salary\n");
        printf("4. Search Employee by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: updateSalary(); break;
            case 4: searchEmployee(); break;
            case 5: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Add a new employee
void addEmployee() {
    if (empCount >= MAX_EMPLOYEES) {
        printf("Employee limit reached!\n");
        return;
    }

    Employee e;
    printf("Enter Employee ID: ");
    if (scanf("%d", &e.id) != 1) {
        printf("Invalid ID!\n");
        clearInputBuffer();
        return;
    }

    if (findEmployeeById(e.id) != -1) {
        printf("Employee with this ID already exists!\n");
        return;
    }

    clearInputBuffer();
    printf("Enter Name: ");
    fgets(e.name, NAME_LEN, stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(e.department, DEPT_LEN, stdin);
    e.department[strcspn(e.department, "\n")] = '\0';

    printf("Enter Designation: ");
    fgets(e.designation, DESIGN_LEN, stdin);
    e.designation[strcspn(e.designation, "\n")] = '\0';

    printf("Enter Salary: ");
    if (scanf("%lf", &e.salary) != 1 || e.salary < 0) {
        printf("Invalid salary!\n");
        clearInputBuffer();
        return;
    }

    employees[empCount++] = e;
    printf("Employee added successfully!\n");
}

// Display all employees
void displayEmployees() {
    if (empCount == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\n%-5s %-20s %-15s %-15s %-10s\n", "ID", "Name", "Department", "Designation", "Salary");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < empCount; i++) {
        printf("%-5d %-20s %-15s %-15s %.2lf\n",
               employees[i].id, employees[i].name, employees[i].department,
               employees[i].designation, employees[i].salary);
    }
}

// Update salary of an employee
void updateSalary() {
    int id;
    printf("Enter Employee ID to update salary: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        clearInputBuffer();
        return;
    }

    int index = findEmployeeById(id);
    if (index == -1) {
        printf("Employee not found!\n");
        return;
    }

    double newSalary;
    printf("Enter new salary: ");
    if (scanf("%lf", &newSalary) != 1 || newSalary < 0) {
        printf("Invalid salary!\n");
        clearInputBuffer();
        return;
    }

    employees[index].salary = newSalary;
    printf("Salary updated successfully!\n");
}

// Search employee by ID
void searchEmployee() {
    int id;
    printf("Enter Employee ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        clearInputBuffer();
        return;
    }

    int index = findEmployeeById(id);
    if (index == -1) {
        printf("Employee not found!\n");
        return;
    }

    Employee e = employees[index];
    printf("\nEmployee Found:\n");
    printf("ID: %d\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %.2lf\n",
           e.id, e.name, e.department, e.designation, e.salary);
}

// Find employee index by ID
int findEmployeeById(int id) {
    for (int i = 0; i < empCount; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
























