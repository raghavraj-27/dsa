class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if(n < 3) return 0;
        if(n == 3) return nums[0] + nums[1] + nums[2];
        int closest = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<n-2; i++) {
            int left = i+1, right = n-1;
            
            while(left < right) {
                int currSum = nums[i] + nums[left] + nums[right];
                
                if(abs(target - currSum) < abs(target - closest)) {
                    closest = currSum;
                }
                
                if(currSum > target) right--;
                else left++;
            }
        }
        
        return closest;
    }
};