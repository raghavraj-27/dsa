class Solution {
public:
    // Greedy
    int jump(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 1) return 0;
        
        int currdist = nums[0];
        int farthest = nums[0];
        int jumps = 1;
        
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] + i > farthest) {
                farthest = nums[i] + i;
            }
            
            if(i == currdist) {
                currdist = farthest; 
                jumps++;
            }
        }
        
        return jumps;
    }
};