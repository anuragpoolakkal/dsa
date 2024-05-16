class Solution {
    public int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int start = 1, end = x;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid*mid > x)
                end = mid - 1;
            else if (mid*mid < x)
                start = mid + 1;
            else
                return mid;
        }
        return Math.round(end);
    }
}