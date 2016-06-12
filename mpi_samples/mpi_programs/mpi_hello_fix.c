#include <stdio.h>
#include <mpi.h>
#include <time.h> 

int main(int argc, char *argv[])
{
	int npes, myrank;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &npes);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	printf("From process %d out of %d, Hello World!\n",
		myrank, npes);
	MPI_Finalize();
	sleep(1);
	printf("This is undeterministic behavior of statements after MPI_Finalize.\n");
	return 0;
}
