import java.util.Arrays;
import java.util.concurrent.RecursiveAction;

class ParallelMergeSort extends RecursiveAction {
    private static final int THRESHOLD = 1000;
    private final int[] array;
    private final int low;
    private final int high;

    public ParallelMergeSort(int[] array, int low, int high) {
        this.array = array;
        this.low = low;
        this.high = high;
    }

    @Override
    protected void compute() {
        if (high - low <= THRESHOLD) {
            // If the number of elements reaches the threshold, use simple MergeSort
            simpleMergeSort(array, low, high);
        } else {
            // Otherwise, split the array into two parts and perform MergeSort in parallel
            int mid = low + (high - low) / 2;
            ParallelMergeSort leftTask = new ParallelMergeSort(array, low, mid);
            ParallelMergeSort rightTask = new ParallelMergeSort(array, mid + 1, high);
            invokeAll(leftTask, rightTask);

            // Merge the sorted parts
            merge(array, low, mid, high);
        }
    }

    private void simpleMergeSort(int[] array, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            simpleMergeSort(array, low, mid);
            simpleMergeSort(array, mid + 1, high);
            merge(array, low, mid, high);
        }
    }

    private void merge(int[] array, int low, int mid, int high) {
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
