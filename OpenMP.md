# OpenMP notes
## Contents
- Scope of variables
- Reduction
- Critical
- Synchronization

## Scope of variables
There are three common scopes of variables: shared, private, firstprivate.

```c
variables A=1, B=1, and C=1
#pragma omp parallel private(B) shared(A) firstprivate(C)
```

Inside the parallel region:
- “A” is shared by all threads; equals 1
- “B” and “C” are local to each thread
  - B’s initial value is undefined
  - C’s initial value equals 1

Outside this parallel region:
- The values of “B” and “C” are undefined.

## Reduction operations
A **reduction operation** is a global calculation or comparison, involving data (e.g., partial sums) from several different threads. The reduction clause allows you to automatically perform such operations in a safe way.

```c
Syntax: reduction({op}:list})
```

Example:
```c
#pragma omp parallel for private (i) reduction(+:sum)
for (i=0; i < n; i++)
    sum = sum + a[i];
```

In this example, each thread automatically gets a private copy of the variable sum, initialized to zero. The threads compute the partial sums corresponding to their share of the loop iterations. Finally, the partial sums are combined from each thread to obtain the global sum.

Available ops:
```c
op = { + | * | - | || | && }
```

## Critical region
Only one thread at a time can enter a critical section.

Example:
```c
#pragma omp parallel private (i,s_local)
{
  s_local = 0;

  #pragma omp for
  for (i=0; i<100; i++)
    s_local += a[i];

  #pragma omp critical
    s += s_local;
}
```

## Synchronization
OpenMP has the following constructs to support synchronization.

### critical section:
The **critical** directive ensures that the immediately following block of code is executed by only one thread at a time in a parallel region. The first thread to arrive at the critical section proceeds to enter; threads that arrive subsequently wait until the thread currently inside it has exited.

```c
#pragma omp critical [(name)]
     structured block of code
```

### barrier:
The **barrier** directive is a construct that forces threads to stop until all have reached the barrier.

```c
#pragma omp barrier
```

### single:
The **single** directive is similar to the **master** directive except that the specified region of code will be performed on the thread which is the first to reach the directive, not necessarily the master thread. Unlike the master directive, there is an implied **barrier** at the end of the single region.

```c
#pragma omp single
    structured block of code
```

### master:
The **master** directive designates a section of code (a structured block) that is executed only by the master thread, i.e., thread 0. This section of code is called the master region.

```c
#pragma omp master
    structured block of code
```

### sections:
There are some tasks which must be performed serially due to data dependencies, calls to serial libraries, input/output issues, etc. If there is more than one such task and they are independent, they can be performed by individual threads at the same time. Note that each task is still only performed by a single thread, i.e., the individual tasks are not parallelized. This configuration can be effected through the use of the **section** and **sections** directives.

```c
#pragma omp parallel
#pragma omp sections
{
  #pragma omp section
  X_calculation(); // only one thread
  #pragma omp section
  y_calculation(); // only one thread
  #pragma omp section
  z_calculation(); // only one thread
}
```
Each of the three tasks will now be performed in parallel on individual threads. In this example, exactly three threads are used irrespective of the number of threads available in the current parallel region.
