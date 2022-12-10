class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void f(int i, vector<int>& nums) {
        ans.push_back(v);
        for(int ind=i; ind<nums.size(); ind++) {
            if(ind != i and nums[ind] == nums[ind-1]) continue;
            v.push_back(nums[ind]);
            f(ind+1, nums);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.clear();
        v.clear();
        f(0, nums);
        
        return ans;
    }
};