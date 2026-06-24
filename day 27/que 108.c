#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define NAME_LEN 50

// Function to calculate grade based on percentage
char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 75) return 'B';
    else if (percentage >= 60) return 'C';
    else if (percentage >= 50) return 'D';
    else return 'F';
}

int main() {
    char name[NAME_LEN];
    int rollNo, numSubjects;
    float marks[MAX_SUBJECTS], total = 0, percentage;
    char grade;

    printf("===== Marksheet Generation System =====\n");

    // Input student name
    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    // Input roll number
    printf("Enter Roll Number: ");
    if (scanf("%d", &rollNo) != 1 || rollNo <= 0) {
        printf("Invalid roll number.\n");
        return 1;
    }

    // Input number of subjects
    printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
    if (scanf("%d", &numSubjects) != 1 || numSubjects <= 0 || numSubjects > MAX_SUBJECTS) {
        printf("Invalid number of subjects.\n");
        return 1;
    }

    // Input marks for each subject
    for (int i = 0; i < numSubjects; i++) {
        printf("Enter marks for Subject %d (0-100): ", i + 1);
        if (scanf("%f", &marks[i]) != 1 || marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks entered.\n");
            return 1;
        }
        total += marks[i];
    }

    // Calculate percentage and grade
    percentage = total / numSubjects;
    grade = calculateGrade(percentage);

    // Display marksheet
    printf("\n===== Student Marksheet =====\n");
    printf("Name       : %s\n", name);
    printf("Roll No.   : %d\n", rollNo);
    printf("Subjects   : %d\n", numSubjects);
    printf("-----------------------------\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("Subject %d : %.2f\n", i + 1, marks[i]);
    }
    printf("-----------------------------\n");
    printf("Total Marks: %.2f\n", total);
    printf("Percentage : %.2f%%\n", percentage);
    printf("Grade      : %c\n", grade);
    printf("=============================\n");

    return 0;
}

























