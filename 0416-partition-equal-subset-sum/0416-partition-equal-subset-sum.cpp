class Solution {
public:
//     bool f(int i, vector<int>& nums, int target, vector<vector<int>>& dp) {
//         if(target == 0) return true;
//         if(i < 0) return 0;
        
//         if(dp[i][target] != -1) return dp[i][target];
//         bool take = false;
//         if(nums[i] <= target) {
//             take = f(i-1, nums, target-nums[i], dp); 
//         }
//         bool notTake = f(i-1, nums, target, dp);
//         return dp[i][target] = take or notTake;
//     }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum & 1) return false;
        int n = nums.size(), target = sum/2;
        
        vector<vector<int>> dp(n, vector<int> (target + 1, 0));
        
        for(int i=0; i<n; i++) {
            dp[i][0] = true;
            if(i == 0) dp[0][target] = (nums[0] == target);
        }
        
        for(int i=1; i<n; i++) {
            for(int t=0; t<=target; t++) {
                bool take = false;
                if(nums[i] <= t) {
                    take = dp[i-1][t-nums[i]]; 
                }
                bool notTake = dp[i-1][t];
                dp[i][t] = take or notTake;
            }
        }
        return dp[n-1][target];
        // return f(nums.size()-1, nums, sum / 2, dp);
    }
};