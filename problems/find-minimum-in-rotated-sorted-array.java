// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
// https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/

class Solution {
    public int findMin(int[] nums) {
        int pivot = findPivot(nums);
        return nums[pivot + 1];
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