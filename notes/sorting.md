# Sorting

#### Table of Contents

1. [Bubble Sort](#bubble-sort)  
2. [Selection Sort](#selection-sort)

### Bubble Sort
```java
static void bubbleSort(int[] arr) {
    boolean swapped;
    // run the steps n-1 times
    for (int i = 0; i < arr.length; i++) {
        swapped = false;
        // for each step, max item will come at last respective index
        for (int j = 1; j < arr.length - i; j++) {
            // swap if item is smaller than previous item
            if (arr[j] < arr[j-1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;

                swapped = true;
            }
        }

        if (!swapped) break;
    }
}
```

## Selection Sort
Time complexity: Worst case - O(n^2), Best case - O(n^2)
Stable?: No
It performs well in small lists/arrays

```java
static void selectionSort(int[] arr) {
    for (int i = 0; i < arr.length - i - 1; i++) {
        // find max item in remaining array and swap with correct index
        int last = arr.length - i - 1;
        int maxIndex = getMaxIndex(arr, 0, last);
        // swap
        int temp = arr[maxIndex];
        arr[maxIndex] = arr[last];
        arr[last] = temp;
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
```