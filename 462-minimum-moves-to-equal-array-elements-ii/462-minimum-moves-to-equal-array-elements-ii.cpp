class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2;
        int ans = 0;
        
        for(int i=0; i<mid; i++) {
            ans += nums[mid] - nums[i];
        }
        
        for(int i=mid+1; i<nums.size(); i++) {
            ans += nums[i] - nums[mid];
        }
        
        return ans;
    }
};

// 1, 2, 3

// 1, 2, 9, 10