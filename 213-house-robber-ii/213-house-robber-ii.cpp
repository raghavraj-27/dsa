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
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        int sum = 0;
        for(auto val : nums) {
            sum += val;
        }
        
        if(sum == 0) {
            return sum;
        }
        
        vector<vector<int>> dp1(nums.size(), vector<int> (sum, -1)), dp2(nums.size(), vector<int> (sum, -1));
        vector<int> v1, v2;
        for(int i=0; i<nums.size()-1; i++) v1.push_back(nums[i]);
        for(int i=1; i<nums.size(); i++) v2.push_back(nums[i]);
        
        return max(solve(0, v1, 0, dp1), solve(0, v2, 0, dp2));
    }
};