class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = (1<<nums.size());
        
        for(int i=0; i<n; i++) {
            int num = i;
            vector<int> subset;
            for(int j=0; j<nums.size(); j++) {
                if(num & (1<<j)) {
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }
        
        return ans;
    }
};