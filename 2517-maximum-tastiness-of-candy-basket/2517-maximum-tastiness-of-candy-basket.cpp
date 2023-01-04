class Solution {
public:
    bool check(vector<int>& prices, int k, int limit, int & mini) {
        vector<int> v(1, prices[0]);
        
        for(int i=1; i<prices.size(); i++) {
            if(abs(v.back() - prices[i]) >= limit) {
                mini = min(mini, prices[i] - v.back());
                v.push_back(prices[i]);
            }
        }
        
        if(v.size() < k) return false;
        return true;
    }
    int maximumTastiness(vector<int>& prices, int k) {
        int n = prices.size();
        sort(prices.begin(), prices.end());
        int low = 1, high = prices[n-1]-prices[0];
        int res = 0;
        
        while(low <= high) {
            int mid = (low + high) >> 1;
            
            int mini = INT_MAX;
            if(check(prices, k, mid, mini)) {
                res = mini;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return res;
    }
};