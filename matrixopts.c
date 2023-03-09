#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define BLOCK_SIZE 10

int main()
{
    int i, j, k, ii, jj, kk;
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

    // perform matrix multiplication
    for (ii = 0; ii < SIZE; ii += BLOCK_SIZE) {
        for (jj = 0; jj < SIZE; jj += BLOCK_SIZE) {
            for (kk = 0; kk < SIZE; kk += BLOCK_SIZE) {
                // do block matrix multiplication
                for (i = ii; i < ii + BLOCK_SIZE; i++) {
                    for (j = jj; j < jj + BLOCK_SIZE; j++) {
                        for (k = kk; k < kk + BLOCK_SIZE; k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }

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

