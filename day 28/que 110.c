#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account details
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

#define FILE_NAME "bank_accounts.dat"

// Function to create a new account
void createAccount() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Append in binary mode
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Account acc;
    printf("Enter Account Number: ");
    if (scanf("%d", &acc.accountNumber) != 1) {
        printf("Invalid input.\n");
        fclose(fp);
        return;
    }

    printf("Enter Account Holder Name: ");
    getchar(); // Clear newline from buffer
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0'; // Remove newline

    printf("Enter Initial Deposit Amount: ");
    if (scanf("%f", &acc.balance) != 1 || acc.balance < 0) {
        printf("Invalid amount.\n");
        fclose(fp);
        return;
    }

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);
    printf("Account created successfully!\n");
}

// Function to deposit money
void depositMoney() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    int accNo;
    float amount;
    printf("Enter Account Number: ");
    if (scanf("%d", &accNo) != 1) {
        printf("Invalid input.\n");
        fclose(fp);
        return;
    }

    Account acc;
    int found = 0;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.accountNumber == accNo) {
            printf("Enter amount to deposit: ");
            if (scanf("%f", &amount) != 1 || amount <= 0) {
                printf("Invalid amount.\n");
                fclose(fp);
                return;
            }
            acc.balance += amount;
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, fp);
            printf("Deposit successful! New Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("Account not found.\n");
    fclose(fp);
}

// Function to withdraw money
void withdrawMoney() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    int accNo;
    float amount;
    printf("Enter Account Number: ");
    if (scanf("%d", &accNo) != 1) {
        printf("Invalid input.\n");
        fclose(fp);
        return;
    }

    Account acc;
    int found = 0;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.accountNumber == accNo) {
            printf("Enter amount to withdraw: ");
            if (scanf("%f", &amount) != 1 || amount <= 0) {
                printf("Invalid amount.\n");
                fclose(fp);
                return;
            }
            if (amount > acc.balance) {
                printf("Insufficient balance.\n");
                fclose(fp);
                return;
            }
            acc.balance -= amount;
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, fp);
            printf("Withdrawal successful! New Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("Account not found.\n");
    fclose(fp);
}

// Function to display account details
void displayAccount() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    int accNo;
    printf("Enter Account Number: ");
    if (scanf("%d", &accNo) != 1) {
        printf("Invalid input.\n");
        fclose(fp);
        return;
    }

    Account acc;
    int found = 0;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.accountNumber == accNo) {
            printf("\n--- Account Details ---\n");
            printf("Account Number: %d\n", acc.accountNumber);
            printf("Name: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("Account not found.\n");
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Bank Account Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayAccount(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}



























