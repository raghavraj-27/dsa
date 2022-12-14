class Solution {
public:
    bool f(int i, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if(target == 0) return true;
        if(i < 0) return 0;
        
        if(dp[i][target] != -1) return dp[i][target];
        bool take = false;
        if(nums[i] <= target) {
            take = f(i-1, nums, target-nums[i], dp); 
        }
        bool notTake = f(i-1, nums, target, dp);
        return dp[i][target] = take or notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum & 1) return false;
        vector<vector<int>> dp(nums.size(), vector<int> (sum/2 + 1, -1));
        return f(nums.size()-1, nums, sum / 2, dp);
    }
};