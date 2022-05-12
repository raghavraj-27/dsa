class Solution {
public:
    void createPermute(int ind, vector<int>& nums, set<vector<int>>& ans) {
        if(ind >= nums.size()) {
            ans.insert(nums);
            return;
        }
        
        for(int i=ind; i<nums.size(); i++) {
            swap(nums[ind], nums[i]);
            createPermute(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans_set;
        createPermute(0, nums, ans_set);
        vector<vector<int>> ans;
        for(auto v : ans_set) {
            ans.push_back(v);
        }
        return ans;
    }
};