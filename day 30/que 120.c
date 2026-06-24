#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

// Structure to store student details
typedef struct {
    int rollNo;
    char name[NAME_LEN];
    float marks;
} Student;

// Function prototypes
void addStudent(Student students[], int *count);
void displayStudents(const Student students[], int count);
void searchStudent(const Student students[], int count);
void calculateAverage(const Student students[], int count);

// Main function
int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Calculate Average Marks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                calculateAverage(students, count);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a student
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached.\n");
        return;
    }

    Student s;
    printf("Enter Roll No: ");
    if (scanf("%d", &s.rollNo) != 1) {
        printf("Invalid roll number!\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n'); // clear buffer

    printf("Enter Name: ");
    fgets(s.name, NAME_LEN, stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    printf("Enter Marks: ");
    if (scanf("%f", &s.marks) != 1) {
        printf("Invalid marks!\n");
        while (getchar() != '\n');
        return;
    }

    students[*count] = s;
    (*count)++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(const Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }
}

// Function to search for a student by roll number
void searchStudent(const Student students[], int count) {
    if (count == 0) {
        printf("No students to search.\n");
        return;
    }
    int roll;
    printf("Enter Roll No to search: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("Student Found: Roll No: %d, Name: %s, Marks: %.2f\n",
                   students[i].rollNo, students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student with Roll No %d not found.\n", roll);
}

// Function to calculate average marks
void calculateAverage(const Student students[], int count) {
    if (count == 0) {
        printf("No students to calculate average.\n");
        return;
    }
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].marks;
    }
    printf("Average Marks: %.2f\n", sum / count);
}


































