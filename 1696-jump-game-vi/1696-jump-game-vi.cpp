class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), val = -1*1e9;
        vector<int> dp(n, INT_MIN);
        multiset<int> st; 
        
        dp[0] = nums[0];
        st.insert(dp[0]);
        
        for(int i=1; i < n; i++) {
            if(i > k) {
                st.erase(st.find(dp[i-k-1]));
            }
            dp[i] = nums[i] + *st.rbegin();
            st.insert(dp[i]);
        }
        
        return dp.back();
    }
};