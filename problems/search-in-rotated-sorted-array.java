class Solution {
    public int search(int[] nums, int target) {
        int pivot = findPivot(nums);

        if (pivot == -1)
            return binarySearch(nums, target, 0, nums.length - 1);

        if (nums[pivot] == target)
            return pivot;
            
        if (target >= nums[0])
            return binarySearch(nums, target, 0, pivot - 1);

        return binarySearch(nums,target,pivot + 1, nums.length - 1);
    }

    static int binarySearch(int[] arr, int target, int start, int end) {
        while(start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > target) {
                end = mid - 1;
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
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
                if (arr[start] > arr[start + 1])
                    return start;

                start++;

                //check whether end is pivot
                if (arr[end] < arr[end - 1])
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