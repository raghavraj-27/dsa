class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> seq(1, nums[0]);
        
        for(int i=1; i<n; i++) {
            if(seq.back() < nums[i]) {
                seq.push_back(nums[i]);
            } else {
                int ind = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                // if(seq.size() >= ind) {
                    // seq[seq.size() - 1] = nums[i];
                // } else {
                    seq[ind] = nums[i];
                // }
            }
        }
        
        return seq.size();
    }
};