class Solution {
public:
    // Greedy Approach
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        if(nums[0] == 0) return false;
        
        int currdist = nums[0];
        int farthest = nums[0];
        bool ans = true;
        
        for(int i=1; i<nums.size()-1; i++) {
            if(i + nums[i] > farthest) {
                farthest = nums[i] + i;
            }
            
            if(i == currdist) {
                // ans++;
                currdist = farthest; 
                if(farthest < nums.size()-1 and nums[farthest] == 0) ans = false;
                else ans = true;
            }
        }
        
        return ans;
    }
};