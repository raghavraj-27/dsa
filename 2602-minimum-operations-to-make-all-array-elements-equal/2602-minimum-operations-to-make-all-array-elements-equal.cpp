class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> presum(n);
        
        presum[0] = nums[0];
        for(int i=1; i<n; i++) {
            presum[i] = (long long)nums[i] + presum[i-1];
        }
        
        vector<long long> ans;
        
        for(int q: queries) {
            int ind = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long cnt = 0;
            if(ind > 0)
                cnt += (long long)q*(ind) - presum[ind-1];
            if(ind < n) { 
                if(ind == 0 and nums[ind] == q) {
                    cnt += presum[n-1] - presum[ind] - (long long)q*(n-ind-1); 
                } else if(ind == 0) {
                    cnt += presum[n-1] - (long long)q*n; 
                } else {
                    cnt += presum[n-1] - presum[ind-1] - (long long)q*(n-ind); 
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


// 1 3 6 8