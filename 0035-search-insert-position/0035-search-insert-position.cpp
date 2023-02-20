class Solution {
public:
    int ans;
    
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int ans = nums.size();
        
        while(low <= high) {
            int mid = (low + high) >> 1;
            
            if(nums[mid] == target) {
                ans = mid;
                break;
            }
            
            if(nums[mid] > target) {
                ans = mid;
                high = mid-1;
            }
            if(nums[mid] < target) {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, target);
        // return ans;
    }
};