#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void matrix_mul_layout(int *A, int *B, int *C) {
    int i, j, k;

    for (i = 0; i < SIZE; i++) {
        for (k = 0; k < SIZE; k++) {
            for (j = 0; j < SIZE; j++) {
                *(C + i * SIZE + j) += *(A + i * SIZE + k) * *(B + k * SIZE + j);
            }
        }
    }
}

int main()
{
    int i, j, k;
    int *A, *B, *C;
    A = (int*) malloc(SIZE * SIZE * sizeof(int));
    B = (int*) malloc(SIZE * SIZE * sizeof(int));
    C = (int*) calloc(SIZE * SIZE, sizeof(int));
    srand(time(0));

    // initialize matrices A and B with random values
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            *(A + i * SIZE + j) = rand() % 10;
            *(B + i * SIZE + j) = rand() % 10;
            *(C + i * SIZE + j) = 0;
        }
    }

    // perform matrix multiplication with changing layout of data in memory
    matrix_mul_layout(A, B, C);

    // print result matrix C
    printf("Result matrix C:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", *(C + i * SIZE + j));
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(C);

    return 0;
}

