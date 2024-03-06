#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
struct Term {
    int data; // Coefficient
    int exponent;
    struct Term *next;
};

// Function to create a new term
struct Term* createTerm(int data, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newTerm->data = data;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the polynomial in ascending order of exponents
struct Term* insertTerm(struct Term* polynomial, int data, int exponent) {
    struct Term* newTerm = createTerm(data, exponent);
    struct Term *current = polynomial, *prev = NULL;

    while (current != NULL && current->exponent < exponent) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newTerm->next = polynomial;
        polynomial = newTerm;
    } else {
        prev->next = newTerm;
        newTerm->next = current;
    }

    return polynomial;
}

// Function to display the polynomial
void displayPolynomial(struct Term* polynomial) {
    struct Term* temp = polynomial;
    while (temp != NULL) {
        printf("%dx^%d ", temp->data, temp->exponent);
        if (temp->next != NULL)
            printf("+ ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a term at the end of a linked list
struct Term* insertAtEnd(struct Term* head, int data, int exponent) {
    struct Term* newTerm = createTerm(data, exponent);
    if (head == NULL)
        return newTerm;
    struct Term* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newTerm;
    return head;
}

// Function to insert a new exponent into the polynomial without affecting the sorted order
struct Term* insertExponent(struct Term* polynomial, int exponent) {
    struct Term* current = polynomial;
    while (current != NULL) {
        if (current->exponent == exponent) {
            printf("Exponent already exists in the polynomial.\n");
            return polynomial;
        }
        if (current->exponent < exponent && (current->next == NULL || current->next->exponent > exponent)) {
            current->next = insertAtEnd(current->next, 0, exponent);
            return polynomial;
        }
        current = current->next;
    }
    return polynomial;
}

int main() {
    struct Term* polynomial = NULL;

    // Input the polynomial from the user
    int data, exponent;
    char choice;
    do {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &data, &exponent);
        polynomial = insertTerm(polynomial, data, exponent);
        printf("Do you want to enter more terms? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Display the original polynomial
    printf("Original polynomial: ");
    displayPolynomial(polynomial);

    // Input the exponent to insert
    int newExponent;
    printf("Enter the exponent to insert into the polynomial: ");
    scanf("%d", &newExponent);

    // Insert the new exponent without affecting the sorted order
    polynomial = insertExponent(polynomial, newExponent);

    // Display the modified polynomial
    printf("Modified polynomial: ");
    displayPolynomial(polynomial);

    return 0;
}
