class Solution {
public:
    int bs(int start, int end, vector<int>& nums, int target) {
        if(start > end) return -1;
        
        int mid = (start + end)>>1;
        if(nums[mid] > target)
            return bs(start, mid-1, nums, target);
        if(nums[mid] < target)
            return bs(mid+1, end, nums, target);
        
        return mid;
    }
    int search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return bs(0, nums.size()-1, nums, target);
    }
};