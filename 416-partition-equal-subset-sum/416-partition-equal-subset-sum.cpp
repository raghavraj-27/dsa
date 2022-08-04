class Solution {
public:
    bool f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(target == 0) return true;
        if(ind == 0) {
            if(target == nums[ind]) return true;
            else return false;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool notTake = f(ind-1, target, nums, dp);
        bool take = false;
        if(nums[ind] <= target)
            take = f(ind-1, target-nums[ind], nums, dp);
        
        return dp[ind][target] = take | notTake;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // if sum is odd then not possible
        if(sum & 1) return false;
        
        int n = nums.size();
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        for(int ind=0; ind<n; ind++) {
            dp[ind][0] = true;
            if(ind == 0) {
                dp[0][target] = (nums[0] == target);
            }
        }
        
        for(int ind=1; ind<n; ind++) {
            for(int T=0; T<=target; T++) {
                bool notTake = dp[ind-1][T];
                bool take = false;
                if(nums[ind] <= T)
                    take = dp[ind-1][T-nums[ind]];

                dp[ind][T] = take | notTake;
            }
        }
        
        return dp[n-1][target];
    }
};