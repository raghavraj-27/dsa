class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for(int i = 0; i < size(nums); i++) if(abs(nums[i] - i) > 1) return false;
	    return true;
    }
};