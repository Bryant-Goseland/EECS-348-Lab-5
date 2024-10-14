#include <stdio.h>
#define SIZE 5 // defines the matrices

// takes in m1 and m2 - adds them - stores result in a matrix (result)
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// takes in m1 and m2 - multiplies them - stores result in a matrix (result)
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int x = 0; x < SIZE; x++) {
                result[i][j] += m1[i][x] * m2[x][j];
            }
        }
    }
}

/* takes in either m1 or m2 - transposes it (swaps rows and columns) -
   and result goes into a matrix (result) */
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}  
    
// prints matrix
void printMatrix(int matrix[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){

    // define the two given matrices
    int m1[SIZE][SIZE] = { // matrix 2
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = { // matrix 2
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    // results
    int addResult[SIZE][SIZE]; // stores the add function
    int multiplyResult[SIZE][SIZE]; // stores the multiply function
    int trasnposeResult[SIZE][SIZE]; // // stores the transpose function

    // output to print the add function
    printf("Added matrices: \n");
    addMatrices(m1,m2, addResult);
    printMatrix(addResult);

    // output to print the multiply function
    printf("\nMultiplied matrices: \n");
    multiplyMatrices(m1,m2, multiplyResult);
    printMatrix(multiplyResult);

    // output to print the transpose function (with input validation)
    int choice;
    do {
        printf("\nChoose a matrix to transpose (1 for m1, 2 for m2): ");
        scanf("%d", &choice);

        if (choice != 1 && choice != 2) {
            printf("Invalid input! Please enter 1 or 2.\n");
        }
    } while (choice != 1 && choice != 2);
    if (choice == 1){
        printf("\nTransposed matrix: \n");
        transposeMatrix(m1, trasnposeResult);
        printMatrix(trasnposeResult);
    } else if (choice == 2){
        printf("\nTransposed matrix: \n");
        transposeMatrix(m2, trasnposeResult);
        printMatrix(trasnposeResult);
    }
}