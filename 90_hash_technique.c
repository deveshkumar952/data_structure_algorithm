#include <stdio.h>

#define SIZE 10 // Size of the hash table

// Function prototypes
int division_hash(int key);
int multiplication_hash(int key);

// Hash table
int hash_table[SIZE] = {0};

int main() {
    int keys[] = {12, 34, 45, 67, 89, 56, 23, 78, 90, 32};
    int i;

    // Using Division Hashing
    printf("Using Division Hashing:\n");
    for (i = 0; i < SIZE; i++) {
        int hash_index = division_hash(keys[i]);
        printf("Key: %d, Hash Index: %d\n", keys[i], hash_index);
    }

    // Using Multiplication Hashing
    printf("\nUsing Multiplication Hashing:\n");
    for (i = 0; i < SIZE; i++) {
        int hash_index = multiplication_hash(keys[i]);
        printf("Key: %d, Hash Index: %d\n", keys[i], hash_index);
    }

    return 0;
}

// Division Hashing function
int division_hash(int key) {
    return key % SIZE;
}

// Multiplication Hashing function
int multiplication_hash(int key) {
    // float A = 0.6180339887; // A = (√5 - 1) / 2 (a typical value for A)
    // return SIZE * (key * A - (int)(key * A));
    return key / SIZE;
}
