class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> inc(nums.size(), 1);
        vector<int> dec(nums.size(), 1);
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] > nums[i]) {
                dec[i] = inc[i-1] + 1;
                inc[i] = inc[i-1];
            } else if(nums[i-1] < nums[i]) {
                inc[i] = dec[i-1] + 1;
                dec[i] = dec[i-1];
            } else {
                inc[i] = inc[i-1];
                dec[i] = dec[i-1];
            }
        }
        
        return max(inc[nums.size()-1], dec[nums.size()-1]);
    }
};