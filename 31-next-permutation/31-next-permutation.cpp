class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(); 
        int ind = -1, diff = INT_MAX; 
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                ind = i; 
                break;
            }
        }

        if(ind == -1) {
            reverse(nums.begin(), nums.end()); 
            return;
        }
        int jnd = 0;
        for(int i=n-1; i>=0; i--) {
            if(nums[i] > nums[ind]) {
                jnd = i;
                break;
            }
        }
        swap(nums[ind], nums[jnd]);
        reverse(nums.begin()+ind+1, nums.end());
    }
};