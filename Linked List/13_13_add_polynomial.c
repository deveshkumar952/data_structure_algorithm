#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};

// Function to create a new term
struct Term *createTerm(int coefficient, int exponent) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the polynomial at the end
void insertTerm(struct Term **polynomial, int coefficient, int exponent) {
    struct Term *newTerm = createTerm(coefficient, exponent);
    if (*polynomial == NULL) {
        *polynomial = newTerm;
    } else {
        struct Term *temp = *polynomial;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

// Function to add two polynomials
struct Term *addPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;
    struct Term *temp1 = poly1;
    struct Term *temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exponent > temp2->exponent) {
            insertTerm(&result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            insertTerm(&result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } else {
            int sum = temp1->coefficient + temp2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, temp1->exponent);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // Append remaining terms of poly1, if any
    while (temp1 != NULL) {
        insertTerm(&result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    // Append remaining terms of poly2, if any
    while (temp2 != NULL) {
        insertTerm(&result, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term *polynomial) {
    struct Term *temp = polynomial;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coefficient, temp->exponent);
        if (temp->next != NULL) {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated for polynomial
void freePolynomial(struct Term *polynomial) {
    struct Term *temp;
    while (polynomial != NULL) {
        temp = polynomial;
        polynomial = polynomial->next;
        free(temp);
    }
}

int main() {
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;

    // Input the first polynomial
    int coefficient, exponent;
    char choice;
    do {
        printf("Enter coefficient and exponent for polynomial 1: ");
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
        printf("Do you want to enter more terms for polynomial 1? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Input the second polynomial
    do {
        printf("Enter coefficient and exponent for polynomial 2: ");
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
        printf("Do you want to enter more terms for polynomial 2? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Display the first polynomial
    printf("First polynomial: ");
    displayPolynomial(poly1);

    // Display the second polynomial
    printf("Second polynomial: ");
    displayPolynomial(poly2);

    // Add the polynomials
    struct Term *sum = addPolynomials(poly1, poly2);

    // Display the result
    printf("Sum of polynomials: ");
    displayPolynomial(sum);

    // Free memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);

    return 0;
}
