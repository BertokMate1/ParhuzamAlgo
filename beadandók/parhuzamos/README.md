## 1. pthread

- **Feladat leírása:** Két nagyméretű mátrix hatékony összeszorzása.

- **Mérési folyamat:**
    - Futásidő: A program futásidejét másodpercekben mérik.
    - Problémaméret: A felhasználótól bekért mátrix mérete határozza meg a probléma méretét.
    - Szálak száma: A program 1-től 10-ig méri a szálakon való futás idejét.

- **Eredmények:**

How big should the matrix be? : 1000
Time taken with 1 threads: 5.373726 seconds
Time taken with 2 threads: 3.291818 seconds
Time taken with 3 threads: 2.451364 seconds
Time taken with 4 threads: 2.088667 seconds
Time taken with 5 threads: 1.822057 seconds
Time taken with 6 threads: 1.611161 seconds
Time taken with 7 threads: 1.461408 seconds
Time taken with 8 threads: 1.320308 seconds
Time taken with 9 threads: 1.217560 seconds
Time taken with 10 threads: 1.142882 seconds

## 2. OpenMP

- **Task Description:** The program calculates the Taylor series approximation of sine around a given x, which are random points. It performs the calculation in parallel using OpenMP.

- **Measurement Process:**
    - Runtime: It runs the calculation of the Taylor series from 1 to 10 thread(s), measuring the elapsed time for each calculation.
    - Problem Size: It prompts the user to input the number of terms used in the Taylor series.
    - Measurement Points: It outputs the runtime for each calculation, showing how fast the program executed alongside the number of threads.

- **Results:**
    - Problem size (number of terms in the Taylor series): 35 000

| Number of threads | Taylor series approximation | math.h sin | difference | time (seconds) |
|-------------------|-----------------------------|------------|------------|----------------|
| 1                 | 0.371446                    | -0.733270  | 1.104716   | 6.247          |
| 2                 | 0.371446                    | -0.733270  | 1.104716   | 3.518711       |
| 3                 | 0.371446                    | -0.733270  | 1.104716   | 2.374051       |
| 4                 | 0.371446                    | -0.733270  | 1.104716   | 1.939701       |
| 5                 | 0.371446                    | -0.733270  | 1.104716   | 1.589735       |
| 6                 | 0.371446                    | -0.733270  | 1.104716   | 1.456865       |
| 7                 | 0.371446                    | -0.733270  | 1.104716   | 1.371542       |
| 8                 | 0.371446                    | -0.733270  | 1.104716   | 1.304944       |
| 9                 | 0.371446                    | -0.733270  | 1.104716   | 1.294432       |
| 10                | 0.371446                    | -0.733270  | 1.104716   | 1.275210       |

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
