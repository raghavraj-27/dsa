class Solution {
public:
    bool isPossible(int lim, vector<int>& nums, int m) {
        int total = 0, sub_arrays = 1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > lim) return false;
            if(total + nums[i] <= lim) {
                total += nums[i];
            } else {
                sub_arrays++;
                total = nums[i];
            }
        }
        return (sub_arrays <= m);
    }
    int splitArray(vector<int>& nums, int m) {
        int low = 0, high = 1e9;
        int ans;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(isPossible(mid, nums, m)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};