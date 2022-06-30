class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=1; i<nums.size(); i++) {
            ans += nums[i] - nums[0];
        }
        return ans;
    }
};
// 2 3 5 7 7 8 9
// 0 1 3 5 5 6 7
