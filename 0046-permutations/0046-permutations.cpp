class Solution {
public:
    vector<int> v;
    vector<vector<int>> ans;
    void createPermutation(vector<int>& nums, map<int, bool>& vis) {
        if(v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(vis[nums[i]] == false) {
                vis[nums[i]] = true;
                v.push_back(nums[i]);
                createPermutation(nums, vis);
                v.pop_back();
                vis[nums[i]] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        map<int, bool> vis;
        for(int i=0; i<nums.size(); i++) {
            vis[nums[i]] = false;
        }
        
        createPermutation(nums, vis);
        
        return ans;
    }
};