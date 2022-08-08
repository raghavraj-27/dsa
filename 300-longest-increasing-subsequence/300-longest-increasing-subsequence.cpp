class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // i -> max len of longest increasing subsequence
        // i=0 -> 1
        // i=1, if(nums[i-1] < nums[i]) => 2
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                } 
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};