#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 100

__global__ void countWordOccurrences(char *sentence, char *word, int *count, int sentenceLength, int wordLength) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    // int wordCount = 0;
    if (tid < sentenceLength - wordLength + 1) {
        int match = 1;
        for (int i = 0; i < wordLength; ++i) {
            if (sentence[tid + i] != word[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            atomicAdd(count, 1);
        }
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int sentenceLength, wordLength;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentenceLength = strlen(sentence);
    if (sentence[sentenceLength - 1] == '\n') {
        sentence[sentenceLength - 1] = '\0';
        sentenceLength--;
    }

    printf("Enter the word to count: ");
    scanf("%s", word);
    wordLength = strlen(word);

    char *d_sentence, *d_word;
    int *d_count;
    int count = 0;
    cudaMalloc(&d_sentence, sentenceLength * sizeof(char));
    cudaMalloc(&d_word, wordLength * sizeof(char));
    cudaMalloc(&d_count, sizeof(int));

    cudaMemcpy(d_sentence, sentence, sentenceLength * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_word, word, wordLength * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_count, &count, sizeof(int), cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (sentenceLength + threadsPerBlock - 1) / threadsPerBlock;

    countWordOccurrences<<<blocksPerGrid, threadsPerBlock>>>(d_sentence, d_word, d_count, sentenceLength, wordLength);

    cudaMemcpy(&count, d_count, sizeof(int), cudaMemcpyDeviceToHost);

    printf("Number of occurrences of '%s' in the sentence: %d\n", word, count);

    cudaFree(d_sentence);
    cudaFree(d_word);
    cudaFree(d_count);

    return 0;
}
