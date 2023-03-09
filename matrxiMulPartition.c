#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define BLOCK_SIZE 10

void matrix_mul_partition(int A[][SIZE], int B[][SIZE], int C[][SIZE]) {
    int i, j, k, ii, jj, kk;

    for (i = 0; i < SIZE; i += BLOCK_SIZE) {
        for (j = 0; j < SIZE; j += BLOCK_SIZE) {
            for (k = 0; k < SIZE; k += BLOCK_SIZE) {
                // process sub-matrices
                for (ii = i; ii < i + BLOCK_SIZE; ii++) {
                    for (jj = j; jj < j + BLOCK_SIZE; jj++) {
                        for (kk = k; kk < k + BLOCK_SIZE; kk++) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int i, j, k;
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    srand(time(0));

    // initialize matrices A and B with random values
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }

    // perform matrix multiplication with partitioning
    matrix_mul_partition(A, B, C);

    // print result matrix C
    printf("Result matrix C:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

