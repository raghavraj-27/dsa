class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(); 
        int cnt = 0;
        
        for(int i=1; i<n; i++) {
            if(nums[i-1] > nums[i]) {
                cnt++;
                if(cnt > 1) return false;
                
                // if(i > 1 and i < n-2 and nums[i-1]-nums[i] <= 1 and nums[i+2]-nums[i+1] <=1)
                //     return false;
                
                if(i>1 and i<n-1 and nums[i-2] > nums[i] and nums[i+1] < nums[i-1])
                    return false;
            }
        }
        
        return true;
    }
};