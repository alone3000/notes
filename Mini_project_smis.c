#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
// int MAX_STUDENTS = 100;

// Define the structure for a Student
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Global array and counter
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function Prototypes
void addRecord();
void updateRecord();
void deleteRecord();
void searchRecord();
void showAllRecords();
void clearConsole();

int main() {
    int choice;

    while (1) {
        printf("Press Enter to continue...");
        getch(); // Wait for user input to continue
        clearConsole();
        printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
        printf("1. Add Record\n");
        printf("2. Update Record\n");
        printf("3. Delete Record\n");
        printf("4. Search Record\n");
        printf("5. Show All Records\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                updateRecord();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                searchRecord();
                break;
            case 5:
                showAllRecords();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}

// 1. ADD RECORD
void addRecord() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database full! Cannot add more students.\n");
        return;
    }

    Student s;
    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);
    
    // Check if ID already exists
    int i;
    for ( i = 0; i < studentCount; i++) {
        if (students[i].id == s.id) {
            printf("Error: Student with ID %d already exists!\n", s.id);
            return;
        }
    }

    printf("Enter Student Name: ");
    getchar(); // Clear newline buffer
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Student GPA: ");
    scanf("%f", &s.gpa);

    students[studentCount] = s;
    studentCount++;
    printf("Record added successfully!\n");
}

// 2. UPDATE RECORD
void updateRecord() {
    int id, found = 0;
    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);

    int i;
    for ( i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Current Name: %s, Current GPA: %.2f\n", students[i].name, students[i].gpa);
            
            printf("Enter New Name: ");
            getchar(); // Clear buffer
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;

            printf("Enter New GPA: ");
            scanf("%f", &students[i].gpa);

            printf("Record updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// 3. DELETE RECORD
void deleteRecord() {
    int id, found = 0;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    int i;
    for ( i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            // Shift all subsequent elements back by one index
            int j;
            for ( j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Record deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// 4. SEARCH RECORD
void searchRecord() {
    int id, found = 0;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    int i;
    for ( i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("\n--- Student Found ---\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("GPA: %.2f\n", students[i].gpa);
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// 5. SHOW ALL RECORDS
void showAllRecords() {
    if (studentCount == 0) {
        printf("\nNo records found in the system.\n");
        return;
    }

    printf("\n---------------------------------------------\n");
    printf("%-10s %-25s %-5s\n", "ID", "Name", "GPA");
    printf("---------------------------------------------\n");
    int i;
    for ( i = 0; i < studentCount; i++) {
        printf("%-10d %-25s %-5.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
    printf("---------------------------------------------\n");

    
}


void clearConsole(){
        system("cls");
    }
