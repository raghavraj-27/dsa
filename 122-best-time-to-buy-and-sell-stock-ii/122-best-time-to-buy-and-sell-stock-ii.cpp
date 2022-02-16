class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        int i=0, n = prices.size();
        
        while(i < n) {
            while(i<n-1 and prices[i]>prices[i+1]) i++;
            
            if(i == n-1) break;
            total_profit += prices[i+1] - prices[i];
            i++;
            while(i<n-1 and prices[i]>prices[i+1]) i++;
        }
        
        return total_profit;
    }
};