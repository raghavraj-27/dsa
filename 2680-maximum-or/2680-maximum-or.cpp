class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n), suffix(n);
        
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] | nums[i];
            suffix[n-i-1] = suffix[n-i] | nums[n-i-1];
        }
        
        long long ans = 0;
        for(int i=0; i<n; i++) {
            long long left, mid, right;
            if(i == 0) left = 0;
            else left = prefix[i-1];
            
            if(i == n-1) right = 0;
            else right = suffix[i+1];
            
            mid = (long long) nums[i] << k;
            
            ans = max(ans, left | mid | right);
        }
        
        return ans;
    }
};