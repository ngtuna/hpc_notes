#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
 printf("inside parallel region? %d\n", omp_in_parallel());
 printf("number of available processors? %d\n",omp_get_num_procs());
 printf("maximum number of threads? %d\n", omp_get_max_threads());
 omp_set_num_threads (omp_get_max_threads() );
 #pragma omp parallel
 {
   printf("inside parallel region? %d\n", omp_in_parallel());
   printf("number of threads in the team %d\n", omp_get_num_threads());
   printf("my thread id %d\n", omp_get_thread_num() );
 }
}
