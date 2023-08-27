class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int start = 0, end = letters.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target < letters[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        // System.gc(); // This single line of code reduced memory consumption from 44MB (beats 53% of users) to 41MB (beats 99.81% of users)
        return letters[start % letters.length];
    }
}