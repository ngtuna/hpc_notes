#include "mpi.h"
void main(argc, argv) 
int argc;
char *argv[];
{
      int nrow, mcol, i, j;
      int p, root, Iam, rank2D, ndim;
      int dims[2], coords[2];
      int periods[2], reorder;
      MPI_Comm comm2D;
/* Starts MPI processes ... */
      MPI_Init(&argc, &argv);               /* starts MPI */
      MPI_Comm_rank(MPI_COMM_WORLD, &Iam);  /* get current process id */
      MPI_Comm_size(MPI_COMM_WORLD, &p);    /* get number of processes */

      nrow = 3; mcol = 2; ndim = 2;
      root = 0; periods[0] = 1; periods[1] = 0; reorder = 1;

/* create cartesian topology for processes */
      dims[0] = nrow;     /* number of rows */
      dims[1] = mcol;     /* number of columns */
      MPI_Cart_create(MPI_COMM_WORLD, ndim, dims, periods, reorder, &comm2D);

      MPI_Barrier(MPI_COMM_WORLD);
      if(Iam == root) {
        printf("\n");
        printf(" Finds ranks of 2D cartesian coordinates\n");
        printf("\n");
        printf("     Row      Col     Rank\n");
        for (i=-3; i<=nrow+2; i++) {
          for (j= 0; j<=mcol-1; j++) {
            coords[0] = i;
            coords[1] = j;
/* <em>  */
            MPI_Cart_rank(comm2D, coords, &rank2D);
/* </em> */
            printf("%8d %8d %8d\n",coords[0], coords[1], rank2D);
          }
        }
      }

      MPI_Finalize();                  /* let MPI finish up ...  */
}     
