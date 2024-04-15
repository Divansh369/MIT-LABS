#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    int myid, numprocs, namelen, len = 7; 
    char s[7] = "HeLlO";
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv); // starts MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &myid); // get current process id
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs); // get number of processes
    MPI_Get_processor_name(processor_name, &namelen);

    if (myid < len) {
        if (islower(s[myid])) {
            s[myid] = toupper(s[myid]);
        } else if (isupper(s[myid])) {
            s[myid] = tolower(s[myid]);
        }
    }

    MPI_Finalize();

    printf("%s\n", s);

    return 0;
}
