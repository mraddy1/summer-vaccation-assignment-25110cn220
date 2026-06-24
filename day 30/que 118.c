#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "library.dat"
#define TITLE_LEN 100
#define AUTHOR_LEN 100

// Structure to store book details
typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
} Book;

// Function prototypes
void addBook();
void viewBooks();
void searchBook();
void deleteBook();
int getNextBookID();

int main() {
    int choice;

    while (1) {
        printf("\n===== Mini Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Delete Book by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: printf("Exiting program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Function to get the next available book ID
int getNextBookID() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 1; // If file doesn't exist, start from ID 1

    Book b;
    int maxID = 0;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id > maxID) maxID = b.id;
    }
    fclose(fp);
    return maxID + 1;
}

// Function to add a new book
void addBook() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return;
    }

    Book b;
    b.id = getNextBookID();
    getchar(); // clear newline from buffer

    printf("Enter book title: ");
    fgets(b.title, TITLE_LEN, stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; // remove newline

    printf("Enter author name: ");
    fgets(b.author, AUTHOR_LEN, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);

    printf("Book added successfully with ID %d.\n", b.id);
}

// Function to view all books
void viewBooks() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No books found.\n");
        return;
    }

    Book b;
    printf("\n%-5s %-30s %-30s\n", "ID", "Title", "Author");
    printf("------------------------------------------------------------\n");
    while (fread(&b, sizeof(Book), 1, fp)) {
        printf("%-5d %-30s %-30s\n", b.id, b.title, b.author);
    }
    fclose(fp);
}

// Function to search for a book by title
void searchBook() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No books found.\n");
        return;
    }

    char searchTitle[TITLE_LEN];
    getchar(); // clear newline
    printf("Enter title to search: ");
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';

    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (strcasecmp(b.title, searchTitle) == 0) {
            printf("Book Found: ID=%d, Title=%s, Author=%s\n", b.id, b.title, b.author);
            found = 1;
            break;
        }
    }
    if (!found) printf("Book not found.\n");
    fclose(fp);
}

// Function to delete a book by ID
void deleteBook() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No books found.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Error creating temporary file.\n");
        fclose(fp);
        return;
    }

    int delID;
    printf("Enter book ID to delete: ");
    if (scanf("%d", &delID) != 1) {
        printf("Invalid input.\n");
        fclose(fp);
        fclose(temp);
        remove("temp.dat");
        return;
    }

    Book b;
    int found = 0;
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id != delID) {
            fwrite(&b, sizeof(Book), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) printf("Book deleted successfully.\n");
    else printf("Book with ID %d not found.\n", delID);
}
































