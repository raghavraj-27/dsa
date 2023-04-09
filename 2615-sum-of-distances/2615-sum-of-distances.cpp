class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long, long long> cnt_l, cnt_r, sum_l, sum_r;
        vector<long long> ans(nums.size(), 0);
        
        for(int i=0; i<nums.size(); i++) {
            ans[i] = cnt_l[nums[i]] * i - sum_l[nums[i]];
            sum_l[nums[i]] += i;
            cnt_l[nums[i]]++;
        }
        
        for(int i=nums.size()-1; i>=0; i--) {
            ans[i] += sum_r[nums[i]] - cnt_r[nums[i]] * i;
            sum_r[nums[i]] += i;
            cnt_r[nums[i]]++;
        }
        
        return ans;
    }
};