import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        // Check if the correct number of command line arguments are provided
        if (args.length > 2 || args.length < 1) {
            System.out.println("Usage: java Main [<size_of_array> [<num_threads>]]");
            return;
        }

        // Parse command line arguments
        int size; // Default array size
        int numThreads = 1; // Default number of threads

        size = Integer.parseInt(args[0]);

        if (args.length == 2) {
            numThreads = Integer.parseInt(args[1]);
        }

        // Create the array and fill it with random numbers
        int[] array = new int[size];
        java.util.Random random = new java.util.Random();
        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt(1000); // Random numbers between 0 and 999
        }

        // Perform MergeSort
        if (numThreads == 1) {
            long startTime = System.currentTimeMillis();
            sequentialMergeSort(array, 0, size - 1);
            long endTime = System.currentTimeMillis();
            double elapsedTime = (endTime - startTime) / 1000.0; // Convert milliseconds to seconds
            System.out.println("Sorting the array sequentially: " + elapsedTime + " seconds");
        } else {
            long startTime = System.currentTimeMillis();
            ParallelMergeSort mergeSort = new ParallelMergeSort(array, 0, size - 1);
            mergeSort.invoke();
            long endTime = System.currentTimeMillis();
            double elapsedTime = (endTime - startTime) / 1000.0; // Convert milliseconds to seconds
            System.out.println("Sorting the array with " + numThreads + " thread(s): " + elapsedTime + " seconds");
        }

        // Print the sorted array
        System.out.println("Sorted array: " + Arrays.toString(array));
    }

    // Sequential MergeSort implementation
    private static void sequentialMergeSort(int[] array, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            sequentialMergeSort(array, low, mid);
            sequentialMergeSort(array, mid + 1, high);
            merge(array, low, mid, high);
        }
    }

    // Merge method
    private static void merge(int[] array, int low, int mid, int high) {
        int[] left = Arrays.copyOfRange(array, low, mid + 1);
        int[] right = Arrays.copyOfRange(array, mid + 1, high + 1);

        int i = 0, j = 0, k = low;
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }
        }

        while (i < left.length) {
            array[k++] = left[i++];
        }

        while (j < right.length) {
            array[k++] = right[j++];
        }
    }
}