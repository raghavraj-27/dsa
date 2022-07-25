class Solution {
public:
    int search(int low, int high, vector<int>& nums, int target, vector<int>& pos) {
        if(low > high) return -1;
        
        int mid = (low + high) >> 1;
        if(nums[mid] < target) {
            return search(mid+1, high, nums, target, pos);
        }
        if(nums[mid] > target) {
            return search(low, mid-1, nums, target, pos);
        }
        
        int left = search(low, mid-1, nums, target, pos);
        int right = search(mid+1, high, nums, target, pos);
        pos[0] = min({mid, left==-1 ? INT_MAX : left, pos[0]});
        pos[1] = max({mid, pos[1], right});
        
        return mid;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos(2);
        pos[0] = INT_MAX, pos[1] = INT_MIN;
        
        search(0, nums.size()-1, nums, target, pos);
        if(pos[0] == INT_MAX or pos[1] == INT_MIN) return {-1, -1};
        
        return pos;
    }
};