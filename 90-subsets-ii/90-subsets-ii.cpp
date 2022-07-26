class Solution {
public:
    void f(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);
        
        for(int i = idx; i<nums.size(); i++) {
            if(i>idx and nums[i-1] == nums[i]) continue;
            temp.push_back(nums[i]);
            f(i+1, nums, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
        f(0, nums, temp, ans);
        return ans;
    }
};