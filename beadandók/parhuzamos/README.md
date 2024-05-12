## 1. pthread

- **Task description:** Efficient multiplication of two large matrix and LU decomposition.

- **Measurement process:**
    - Runtime: The program's runtime is measured in seconds.
    - Problem size: The size of the matrix entered by the user determines the problem size.
    - Number of threads: The program measures the runtime with the amount thread(s) the user has input.

- **Results:**
- Matrix size : 1000

| Number of Threads | Time (seconds) |
|-------------------|----------------|
| 1                 | 8.353726       |
| 2                 | 3.991898       |
| 3                 | 2.655864       |
| 4                 | 2.258967       |
| 5                 | 1.923857       |
| 6                 | 1.721569       |
| 7                 | 1.561708       |
| 8                 | 1.420308       |
| 9                 | 1.314560       |
| 10                | 1.222882       |


## 2. OpenMP

- **Task Description:** The program calculates the Taylor series approximation of sine and cosine around a given x, which is a random point. It performs the calculation in parallel using OpenMP.

- **Measurement Process:**
    - Runtime: It runs the calculation of the Taylor series from 1 to 10 thread(s), measuring the elapsed time for each calculation.
    - Problem Size: It prompts the user to input the number of terms used in the Taylor series.
    - Measurement Points: It outputs the runtime for each calculation, showing how fast the program executed alongside the number of threads.

- **Results:**
-Problem size (number of terms in the Taylor series): 35 000

| Number of threads | Taylor series approximation (sin) | math.h sin | Difference (sin) | Taylor series approximation (cos) | math.h cos | Difference (cos) | Time (seconds) |
|-------------------|----------------------------------|------------|------------------|----------------------------------|------------|------------------|----------------|
| 1                 | 0.972372                         | 0.972372   | 0.000000         | 0.233438                         | 0.233438   | 0.000000         | 6.245          |
| 2                 | 0.972372                         | 0.972372   | 0.000000         | 0.233438                         | 0.233438   | 0.000000         | 3.132          |
| 3                 | 0.972372                         | 0.972372   | 0.000000         | 0.233438                         | 0.233438   | 0.000000         | 2.311          |
| 4                 | 0.972372                         | 0.972372   | 0.000000         | 0.233438                         | 0.233438   | 0.000000         | 1.974          |
| 5                 | 0.972372                         | 0.972372   | 0.000000         | 0.233438                         | 0.233438   | 0.000000         | 1.574          |
| 6                 | 0.972372                         | 0.972372   | 0.000000         | 0.233438                         | 0.233438   | 0.000000         | 1.450          |
| 7                 | 0.972372                         | 0.972372   | 0.000000         | 0.233438                         | 0.233438   | 0.000000         | 1.380          |
| 8                 | 0.972372                         | 0.972372   | 0.000000         | 0.233438                         | 0.233438   | 0.000000         | 1.307          |
| 9                 | 0.972372                         | 0.972372   | 0.000000         | 0.233438                         | 0.233438   | 0.000000         | 1.290          |
| 10                | 0.972372                         | 0.972372   | 0.000000         | 0.233438                         | 0.233438   | 0.000000         | 1.279          |


# 3. Java ForkJoinPool

- **Task Description:** The program demonstrates the parallel implementation of the Merge Sort algorithm in Java using the Fork/Join framework. We sort an array of integers in parallel.

- **Measurement Process:**
    - Runtime: Outputs the runtime for the given problem size and number of threads, as well as for sequential execution.
    - Problem Size: The user dictates it, this will determine the size of the array to work with.
    - Sequential Vs Parallel: Results below will demonstrate the speedup achieved by parallel execution.

- **Results:**
- -Array Size for all: 100 000 000

| Number of Threads | Runtime (seconds) |
|--------------|------------------------|
| Sequential   | 16.924                 |
| 2            | 9.553                  |
| 4            | 5.176                  |
| 8            | 2.892                  |
| 16           | 1.684                  |
| 32           | 0.961                  |