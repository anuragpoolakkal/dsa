int Solution::maxProfit(const vector<int> &A) {
    if (A.size() == 0) return 0;
    
    int sell_price = 0;
    int profit = 0;
    
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] > sell_price) {
            sell_price = A[i];
        } else if (A[i] < sell_price) {
            profit = max(profit, sell_price - A[i]);
        }
    }
    return profit;
}
