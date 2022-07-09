class Solution {
public:
    // Optimized approach with TC : O(N log k) + O(log k)
    // SC : O(K)
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        multiset<int> st;
        
        dp[0] = nums[0];
        st.insert(dp[0]);
        
        for(int i=1; i<n; i++) {
            if(i > k) {
                st.erase(st.find(dp[i-k-1]));
            }
            dp[i] = *st.rbegin() + nums[i];
            st.insert(dp[i]);
        }
        
        return dp[n-1];
    }
};