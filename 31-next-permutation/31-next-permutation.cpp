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
//         int ind2;
//         for(int i=n-1; i>=0; i--) {
//             if(nums[i] > nums[ind] and abs(nums[i] - nums[ind]) < diff) {
//                 ind2 = i;
//                 break;
//             }
//         }

//         swap(nums[ind], nums[ind2]);

        // After swaping, you can either sort the array after ind or you can reverse the array after ind
        // sorting will cause TC = O(n) + O(n) + O(n.log n) = O(n. log n)
        // reverse will cause TC = O(n) + O(n) + O(n) = O(n)
        // This is why revering is better approach here

        // sort(nums.begin()+ind+1, nums.end());
        // reverse(nums.begin()+ind+1, nums.end());
    }
};