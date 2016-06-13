#include "mpi.h"
/* prototyping ...  */
void foo(int Iam, MPI_Comm comm);
   int i, me, ndim, dims[10], coords[10], periods[10];
void main(int argc, char *argv[]) 
{
      int nrow, mcol;
      int p, Iam, me, ndim;
      int coords[2], dims[2];
      int periods[2], belongs[2], reorder;
      MPI_Comm col_comm, grid_comm;

/* Starts MPI processes ... */
      MPI_Init(&argc, &argv);               /* starts MPI */
      MPI_Comm_rank(MPI_COMM_WORLD, &Iam);  /* get current process id */
      MPI_Comm_size(MPI_COMM_WORLD, &p);    /* get number of processes */

      nrow = 3; mcol = 2; ndim = 2;
      periods[0] = 0; periods[1] = 0; reorder = 1;

/* create cartesian topology for processes */
      dims[0] = nrow;     /* number of rows */
      dims[1] = mcol;     /* number of columns */
      MPI_Cart_create(MPI_COMM_WORLD, ndim, dims, periods, reorder, &grid_comm);
      MPI_Comm_rank(grid_comm, &me);
      MPI_Cart_coords(grid_comm, me, ndim, coords);

/* create column subgrids */
      belongs[0] = 1;   /* index belongs to grid - true */
      belongs[1] = 0;   /* index belongs to grid - false */
      MPI_Cart_sub(grid_comm, belongs, &col_comm);

      foo(Iam, col_comm);

      MPI_Finalize();                  /* let MPI finish up ...  */
}
void foo(int Iam, MPI_Comm comm)
{
   int i, me, ndim, dims[10], coords[10], periods[10];
/* Retrieve subgrid dimensions and other info */
   MPI_Cartdim_get(comm, &ndim);
   MPI_Cart_get(comm, ndim, dims, periods, coords);
   MPI_Cart_rank(comm, coords, &me);

   printf("Iam = %2d  ; subgrid rank =  %2d ; subgrid coords =  ",Iam,me);
   for (i=0; i<ndim; i++) {
     printf("%2d",coords[i]);
   }
   printf(" Dimensions of subgrid = %5d\n",ndim);
   printf(" dims :");
   for (i=0; i<ndim; i++) {
     printf("%5d",dims[i]);
   }
   printf(" periods :");
   for (i=0; i<ndim; i++) {
     printf("%5d",periods[i]);
   }
}
