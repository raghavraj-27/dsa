class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_min_sum = 0, curr_max_sum = 0;
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        int tot_sum = 0;
        
        for(int i=0; i<nums.size(); i++) 
        {
            curr_max_sum = max(curr_max_sum + nums[i], nums[i]);
            max_sum = max(curr_max_sum, max_sum);
            
            curr_min_sum = min(curr_min_sum + nums[i], nums[i]);
            min_sum = min(curr_min_sum, min_sum);
            
            tot_sum += nums[i];
        }
        
        if(tot_sum == min_sum) return max_sum;
        
        return max(max_sum, tot_sum - min_sum);
    }
}; 