class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
//         vector<int> v; 
//         v.push_back(nums[0]);
        
//         for(int i=1; i<nums.size(); i++) {
//             if(v.back() < nums[i]) {
//                 nums.push_back(nums[i]);
//             } else {
//                 int ind = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
//                 v[ind] = nums[i];
//             }
//         }
        
//         return v.size();
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};