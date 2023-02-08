class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        int currDist = nums[0], farthest = nums[0], jump = 1;
        
        for(int i=0; i<n-1; i++) {
            if(nums[i] + i > farthest) {
                farthest = nums[i] + i;
            }
            
            if(i == currDist) {
                jump++;
                currDist = farthest;
            }
        }
        
        return jump;
    }
};