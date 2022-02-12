class Solution {
public:
    int func(int i, vector<int>& nums, vector<int>& dp) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        int sum = nums[i]; 
        int element = nums[i];
        int nextInd = i+1;
        while(nextInd < nums.size() and element==nums[nextInd]) {
            sum+=nums[i];
            nextInd++;
        }
        while(nextInd < nums.size() and element+1==nums[nextInd]) {
            nextInd++;
        }
        
        int val1 = sum + func(nextInd, nums, dp);
        int val2 = func(i+1, nums, dp);
        
        return dp[i] = max(val1, val2);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size(); 
        sort(nums.begin(), nums.end());
        vector<int> dp(n, -1);
        return func(0, nums, dp);
    }
};