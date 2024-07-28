#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for student record
struct Student {
    int rollNo;
    char name[50];
    float marks;
    struct Student* next; // Pointer to the next student
};

int main() {
    // Dynamically allocate memory for 5 student records
    struct Student* head = NULL;
    struct Student* temp = NULL;
    for (int i = 0; i < 5; i++) {
        struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
        if (newStudent == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        // Input student details
        printf("Enter Roll No. for student %d: ", i+1);
        scanf("%d", &newStudent->rollNo);
        printf("Enter Name for student %d: ", i+1);
        scanf("%s", newStudent->name);
        printf("Enter Marks for student %d: ", i+1);
        scanf("%f", &newStudent->marks);
        newStudent->next = NULL;

        // Add student record to the list
        if (head == NULL) {
            head = newStudent;
            temp = head;
        } else {
            temp->next = newStudent;
            temp = newStudent;
        }
    }

    // Print student records
    printf("\nStudent Records:\n");
    struct Student* current = head;
    while (current != NULL) {
        printf("Roll No.: %d, Name: %s, Marks: %.2f\n", current->rollNo, current->name, current->marks);
        current = current->next;
    }

    // Free allocated memory
    current = head;
    while (current != NULL) {
        struct Student* nextStudent = current->next;
        free(current);
        current = nextStudent;
    }

    return 0;
}
