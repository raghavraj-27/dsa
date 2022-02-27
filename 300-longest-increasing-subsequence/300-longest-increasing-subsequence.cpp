class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // DP Approach
        /*
        vector<int> dp(nums.size(), 0); 
        dp[0] = 1; 
        
        for(int i=1; i<nums.size(); i++) {
            int prev = INT_MIN; 
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i] and dp[j] > prev) {
                    dp[i] = dp[j]; 
                    prev = dp[j];
                }
            } 
            dp[i]++;
        }
        
        return *max_element(dp.begin(), dp.end());
        */
        
        vector<int> seq; 
        seq.push_back(nums[0]); 
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > seq.back()) 
                seq.push_back(nums[i]);
            else {
                int index = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[index] = nums[i];
            }
        }
        
        return seq.size();
    }
};