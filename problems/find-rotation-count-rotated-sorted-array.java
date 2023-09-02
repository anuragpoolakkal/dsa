// https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/


class Solution {
    int findKRotation(int arr[], int n) {
        int pivot = findPivot(arr);
        if (pivot == -1)
            return 0;
        
        return pivot + 1;
    }
    
    static int findPivot(int[] arr) {
        int start = 0, end = arr.length - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if (mid < end && arr[mid] > arr[mid + 1]) {
                return mid;
            }

            if (mid > start && arr[mid] < arr[mid - 1]) {
                return mid - 1;
            }

            if (arr[mid] <= arr[start]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
}