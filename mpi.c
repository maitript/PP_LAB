#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main() {
    MPI_Init(NULL, NULL);

    int communicator_size;
    MPI_Comm_size(MPI_COMM_WORLD, &communicator_size); // Get the number of processes
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); // Get the rank of the current process

    printf("Hello from process %d of %d \n", my_rank, communicator_size);

    char my_msg1[100];
    char my_msg[] = "Hello from MXNXV-ERR";
    int number;

    // Communication between processes
    if (my_rank != 0) {
        // If the process is not rank 0, send a message to process 0
        sprintf(my_msg, "hello from %d", my_rank);
        MPI_Send(&my_msg, strlen(my_msg), MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    } else {
        // If the process is rank 0, receive messages from other processes
        for (int i = 1; i < communicator_size; i++) {
            MPI_Recv(&my_msg1, strlen(my_msg), MPI_CHAR, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Received message: %s from processor %d\n", my_msg1, i);
        }
    }

    MPI_Finalize();

    return 0;
}
