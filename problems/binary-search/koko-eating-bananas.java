class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int start = 1, end = 0;

        for (int pile: piles)
            end = Math.max(pile, end);

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (isPossible(piles, h, mid))
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }


    static boolean isPossible(int[] piles, int h, int k) {
        int hoursNeeded = 0;

        for (int pile : piles)
            hoursNeeded += Math.ceil((double)pile / k);

        return hoursNeeded <= h;
    }
}