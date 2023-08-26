# Binary Search

Binary searching needs sorted array.

### Time Complexity

Best Case: O(1) <br>
Worst Case: O(log n)

**Binary Search**

```java
public class BinarySearch {
    public static void main (String args[]) {
        int[] numbers = { 34, 322, 23, 34, 45, 67, 879, 89, 7, 88 };
        int target = 89;
        int ans = binarySearch(numbers, target);
        System.out.println(ans);
    }

    static int binarySearch(int arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target < arr[mid]) {
                end = mid - 1;
            } else if (target > arr[mid]) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}
```

**Order Agonistic Binary Search**

```java
public class BinarySearch {
    public static void main (String args[]) {
        int[] numbers = { 34, 322, 23, 34, 45, 67, 879, 89, 7, 88 };
        int target = 89;
        int ans = orderAgonisticBS(numbers, target);
        System.out.println(ans);
    }

    static int orderAgonisticBS(int arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        boolean isAsc = arr[start] < arr[end];

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) return mid;

            if (isAsc) {
                if (target < arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target > arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
}
```
