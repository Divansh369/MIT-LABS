#include <cstring>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

#define MAX_WORD_LENGTH 100

int main(int argc, char* argv[]) {
    int myrank, numprocs;
    char word[MAX_WORD_LENGTH];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    if (numprocs != 2) {
        if (myrank == 0) {
            printf("This program requires exactly 2 processes.\n");
        }
        MPI_Finalize();
        return 1;
    }

    if (myrank == 0) {
        strcpy(word, "hello");
        MPI_Ssend(word, strlen(word) + 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        printf("Sender: Sent word: %s\n", word);

        MPI_Recv(word, MAX_WORD_LENGTH, MPI_CHAR, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Sender: Received toggled word: %s\n", word);
    } else if (myrank == 1) {
        MPI_Recv(word, MAX_WORD_LENGTH, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Receiver: Received word: %s\n", word);

        int i;
        for (i = 0; word[i] != '\0'; ++i) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                word[i] = word[i] - 32;
            } else if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] = word[i] + 32;
            }
        }

        MPI_Ssend(word, strlen(word) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
        printf("Receiver: Sent toggled word: %s\n", word);
    }

    MPI_Finalize();
    return 0;
}