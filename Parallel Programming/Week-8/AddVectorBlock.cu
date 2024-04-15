#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
 
// CUDA kernel to add two vectors
__global__ void vecAddKernel(int* A, int* B, int* C, int n) {
    // Get the global thread ID
    int id = blockIdx.x * blockDim.x + threadIdx.x;
    // Check if the thread is within the vector range
    if (id < n) {
        // Add the corresponding elements of A and B
        C[id] = A[id] + B[id];
    }
}
 
 
// Function to add two vectors using CUDA
void vecAdd(int* A, int* B, int* C, int n) {
    // Allocate device memory for the vectors
    int* d_A, * d_B, * d_C;
    cudaMalloc(&d_A, n * sizeof(int));
    cudaMalloc(&d_B, n * sizeof(int));
    cudaMalloc(&d_C, n * sizeof(int));
 
 
    // Copy the vectors from host to device
    cudaMemcpy(d_A, A, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, n * sizeof(int), cudaMemcpyHostToDevice);
 
 
    // Define the block size and grid size
    int blockSize = 256; // Number of threads per block
    int gridSize = (n + 256 - 1) / n; // Number of blocks per grid
 
 
    // Launch the kernel with the specified configuration
    vecAddKernel << <gridSize, blockSize >> > (d_A, d_B, d_C, n);
 
 
    // Copy the result vector from device to host
    cudaMemcpy(C, d_C, n * sizeof(int), cudaMemcpyDeviceToHost);
 
 
    // Free the device memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
}
 
 
// Main function to test the vector addition
int main() {
    // Get the vector length from the user
    int n;
    printf("Enter the vector length: ");
    scanf("%d", &n);
 
 
    // Allocate host memory for the vectors
    int* A = (int*)malloc(n * sizeof(int));
    int* B = (int*)malloc(n * sizeof(int));
    int* C = (int*)malloc(n * sizeof(int));
 
 
    // Initialize the vectors with random values
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
        C[i] = 0;
    }
 
 
    // Add the vectors using CUDA
    vecAdd(A, B, C, n);
    printf("\nThe first vector is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\nThe second vector is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", B[i]);
    }
    // Print the result vector
    printf("\n\nThe result vector is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", C[i]);
    }
 
    printf("\n");
    // Free the host memory
    free(A);
    free(B);
    free(C);
 
 
    return 0;
}
