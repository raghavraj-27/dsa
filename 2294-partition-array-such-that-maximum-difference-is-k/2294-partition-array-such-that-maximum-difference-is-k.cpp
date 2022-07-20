class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0, ans =0; 
        while(i < nums.size()) {
            int start = i;
            while(i < nums.size() and nums[i]-nums[start] <= k) {
                i++;
            }
            ans++;
        }
        return ans;
    }
};

// 1 2 3 5 6
    
// 3 6 1 2 5