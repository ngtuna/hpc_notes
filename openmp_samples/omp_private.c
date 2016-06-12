#include <stdio.h> 
#include <omp.h> 
int main(void)
{
int i=42; 
printf("before PR: i=%d \n", i);
#pragma omp parallel private(i)
{
  printf("(%d):i=%d\n", omp_get_thread_num(), i);
  i+= omp_get_thread_num();
  printf("(%d):  i=%d\n", omp_get_thread_num(),i);
}
printf("after PR: i=%d \n", i); 
}
