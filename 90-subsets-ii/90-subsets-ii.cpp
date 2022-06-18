class Solution {
public:
    vector<vector<int>> ans;
    void helper(int ind, vector<int>& nums, vector<int>& temp) {
        ans.push_back(temp);
        for(int i=ind; i<nums.size(); i++) {
            if(i != ind and nums[i] == nums[i-1]) continue;
            
            temp.push_back(nums[i]);
            helper(i+1, nums, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // ans.clear();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        helper(0, nums, temp);
        return ans;
    }
};