class Solution {
public:
    int solve(int ind, vector<int> & nums, int money, vector<vector<int>> & dp) 
    {
        if(ind>=nums.size()) {
            return money;
        }
        
        if(dp[ind][money] != -1) {
            return dp[ind][money];
        }
        
        int option1 = solve(ind+2, nums, money + nums[ind], dp);
        int option2 = solve(ind+1, nums, money, dp);
        
        return dp[ind][money] = max(option1, option2);
    }
    
    int rob(vector<int>& nums) {
        int sum = 0;
        for(auto val : nums) {
            sum += val;
        }
        
        if(sum == 0) {
            return sum;
        }
        
        vector<vector<int>> dp(nums.size(), vector<int> (sum, -1));
        return solve(0, nums, 0, dp);
    }
};