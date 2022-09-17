class Solution {
public:
    int lb(vector<int>& sub, int x) {
        int n = sub.size();
        int low = 0, high = n;
        
        while(low < high) {
            int mid = (low + high) >> 1;
            
            if(x <= sub[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        if(low < n and sub[low] < x) {
            low++;
        }
        
        return low;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++) {
            if(sub.back() < nums[i]) {
                sub.push_back(nums[i]);
            } else {
                int ind = lb(sub, nums[i]);
                if(ind < sub.size()) {
                    sub[ind] = nums[i];
                } 
            }
        }
        
        return sub.size();
    }
};