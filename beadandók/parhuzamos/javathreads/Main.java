import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.ForkJoinPool;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the size of the array and number of threads
        System.out.print("Please enter the size of the array: ");
        int size = scanner.nextInt();
        System.out.print("Please enter the number of threads: ");
        int numThreads = scanner.nextInt();

        // Create the array and fill it with random numbers
        int[] array = new int[size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt(1000); // Random numbers between 0 and 999
        }

        // Perform parallel MergeSort
        ForkJoinPool pool = new ForkJoinPool(numThreads);
        long startTime = System.currentTimeMillis();
        pool.invoke(new ParallelMergeSort(array, 0, size - 1));
        long endTime = System.currentTimeMillis();

        // Print the sorting time
        double elapsedTime = (endTime - startTime) / 1000.0; // Convert milliseconds to seconds
        System.out.println("Sorting the array with " + numThreads + " thread(s): " + elapsedTime + " seconds");
    }
}