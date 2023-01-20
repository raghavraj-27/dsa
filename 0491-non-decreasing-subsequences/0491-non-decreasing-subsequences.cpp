class Solution {
public:
    set<vector<int>> ans;
    void f(int ind, vector<int>& nums, vector<int> seq) {
        if(seq.size() >= 2) ans.insert(seq);
        
        for(int i=ind; i<nums.size(); i++) {   
            // if(seq.size() == 0) seq.push_back(nums[i]);
            if(seq.back() <= nums[i]) {
                seq.push_back(nums[i]);
                f(i+1, nums, seq);
                seq.pop_back();
            } 
                // else {
            //     int in = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
            //     // if(in == seq.size()) {
            //     //     seq.push_back(nums[i]);
            //     //     f(i+1, nums, seq);
            //     //     seq.pop_back();
            //     // } else {
            //         int temp = seq[in];
            //         seq[in] = nums[i];
            //         f(i+1, nums, seq);
            //         seq[in] = temp;
            //         // seq.pop_back();
            //     // }
            // }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++) {
            vector<int> seq(1, nums[i]);
            f(i+1, nums, seq);
        }
        // f(1, nums, seq);
        
        vector<vector<int>> a(ans.begin(), ans.end());
        return a;
    }
};