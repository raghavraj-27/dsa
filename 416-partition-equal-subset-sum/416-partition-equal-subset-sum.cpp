class Solution {
public:
    bool f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(target == 0) return true;
        if(ind < 0) return false;
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool notTake = f(ind-1, target, nums, dp);
        bool take = false;
        if(nums[ind] <= target)
            take = f(ind-1, target-nums[ind], nums, dp);
        
        return dp[ind][target] = take | notTake;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum/2 + 1, -1));
        return f(nums.size()-1, sum/2, nums, dp);
    }
};