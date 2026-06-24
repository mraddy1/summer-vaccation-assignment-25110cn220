#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store employee details
typedef struct {
    int id;
    char name[50];
    char department[30];
    float salary;
} Employee;

#define FILE_NAME "employees.dat"

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();

// Utility function to safely read strings
void readString(char *prompt, char *str, int size) {
    printf("%s", prompt);
    if (fgets(str, size, stdin)) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        getchar(); // consume newline

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Add a new employee
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Employee emp;
    printf("Enter Employee ID: ");
    if (scanf("%d", &emp.id) != 1) {
        printf("Invalid ID!\n");
        fclose(fp);
        while (getchar() != '\n');
        return;
    }
    getchar(); // consume newline

    readString("Enter Name: ", emp.name, sizeof(emp.name));
    readString("Enter Department: ", emp.department, sizeof(emp.department));

    printf("Enter Salary: ");
    if (scanf("%f", &emp.salary) != 1) {
        printf("Invalid salary!\n");
        fclose(fp);
        while (getchar() != '\n');
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
    printf("\n%-5s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("------------------------------------------------------\n");

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        printf("%-5d %-20s %-15s %-10.2f\n", emp.id, emp.name, emp.department, emp.salary);
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
        fclose(fp);
        while (getchar() != '\n');
        return;
    }

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n",
                   emp.id, emp.name, emp.department, emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
    fclose(fp);
}

// Update employee details
void updateEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Employee ID to update: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID!\n");
        fclose(fp);
        while (getchar() != '\n');
        return;
    }
    getchar();

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            printf("Enter new details:\n");
            readString("Enter Name: ", emp.name, sizeof(emp.name));
            readString("Enter Department: ", emp.department, sizeof(emp.department));
            printf("Enter Salary: ");
            if (scanf("%f", &emp.salary) != 1) {
                printf("Invalid salary!\n");
                fclose(fp);
                while (getchar() != '\n');
                return;
            }

            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("Employee updated successfully!\n");
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
        fclose(fp);
        fclose(temp);
        while (getchar() != '\n');
        return;
    }

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp)) {
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
        printf("Employee deleted successfully!\n");
    } else {
        printf("Employee with ID %d not found.\n", id);
    }
}























