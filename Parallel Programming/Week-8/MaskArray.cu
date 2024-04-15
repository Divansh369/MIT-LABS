#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
 
#define TILE_WIDTH 16 // number of threads per block
 
// kernel function for convolution
__global__ void convolve(float* N, float* M, float* P, int width, int mask_width) {
    // calculate global thread index
    int i = blockIdx.x * blockDim.x + threadIdx.x;
 
    // initialize output element to zero
    float P_val = 0;
 
    // loop over the mask array
    for (int j = 0; j < mask_width; j++) {
        // calculate the index of the input element
        int k = i - (mask_width / 2) + j;
 
        // check if the index is within bounds
        if (k >= 0 && k < width) {
            // accumulate the product of input and mask elements
            P_val += N[k] * M[j];
        }
    }
 
    // store the output element in the output array
    P[i] = P_val;
}
 
int main() {
 
    // initialize input array N
    float N[] = { 1, 2, 3, 4, 5 };
 
    // initialize mask array M
    float M[] = { 0.2, 0.2, 0.2, 0.2, 0.2 };
 
    // get the sizes of the arrays
    int width = sizeof(N) / sizeof(float);
    int mask_width = sizeof(M) / sizeof(float);
 
    // allocate memory for output array P on host
    float* P = (float*)malloc(width * sizeof(float));
 
    // allocate memory for arrays on device
    float* d_N, * d_M, * d_P;
    cudaMalloc((void**)&d_N, width * sizeof(float));
    cudaMalloc((void**)&d_M, mask_width * sizeof(float));
    cudaMalloc((void**)&d_P, width * sizeof(float));
 
    // copy arrays from host to device
    cudaMemcpy(d_N, N, width * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_M, M, mask_width * sizeof(float), cudaMemcpyHostToDevice);
 
    // calculate number of blocks needed
    int num_blocks = ceil((float)width / TILE_WIDTH);
 
    // launch kernel function
    convolve << <num_blocks, TILE_WIDTH >> > (d_N, d_M, d_P, width, mask_width);
 
    // copy output array from device to host
    cudaMemcpy(P, d_P, width * sizeof(float), cudaMemcpyDeviceToHost);
 
    printf("Input array P:\n");
    for (int i = 0; i < width; i++) {
        printf("%f ", N[i]);
    }
    printf("\n");
    printf("Mask array P:\n");
    for (int i = 0; i < width; i++) {
        printf("%f ", P[i]);
    }
    printf("\n");
 
    // print output array
    printf("Output array P:\n");
    for (int i = 0; i < width; i++) {
        printf("%f ", P[i]);
    }
    printf("\n");
 
    // free memory on host and device
    free(P);
    cudaFree(d_N);
    cudaFree(d_M);
    cudaFree(d_P);
 
    return 0;
}
