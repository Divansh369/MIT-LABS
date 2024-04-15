#include <stdio.h>
#include <math.h>

__global__ void computeSine(float *input, float *output, int size) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < size) {
        output[tid] = sinf(input[tid]);
    }
}

int main() {
    int size = 10; // Size of the input array
    size_t bytes = size * sizeof(float);

    // Allocate memory for the host arrays
    float *h_input = (float*)malloc(bytes);
    float *h_output = (float*)malloc(bytes);

    // Initialize the input array with angles in radians
    for (int i = 0; i < size; ++i) {
        h_input[i] = 200*i; // Increment angle by 0.01 radians
    }

    // Allocate memory for the device arrays
    float *d_input, *d_output;
    cudaMalloc(&d_input, bytes);
    cudaMalloc(&d_output, bytes);

    // Copy the input array from host to device
    cudaMemcpy(d_input, h_input, bytes, cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    int threadsPerBlock = 256;
    int blocksPerGrid = (size + threadsPerBlock - 1) / threadsPerBlock;

    // Launch the kernel
    computeSine<<<blocksPerGrid, threadsPerBlock>>>(d_input, d_output, size);

    // Copy the result array from device to host
    cudaMemcpy(h_output, d_output, bytes, cudaMemcpyDeviceToHost);

    // Print the result
    for (int i = 0; i < size; ++i) {
        printf("sin(%f radians) = %f\n", h_input[i], h_output[i]);
    }

    // Free device memory
    cudaFree(d_input);
    cudaFree(d_output);

    // Free host memory
    free(h_input);
    free(h_output);

    return 0;
}
