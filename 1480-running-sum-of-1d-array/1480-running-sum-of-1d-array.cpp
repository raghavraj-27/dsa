class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        for(int I=1; I<nums.size() ; I++) {
            ans[I] = ans[I-1] + nums[I];
        }
        return ans;
    }
};