class Solution {
    public int arrangeCoins(int n) {
        long low = 0, high = n, mid = -1, k = -1;

        while (low <= high) {
            mid = low + (high - low) / 2;
            k = mid * (mid+1) / 2;

            if (k == n)
                return (int)mid;
            else if (k > n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return (int)high;
    }
}