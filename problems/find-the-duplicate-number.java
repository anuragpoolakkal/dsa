import java.util.Arrays;

class Solution {
    public int findDuplicate(int[] nums) {
        int index = 0;

        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == nums[i+1]) {
                index = nums[i];
                break;
            }
        }
        // System.gc();
        return index;
    }
}