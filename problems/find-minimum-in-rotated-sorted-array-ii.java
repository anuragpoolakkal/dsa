class Solution {
    public int findMin(int[] nums) {
        int pivot = findPivotWithDuplicates(nums);
        return nums[pivot + 1];
    }

    static int findPivotWithDuplicates(int[] arr) {
        int start = 0, end = arr.length - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if (mid < end && arr[mid] > arr[mid + 1]) {
                return mid;
            }

            if (mid > start && arr[mid] < arr[mid - 1]) {
                return mid - 1;
            }

            if (arr[mid] == arr[start] && arr[mid] == arr[end]) {
                // skip the duplicates
                // NOTE: what if the elements at start and end were the pivot?
                // check if start is pivot
                if (start < end && arr[start] > arr[start + 1])
                    return start;

                start++;

                //check whether end is pivot
                if (start < end && arr[end] < arr[end - 1])
                    return end - 1;

                end--;
            }
            // left side is sorted, so pivot should be in right
            else if (arr[start] < arr[mid] || arr[start] == arr[mid] && arr[mid] > arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
}