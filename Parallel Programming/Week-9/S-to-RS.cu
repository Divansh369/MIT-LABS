#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 1000

__global__ void repeatString(char *S, char *RS, int length, int S_length) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < length) {
        RS[tid] = S[tid % S_length];
    }
}

int main() {
    char S[MAX_STRING_LENGTH];
    char RS[MAX_STRING_LENGTH * 3]; // Assuming the output string can be at most 3 times the length of the input string
    int length;

    printf("Enter a string: ");
    fgets(S, MAX_STRING_LENGTH, stdin);
    length = strlen(S);
    if (S[length - 1] == '\n') {
        S[length - 1] = '\0';
        length--;
    }

    int S_length = length; // Store the length of input string
    length *= 3; // Adjust length for output string

    char *d_S, *d_RS;
    cudaMalloc(&d_S, S_length * sizeof(char));
    cudaMalloc(&d_RS, length * sizeof(char));

    cudaMemcpy(d_S, S, S_length * sizeof(char), cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (length + threadsPerBlock - 1) / threadsPerBlock;

    repeatString<<<blocksPerGrid, threadsPerBlock>>>(d_S, d_RS, length, S_length);

    cudaMemcpy(RS, d_RS, length * sizeof(char), cudaMemcpyDeviceToHost);

    printf("Input String S: %s\n", S);
    printf("Output String RS: %s\n", RS);

    cudaFree(d_S);
    cudaFree(d_RS);

    return 0;
}
