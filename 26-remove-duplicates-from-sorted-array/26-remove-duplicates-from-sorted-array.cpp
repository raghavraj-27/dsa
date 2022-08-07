class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0; 
        for(int j=1; j<nums.size();) {
            if(nums[i] == nums[j]) {
                j++;
            } else {
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        
        return i+1;
    }
};