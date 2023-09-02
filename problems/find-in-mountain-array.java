// this problem is not submitted on leetcode as it have to be implemented with interface MountainArray provided

class Solution {
    int search(int[] arr, int target) {
        int peak = peakIndexInMountainArray(arr);
        int firstTry = orderAgonisticBS(arr, target, 0, peak);
        if (firstTry != -1) return firstTry;
        // if not found in first try, try to search on second half
        return orderAgonisticBS(arr, target, peak+1, arr.length-1)
    }
    
    public int peakIndexInMountainArray(int[] arr) {
        int start = 0, end = arr.length -1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[mid+1]) {
                // you are in the dec part of the array. this may be the ans, but look at left.
                // this is why end != mid -1
                end = mid;
            } else {
                // you are in the asc part of the array
                start = mid + 1; // bcz mid+1 element > mid element
            }
        }
        //in the end start == end, pointing to the largest number
        return start;
    }

    public int orderAgonisticBS(int[] arr, int target, int start, int end) {
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