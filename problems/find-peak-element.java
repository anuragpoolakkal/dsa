// same answer to peak-index-in-a-mountain-array (easy) qn

class Solution {
    public int findPeakElement(int[] arr) {
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
}