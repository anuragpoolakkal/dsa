// https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/

class Solution {

    public static void main(String[] args) {
        int[] arr = {12, 23, 34, 45, 56, 67, 78, 89, 90, 100, 112, 123, 233, 345, 456, 566};
        int target = 456;
        System.out.println(ans(arr, target));
    }
    
    static int ans(int[] arr, int target) {
        int start = 0;
        int end = 1;

        while (target > arr[end]) {
            int newStart = end + 1;
            
            end = end + (end - start + 1) * 2;
            start = newStart;
            
        }
        return binarySearch(arr, target, start, end);
    }

    static int binarySearch(int[] arr, int target, int start, int end) {
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