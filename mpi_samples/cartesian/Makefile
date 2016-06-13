# MPICH Makefile for the MPI Tutorial examples
##### User configurable options #####

MPICH_HOME = /usr/local/mpi-1.2.0/IRIX64/ch_shmem/bin

CC          = $(MPICH_HOME)/mpicc
CCC         = $(MPICH_HOME)/mpiCC
F77         = $(MPICH_HOME)/mpif77
F90         = $(MPICH_HOME)/mpif90
CLINKER     = $(MPICH_HOME)/mpicc
CCLINKER    = $(MPICH_HOME)/mpiCC
FLINKER     = $(MPICH_HOME)/mpif77
F90LINKER   = $(MPICH_HOME)/mpif90	  
OPTFLAGS    = -O3
MAKE        = make
SHELL       = /bin/sh
#

### End User configurable options ###

### to run, type "mpichrun -np 6 group_example" ###
### (assuming that you have already aliased mpichrun to $(MPICH_HOME)/mpirun)

CFLAGS  = $(OPTFLAGS)
FFLAGS =  $(OPTFLAGS)
LIBS =
FLIBS =
CLIBS =
EXECS = cart_example1 cart_example2 cart_sub_example cart_get_example

default: $(EXECS)

all: $(EXECS)

cart_example1: cart_example1.o
	$(CLINKER) $(OPTFLAGS) -o cart_example1 cart_example1.o $(CLIBS)

cart_example2: cart_example2.o
	$(CLINKER) $(OPTFLAGS) -o cart_example2 cart_example2.o $(CLIBS)

cart_sub_example: cart_sub_example.o
	$(CLINKER) $(OPTFLAGS) -o cart_sub_example cart_sub_example.o $(CLIBS)

cart_get_example: cart_get_example.o
	$(CLINKER) $(OPTFLAGS) -o cart_get_example cart_get_example.o $(CLIBS)

clean:
	/bin/rm -f *.o *~ $(EXECS)

.c.o:
	$(CC) $(CFLAGS) -c $*.c
.f.o:
	$(F77) $(FFLAGS) -c $*.f
.f90.o:
	$(F90) $(FFLAGS) -c $*.f90
.SUFFIXES: .f90
