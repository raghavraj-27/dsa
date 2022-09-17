class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++) {
            if(sub.back() < nums[i]) {
                sub.push_back(nums[i]);
            } else {
                int ind = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
                if(ind < sub.size()) {
                    sub[ind] = nums[i];
                } 
                // else {
                    
                // }
            }
        }
        
        return sub.size();
    }
};