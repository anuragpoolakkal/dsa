import java.util.Arrays;

public class Sort {
    public static void main (String[] args) {
        int[] arr = {77, 76, 54, 44, 32};
        bubbleSort(arr);
        //selectionSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }

    static void bubbleSort(int[] arr) {
        boolean swapped;
        // run the steps n-1 times
        for (int i = 0; i < arr.length; i++) {
            swapped = false;
            // for each step, max item will come at last respective index
            for (int j = 1; j < arr.length - i; j++) {
                // swap if item is smaller than previous item
                if (arr[j] < arr[j-1]) {
                    swap(arr, j, j-1);

                    swapped = true;
                }
            }

            if (!swapped) break;
        }
    }

    static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length - i - 1; i++) {
            // find max item in remaining array and swap with correct index
            int last = arr.length - i - 1;
            int maxIndex = getMaxIndex(arr, 0, last);
            swap(arr, maxIndex, last);
        }
    }
    
    static int getMaxIndex(int[] arr, int start, int end) {
        int max = start;

        for (int i = start; i <= end; i++) {
            if (arr[max] < arr[i])
                max = i;
        }
        return max;
    }
}
