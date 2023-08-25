class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxWealth = Integer.MIN_VALUE, wealth = 0;
        for (int[] row : accounts) {
            for (int col : row) {
                wealth += col;
            }
            maxWealth = Math.max(wealth, maxWealth);
            wealth = 0;
        }
        return maxWealth;
    }
}