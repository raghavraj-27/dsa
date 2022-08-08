class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        seq.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++) {
            if(seq.back() < nums[i]) {
                seq.push_back(nums[i]);
            } else {
                int ind = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                if(ind < seq.size()) {
                    seq[ind] = nums[i];
                } else {
                    seq[seq.size()-1] = nums[i];
                }
            }
        }
        
        return seq.size();
    }
};