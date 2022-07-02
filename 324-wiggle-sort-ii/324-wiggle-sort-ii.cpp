class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int mid = (nums.size() + 1) / 2;
        sort(nums.begin(), nums.end());
        vector<int> temp = nums;
        
        for(int i=1, j=nums.size()-1; i<nums.size() and j>=mid; i=i+2, j--) {
            nums[i] = temp[j];
        }
        
        for(int i=0, j=mid-1; i<nums.size(); i=i+2, j--) {
            nums[i] = temp[j];
        }
    }
};

// 1 5 1 1 6 4
//     after sorting
// 1 1 1 4 5 6
// 0 1 2 3 4 5    
