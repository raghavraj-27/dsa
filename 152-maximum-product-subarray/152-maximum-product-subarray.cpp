class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = 1, r = 1, n = nums.size(), ans;
        for(int i=0; i<n; i++) {
            l = ((l==0) ? 1 : l) * nums[i];
            r = ((r==0) ? 1 : r) * nums[n-i-1];
            ans = max(ans, max(l, r));
        }
        
        return ans;
    }
};