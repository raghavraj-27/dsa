class Solution {
public:
    void createPermutations(vector<int>& nums, map<int, bool> freq, vector<int> v, 
                           vector<vector<int>>& ans) {
        if(v.size() >= nums.size()) {
            ans.push_back(v);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(freq[nums[i]] == false) {
                freq[nums[i]] = true;
                v.push_back(nums[i]);
                createPermutations(nums, freq, v, ans);
                v.pop_back();
                freq[nums[i]] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        map<int, bool> freq;
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]] = false;
        }
        
        vector<int> v;
        vector<vector<int>> ans;
        createPermutations(nums, freq, v, ans);
        return ans;
    }
};