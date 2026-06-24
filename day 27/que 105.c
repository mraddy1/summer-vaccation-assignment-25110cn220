#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

// Structure to store student details
typedef struct {
    int id;
    char name[50];
    int age;
    char gender;
    char course[50];
} Student;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
void updateStudent();
int studentExists(int id);

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student by ID\n");
        printf("5. Update Student by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Check if student with given ID exists
int studentExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;
    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// Add a new student
void addStudent() {
    Student s;
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &s.id);

    if (studentExists(s.id)) {
        printf("Student with ID %d already exists!\n", s.id);
        fclose(fp);
        return;
    }

    printf("Enter Name: ");
    getchar(); // clear newline
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Gender (M/F): ");
    scanf(" %c", &s.gender);

    printf("Enter Course: ");
    getchar();
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = '\0';

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

// Display all students
void displayStudents() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    Student s;
    printf("\n%-5s %-20s %-5s %-7s %-20s\n", "ID", "Name", "Age", "Gender", "Course");
    printf("-------------------------------------------------------------\n");
    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("%-5d %-20s %-5d %-7c %-20s\n", s.id, s.name, s.age, s.gender, s.course);
    }
    fclose(fp);
}

// Search student by ID
void searchStudent() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("\nStudent Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGender: %c\nCourse: %s\n",
                   s.id, s.name, s.age, s.gender, s.course);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}

// Delete student by ID
void deleteStudent() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!fp || !temp) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id != id) {
            fwrite(&s, sizeof(Student), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Student deleted successfully!\n");
    } else {
        printf("Student with ID %d not found!\n", id);
    }
}

// Update student by ID
void updateStudent() {
    int id;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("Enter New Name: ");
            getchar();
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = '\0';

            printf("Enter New Age: ");
            scanf("%d", &s.age);

            printf("Enter New Gender (M/F): ");
            scanf(" %c", &s.gender);

            printf("Enter New Course: ");
            getchar();
            fgets(s.course, sizeof(s.course), stdin);
            s.course[strcspn(s.course, "\n")] = '\0';

            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            found = 1;
            printf("Student updated successfully!\n");
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}






















