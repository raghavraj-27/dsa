class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int cnt = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) continue;
            
            int diff = nums[i-1] - nums[i];
            cnt += diff + 1;
            nums[i] = nums[i-1] + 1;            
        }
        return cnt;
    }
};