#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "employees.dat"

// Employee structure
typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();
int isValidName(const char *name);

int main() {
    int choice;

    while (1) {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Validate name (only alphabets and spaces allowed)
int isValidName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ')
            return 0;
    }
    return 1;
}

// Add new employee
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Employee emp;
    printf("Enter Employee ID: ");
    if (scanf("%d", &emp.id) != 1) {
        printf("Invalid ID! Must be a number.\n");
        while (getchar() != '\n');
        fclose(fp);
        return;
    }

    while (getchar() != '\n'); // clear buffer

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0'; // remove newline

    if (!isValidName(emp.name) || strlen(emp.name) == 0) {
        printf("Invalid name! Only alphabets and spaces allowed.\n");
        fclose(fp);
        return;
    }

    printf("Enter Employee Salary: ");
    if (scanf("%f", &emp.salary) != 1 || emp.salary < 0) {
        printf("Invalid salary! Must be a positive number.\n");
        while (getchar() != '\n');
        fclose(fp);
        return;
    }

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);
    printf("Employee added successfully!\n");
}

// Display all employees
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    Employee emp;
    printf("\n%-10s %-30s %-10s\n", "ID", "Name", "Salary");
    printf("--------------------------------------------------\n");

    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        printf("%-10d %-30s %-10.2f\n", emp.id, emp.name, emp.salary);
    }

    fclose(fp);
}

// Search employee by ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Employee ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        while (getchar() != '\n');
        fclose(fp);
        return;
    }

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == id) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\nName: %s\nSalary: %.2f\n", emp.id, emp.name, emp.salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }

    fclose(fp);
}

// Delete employee by ID
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        perror("Error creating temp file");
        fclose(fp);
        return;
    }

    int id, found = 0;
    printf("Enter Employee ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        while (getchar() != '\n');
        fclose(fp);
        fclose(temp);
        return;
    }

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == id) {
            found = 1;
            continue; // skip writing this record
        }
        fwrite(&emp, sizeof(Employee), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Employee deleted successfully.\n");
    } else {
        printf("Employee with ID %d not found.\n", id);
    }
}

































