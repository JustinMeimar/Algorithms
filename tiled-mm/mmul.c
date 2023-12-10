#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MSIZE 512
#define TILE_SIZE 16 // elements

void init_matrix(int matrix[512][512], int width, const char* fmatrix) {
    
    FILE *file = fopen(fmatrix, "r");
    if (file == NULL) {
        perror("Error opening file");
    }
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                fclose(file);
                fprintf(stderr, "Error reading the matrix from the file.\n");
            }
        }
    } 
    fclose(file);
}

void naive_mat_mul(int A[MSIZE][MSIZE], int B[MSIZE][MSIZE], int C[MSIZE][MSIZE]) { 
    for (int i = 0; i < MSIZE; i++) {
        for (int j = 0; j < MSIZE; j++) {
            A[i][j] = 0;
            for (int k = 0; k < MSIZE; k++) {
                A[i][j] += B[i][k] * C[k][j]; 
            }
        }
    }
}

/**
 * optimized for cache line size of 64
 * */
void tiled_mat_mul(int A[MSIZE][MSIZE], int B[MSIZE][MSIZE], int C[MSIZE][MSIZE]) {
    // Compute A = B @ C
    for (int i = 0; i < MSIZE / TILE_SIZE; i++) {
        for (int j = 0; j < MSIZE / TILE_SIZE; j++) { 
            // compute a tile
            for (int x = TILE_SIZE * i; x < TILE_SIZE * (i+1); x++) {
                for (int y = TILE_SIZE * j; y < TILE_SIZE * (j+1); y++) {
                    A[x][y] += B[x][y] * C[x][y];
                }
            }            
        }
    }
}

int main() {

    int A[512][512] = {0};
    int B[512][512] = {0};
    int C[512][512] = {0};
    
    init_matrix(B, 512, "identity.txt"); 
    init_matrix(C, 512, "diagonal.txt"); 
    
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    naive_mat_mul(A, B, C); 
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Time taken by naive_mat_mul: %f seconds\n", cpu_time_used);

    int A2[MSIZE][MSIZE] = {0};
    start = clock();
    tiled_mat_mul(A2, B, C);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by tiled_mat_mul: %f seconds\n", cpu_time_used);
 
    return 0;
}
